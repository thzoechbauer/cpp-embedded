/******************************************************//**
* \file     crt1.h
* \brief    Call all initializing ctors.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     30-September-2015
**********************************************************/

typedef void(*function_type)();

extern function_type _ctors_end[];
extern function_type _ctors_begin[];

void crt_init_ctors()
{
    for (function_type* pf = _ctors_begin; pf != _ctors_end; pf++)
    {
        (*pf)();
    }
}
