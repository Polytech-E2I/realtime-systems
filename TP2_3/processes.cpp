#include "processes.h"



/* file containing the functions implementing the processes (also called tasks) */

bool proc1 (Task* task, void* p)
{
    static int count = 0;

    IntHandler* par=(IntHandler*)p;

    cout << task->m_name << " "<< par->i << endl;

    count += 1;
    if(count == 5)
    {
        static Proc4ArgumentHandler par5(5, 55, "cinq");
        task->m_os->m_cpu->s_cpus[1]->AddInitialTask(proc5, (void*) &par5, "cpu2 - proc5");
    }

    CONSUME(par->i * 100);

    return true;
}

bool proc2 (Task* task,void* p)
{
    IntHandler* par=(IntHandler*)p;

    cout << task->m_name << " "<< par->i << endl;

    CONSUME(par->i * 100);
    return true;
}

bool proc3 (Task* task,void* p)
{
    IntHandler* par=(IntHandler*)p;

    cout << task->m_name << " "<< par->i << endl;

    CONSUME(par->i * 100);

    return true;
}


bool proc4 (Task* task,void* p)
{
    Proc4ArgumentHandler* par = (Proc4ArgumentHandler*) p;

    cout << par->_a + par->_b << " " << par->_s;

    return true;
}

bool proc5 (Task* task,void* p)
{
    Proc4ArgumentHandler* par = (Proc4ArgumentHandler*) p;

    cout << par->_a + par->_b << " " << par->_s;
    //Do not restart the process
    return false;
}

