/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:07:34 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/08 23:21:35 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../iterator/iteratorTrait.hpp"

namespace ft
{

    template <class Iter>
    class reverseIterator
    {
    public:
        typedef typename ft::iteratorTrait::reference reference;
        typedef typename ft::iteratorTrait::difference_type difference_type;
        typedef typename ft::iteratorTrait::value_type value_type;
        typedef typename ft::iteratorTrait::pointer pointer;
        // typedef ft::iteratorTrait::iterator_category iterator_category;
        reverseIterator() : it(0) {}
        explicit reverseIterator(pointer it) : it(it) {}
        ~reverseIterator(){};
        reference operator*() const
        {
            return (*this->it);
        }

    private:
        pointer it;
    };

}
