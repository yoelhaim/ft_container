/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_integral.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:05:43 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/08 22:05:45 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft
{
    template <bool B, class T = void>
    struct enable_if
    {
    };

    template <class T>
    struct enable_if<true, T>
    {
        typedef T type;
    };

    // is integral type

    template <class T>
    struct is_integral
    {
        static const bool value = false;
    };


    template <>
    struct is_integral<bool>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<char>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<char16_t>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<char32_t>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<wchar_t>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<signed char>
    {
    };
    template <>
    struct is_integral<short int>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<int>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<long int>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<unsigned char>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<long long int>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<unsigned short int>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<unsigned int>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<unsigned long int>
    {
        static const bool type = true;
    };
    template <>
    struct is_integral<unsigned long long int>
    {
        static const bool type = true;
    };

}