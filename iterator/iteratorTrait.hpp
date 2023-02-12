/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTrait.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:59:42 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/10 20:36:12 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <iterator>
#include <cstddef>
#include "iterator.hpp"
namespace ft
{
    template <typename T>
    class iteratorTrait
    {
    public:
        typedef typename T::iterator_category iterator_category;
        typedef  T value_type;
        typedef typename T::reference reference;
        typedef typename T::difference_type difference_type;
        typedef typename T::pointer pointer;
    };

} // namespace ft
