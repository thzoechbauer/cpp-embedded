/******************************************************//**
* \file     crt1.cpp
* \brief    Call all ctor initializations.
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

#include <algorithm>
#include <iterator>

struct ctor_type
{
    using function_type = void(*)();
    using const_iterator = const function_type*;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;
};

extern "C"
{
    extern ctor_type::function_type _ctors_begin[];
    extern ctor_type::function_type _ctors_end[];
}

namespace crt
{
    void init_ctors();
}

void crt::init_ctors()
{
    std::for_each(ctor_type::const_iterator(_ctors_begin),
        ctor_type::const_iterator(_ctors_end),
        [](const ctor_type::function_type pf)
        {
            pf();
        }
    );

}
