/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 22:07:34 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/10 21:08:46 by pro              ###   ########.fr       */
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
        typedef Iter iterator_type;
        typedef typename ft::iteratorTrait<Iter>::reference reference;
        typedef typename ft::iteratorTrait<Iter>::difference_type difference_type;
        typedef typename ft::iteratorTrait<Iter>::value_type value_type;
        typedef typename ft::iteratorTrait<Iter>::pointer pointer;
        typedef typename ft::iteratorTrait<Iter>::iterator_category iterator_category;
        reverseIterator() : it(0) {}
        explicit reverseIterator(pointer it) : it(it) {}
        ~reverseIterator(){};

        iterator_type base() const{
            return (this->it);
        }
        reference operator*() const
        {
            iterator_type tmp(base());
            return (*(tmp));
        }

    private:
        pointer it;
    };

}
