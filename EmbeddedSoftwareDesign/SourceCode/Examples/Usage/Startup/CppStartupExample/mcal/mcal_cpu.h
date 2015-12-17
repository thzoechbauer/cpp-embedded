/******************************************************//**
* \file     mcal_cpu.h
* \brief    MCAL CPU header.
* \author   Thomas Zöchbauer
* \version  V1.0
* \date     23-September-2015
*
*           This file is based on Christopher Kormanyos
*           and modified by Thomas Zöchbauer (2015).
**********************************************************/


///////////////////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2007 - 2013.
//  Distributed under the Boost Software License,
//  Version 1.0. (See accompanying file LICENSE_1_0.txt
//  or copy at http://www.boost.org/LICENSE_1_0.txt)
//
//  Modified at 23-September-2015 by Thomas Zöchbauer.

#ifndef INCLUDE_MCAL_CPU_H
#define INCLUDE_MCAL_CPU_H

#include <cstdint>

namespace mcal
{
    namespace cpu
    {
        inline void init() { }
        inline void nop() { asm volatile("nop"); }
    }
}

#endif // INCLUDE_MCAL_CPU_H
