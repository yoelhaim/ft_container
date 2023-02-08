/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:22:51 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/08 13:56:52 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

namespace ft
{
    template <class T>
    class _Iterator
    {
    public:
        typedef T *pointer;
        typedef T &reference;
        typedef std::random_access_iterator_tag random_access_iterator;
        typedef std::ptrdiff_t difference_type;
        _Iterator() : _p(NULL) {}
        _Iterator(pointer _p) : _p(_p) {}
        ~_Iterator() {}

        // operator

        reference operator*() const
        {
            return (*this->_p);
        }
        // Subscript operator
        reference operator[](difference_type n) const { return *(*this + n); }

        // Member access operator
        pointer operator->() const { return _p; }
        // post-increment operator
        _Iterator operator++(int)
        {
            _Iterator tmp(*this);
            this->_p++;
            return (tmp);
        }
        // Pre-increment operator
        _Iterator &operator++()
        {
            this->_p++;
            return (*this);
        }
        _Iterator &operator=(const _Iterator &rhs)
        {
            if (this != &rhs)
                this->_p = rhs._p;
            return *this;
        }
        // post-decrement operator
        _Iterator operator--(int)
        {
            _Iterator tmp(*this);
            this->_p--;
            return (tmp);
        }
        // Pre-decrement operator
        _Iterator &operator--()
        {
            this->_p--;
            return (*this);
        }

        bool operator<(const _Iterator &ps) const
        {
            return (this->_p < ps._p);
        }

        _Iterator operator+(difference_type n) const
        {
            return _p + n;
        }

        _Iterator operator-(difference_type n) const
        {
            return _Iterator(_p - n);
        }
        difference_type operator-(const _Iterator &rhs) const
        {
            return (this->_p - rhs._p);
        }
        difference_type operator+(const _Iterator &rhs) const
        {
            return (this->_p + rhs._p);
        }

        // Equal to operator
        bool operator==(const _Iterator &other) const
        {
            return _p == other._p;
        }
        bool operator>=(const _Iterator &other)
        {
            return _p >= other._p;
        }
        bool operator<=(const _Iterator &other)
        {
            return _p <= other._p;
        }

        bool operator!=(const _Iterator &other) const
        {
            return (this->_p != other._p);
        }

        _Iterator &operator+=(difference_type n)
        {
            this->_p + n;
            return (*this);
        }
        _Iterator &operator-=(difference_type n)
        {
            this->_p - n;
            return (*this);
        }

        // Greater than operator
        bool operator>(const _Iterator &other) const
        {
            return (other < *this);
        }

    private:
        pointer _p;
    };
} // namespace ft
