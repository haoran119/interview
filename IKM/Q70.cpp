//
//  main.cpp
//  LeetCode
//
//  Created by Hao on 2017/3/16.
//  Copyright © 2017年 Hao. All rights reserved.
//
#include <iostream>
#include <complex>

/*
template< class T >
struct is_complex_or_fp< std::complex< T > > std::is_floating_point< T > { }; // Explicit specialization of non-template struct 'is_complex_or_fp'
*/


template< class T >
struct is_complex_or_fp : std::is_floating_point< T > { static constexpr bool value{true}; };


/*
template< class T >
struct is_complex_or_fp : std::is_floating_point< T > { };

template< class T >
struct is_complex_or_fp< T > : std::is_floating_point< std::complex< T > > { }; // Class template partial specialization does not specialize any template argument; to define the primary template, remove the template argument list
 */


template< class T >
struct is_complex_or_fp : std::is_floating_point< T > { };

template< class T >
struct is_complex_or_fp< std::complex< T > > : std::is_floating_point< T > { };


/*
template< class T >
struct is_complex_or_fp< T > : std::is_floating_point< std::complex< T > > { }; // Explicit specialization of non-template struct 'is_complex_or_fp'
*/

int main ()
{
    return 0;
}
