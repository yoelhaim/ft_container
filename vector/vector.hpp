/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:25:24 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/08 20:09:15 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <memory>
#include <exception>
#include "../iterator/iterator.hpp"
#include "../utils/is_integral.hpp"
using namespace std;

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef Alloc allocator_type;
        typedef T value_type;
        typedef size_t size_type;
        typedef ft::_Iterator<value_type> iterator;
        typedef ft::_Iterator<value_type> const_iterator;

        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;

        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef typename allocator_type::difference_type difference_type;

        // start Member functions
        explicit vector(const allocator_type &alloc = allocator_type()) : allocator_data(alloc)
        {
            cout << "default constractur\n";
            sizeOfContainer = 0;
            capacityOfContainer = 0;
        }
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            sizeOfContainer = n;
            capacityOfContainer = n * 2;
            // this->reserve(n);
            this->allocator_data = alloc;
            this->container = allocator_data.allocate(capacityOfContainer);
            for (size_type i = 0; i < n; i++)
                this->allocator_data.construct(this->container + i, val);
        }
        template <typename InputIterator>
        vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0) : allocator_data(alloc)
        {
            this->sizeOfContainer = last - first;
            cout << this->sizeOfContainer << endl;
            int i = 0;
            this->capacityOfContainer = last - first;
            this->container = this->allocator_data.allocate(this->capacity());
            while (first != (last))
            {
                this->allocator_data.construct(this->container + i, *first);
                i++;
                first++;
            }
        }

        ~vector() {}
        vector &operator=(const vector &x)
        {
            if (this->size())
                for (size_type i = 0; i < x.size(); i++)
                    allocator_data.destroy(&this->container[i]);
            allocator_data.deallocate(x.container, x.sizeOfContainer);
            size_type nb = x.size();
            this->allocator_data = x.allocator_data;
            this->sizeOfContainer = nb;
            this->capacityOfContainer = x.capacity();
            this->container = allocator_data.allocate(x.capacity());
            for (size_type i = 0; i < nb; i++)
                this->container[i] = x.container[i];
            return *this;
        }
        // copy contructor
        vector(const vector &x)
        {
            *this = x;
        }
        // end  Member functions
        //  start  Modifiers
        //  start itertaor

        iterator begin()
        {
            return (container);
        }

        const_iterator begin() const
        {
            return (container);
        }
        iterator end()
        {
            return (this->container + size());
        }
        const_iterator end() const
        {
        }
        // end  iterator
        template <class InputIterator>  void assign (InputIterator first, InputIterator last)
        {
            sizeOfContainer = 0;
            while (first != last)push_back(*first++);
        }
        void assign(size_type n, const value_type &val)
        {
            for (size_type i = 0; i < this->size(); i++)this->allocator_data.destroy(this->container + i);
            
            allocator_data.deallocate(container, this->capacity());
            sizeOfContainer = 0;
            for (size_type i = 0; i < n; i++)
                this->push_back(val);
        }
        void push_back(const value_type &value)
        {
            if (capacity() == 0)
            {
                container = allocator_data.allocate(1);
                container[sizeOfContainer++] = value;
                capacityOfContainer++;
                return;
            }
            if (size() == capacity())
            {
                value_type *tmp = container;
                // reserve(capacity() * 2);
                capacityOfContainer = capacityOfContainer * 2;
                tmp = allocator_data.allocate(capacity() * 2);
                size_type i = -1;
                while (++i <= size())
                    this->allocator_data.construct(tmp + i, container[i]);

                allocator_data.deallocate(container, capacity());
                tmp[i - 1] = value;
                container = tmp;
                sizeOfContainer++;
            }
            else
                container[sizeOfContainer++] = value;
        }
        void pop_back()
        {
            allocator_data.destroy(&container[size() - 1]);
            sizeOfContainer--;
        }
        iterator insert(iterator position, const value_type &val)
        {
            pointer tmp = allocator_data.allocate(this->capacity() + 1);

            iterator it = this->begin();
            iterator pos = position;
            size_type i = 0;
            while (it < pos)
            {
                this->allocator_data.construct(tmp + i, *it);
                it++;
                i++;
            }
            size_type positionOfIter = i;
            this->allocator_data.construct(tmp + i, val);
            i++;
            while (it <= this->end())
            {
                  this->allocator_data.construct(tmp + i, *it);
                 it++;
                 i++;
            }
            for (size_type i = 0; i < this->size(); i++)
                 allocator_data.destroy(this->container + i);
            allocator_data.deallocate(container, capacity());
            
            this->container = tmp;
            this->sizeOfContainer++;
            return (this->begin() + positionOfIter);
        }
        void insert(iterator position, size_type n, const value_type &val)
        {
            pointer tmp = allocator_data.allocate(capacity() + n);

            iterator it = this->begin();
            iterator pos = position;
            size_type i = 0;
            while (it < pos)
            {
                this->allocator_data.construct(tmp + i, *it);
                it++;
                i++;
            }
            size_type tmpn = n;
            while (tmpn > 0)
            {
                tmp[i] = val;
               this->allocator_data.construct(tmp + i, val);
               tmpn--;
               i++;
            }
            while (it <= this->end())
            {
                tmp[i] = container[i];
                  this->allocator_data.construct(tmp + i, *it);
                 it++;
                 i++;
            }
            
            for (size_type i = 0; i < this->size(); i++)
                 allocator_data.destroy(this->container + i);
            allocator_data.deallocate(container, size());
            this->container = tmp;
            sizeOfContainer+=n;
        }
       template <class InputIterator>
       void insert (iterator position, InputIterator first, InputIterator last,typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
       {
        int len = (last- first);
        pointer tmp = allocator_data.allocate(this->capacity() + len);
        iterator pos = position;
        iterator it = this->begin();
        size_type i = 0;
        while(it != pos)
        {
            this->allocator_data.construct(tmp + i, *it);
            it++;
            i++;
        }
        while (first != last)
        {
           this->allocator_data.construct(tmp + i, *first);
           first++;
           i++;
        }
        while (it < this->end())
        {
           this->allocator_data.construct(tmp + i, *it);
           it++;
           i++;
        }
        for (size_type i = 0; i < size(); i++)allocator_data.destroy(this->container + i);
        allocator_data.deallocate(container, capacity());
        container = tmp;
        sizeOfContainer += len;
       }
        iterator erase (iterator position)
        {
            pointer tmp = allocator_data.allocate(this->capacity());
            
            iterator it = this->begin();
            size_type i = 0;
            for (;it  != position; it++){
                this->allocator_data.construct(tmp + i, *it);i++;
            }
            size_type positionOfIter = i;
            it++;
            for (;it  < this->end(); it++){ this->allocator_data.construct(tmp + i, *it);i++;}
            for (size_type i = 0; i < this->size(); i++)allocator_data.destroy(this->container + i);
            allocator_data.deallocate(this->container, this->sizeOfContainer);
            sizeOfContainer--;
            for (size_type i = 0; i < size(); i++)this->container[i] = tmp[i];
            return this->begin() + positionOfIter;
            
        }
    
       iterator erase (iterator first, iterator last)
       {
        pointer tmp = allocator_data.allocate(this->capacity());
        size_type i = 0;
        
        while (first != last)first++;
        iterator firstIter = last;
        while (last != this->end()){this->allocator_data.construct(tmp+ i, *last++); i++; }
        sizeOfContainer = i;
        for (size_type i = 0; i < this->size(); i++)allocator_data.destroy(this->container + i);
        allocator_data.deallocate(this->container, this->sizeOfContainer);
        
        for (size_type i = 0; i < size(); i++)this->container[i] = tmp[i];
        return this->begin();
       }

        void swap(vector &x)
        {
            vector<value_type> tmp = *this;
            *this = x;
            x = tmp;
        }
        void clear()
        {
            allocator_data.deallocate(this->container, this->sizeOfContainer);
            sizeOfContainer = 0;
        }

       
        // end  Modifiers
        // start  Element access:
        reference operator[](size_type n) const
        {
            return (this->at(n));
        }
        const_reference operator[](size_type n)
        {
            return (this->at(n));
        }
        reference at(size_type n)
        {
            if (n >= size())
                throw out_of_range("out ouf range");
            return (container[n]);
        }
        const_reference at(size_type n) const
        {
            if (n >= size())
                throw out_of_range("out ouf range");
            return (&container[n]);
        }

        reference front()
        {
            return (this->container[0]);
        }
        const_reference front() const
        {

            return (this->container[0]);
        }
        reference back()
        {
            return (this->container[size() - 1]);
        }
        const_reference back() const
        {
            return (this->container[size() - 1]);
        }
        // end  Element access:
        // start  Capacity:  7 functions
        size_type size() const
        {
            return (this->sizeOfContainer);
        }
        size_type capacity() const
        {
            return (this->capacityOfContainer);
        }
        size_type max_size() const
        {
            return (allocator_data.max_size());
        }
        void resize(size_type n, value_type val = value_type())
        {
            if (n < size())
                sizeOfContainer = n;
            while (n > size())
                push_back(val);
        }
        bool empty() const
        {
            return (!(size() > 0));
        }
        void reserve(size_type n)
        {
            this->capacityOfContainer = n;
            container = allocator_data.allocate(n);
        }
        // end  Capacity:
        void test()
        {

            for (size_type i = 0; i < sizeOfContainer; i++)
            {
                std::cout << container[i] << std::endl;
            }
        }

    private:
        value_type *container;
        size_type capacityOfContainer;
        size_type sizeOfContainer;
        allocator_type allocator_data;
    };

}

template <class T, class Alloc>
bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return (lhs.size() == rhs.size());
}
template <class T, class Alloc>
bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return (lhs.size() != rhs.size());
}

template <class T, class Alloc>
bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return (lhs < rhs);
}
template <class T, class Alloc>
bool operator-(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return (lhs.size() - rhs.size());
}

template <class T, class Alloc>
bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return (lhs <= rhs);
}

template <class T, class Alloc>
bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return (lhs > rhs);
}

template <class T, class Alloc>
bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
{
    return (lhs >= rhs);
}

template <class T, class Alloc>
void swap(vector<T, Alloc> &x, vector<T, Alloc> &y)
{
    std::cout << "test this swap\n";
    x.swap(y);
}