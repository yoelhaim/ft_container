/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:25:24 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/02 17:34:57 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <memory>
#include <exception>
using namespace std;

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
    public:
        typedef Alloc allocator_type;
        typedef typename allocator_type::value_type     value_type;
        typedef size_t size_type;
        
        typedef typename  allocator_type::reference       reference;
        typedef typename  allocator_type::const_reference const_reference;

        // start Member functions
        vector()
        {
            sizeOfContainer = 0;
            capacityOfContainer = 0;
        }
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type())
        {
            this->allocator_data = alloc;
            this->sizeOfContainer = n;
            this->capacityOfContainer = n;
            container = allocator_data.allocate(n);
            for (size_type i = 0; i < n; i++)
                container[i] = val;
        }
        ~vector() {}
        vector& operator= (const vector& x){
            size_type nb = x.size();
            // allocator_data.deallocate( this->container, this->sizeOfContainer);
            this->sizeOfContainer = nb;
            this->capacityOfContainer = x.capacity();
            this->container =  allocator_data.allocate(nb);
            for (size_type i = 0; i < nb; i++)
                this->container[i] = x.container[i];   
            return *this;
        }
        //end  Member functions
        // start  Modifiers
        //TODO  template <class InputIterator>  void assign (InputIterator first, InputIterator last);
        void assign(size_type n, const value_type& val)
        {
           
            // allocator_data.deallocate(container, sizeOfContainer);
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
            }
            else if (size() == capacity())
            {
                value_type *tmp = container;
                allocator_data.deallocate(container, size());
                container = allocator_data.allocate(capacity() * 2);
                this->reserve(capacity() * 2);

                for (size_type i = 0; i < size(); i++)
                    container[i] = tmp[i];
               
                container[sizeOfContainer++] = value;
            }
            else
                container[sizeOfContainer++] = value;
        }
        void pop_back()
        {
            allocator_data.destroy(&container[size() - 1]);
            sizeOfContainer--;
        }
        //TODO iterator insert (iterator position, const value_type& val);
        //TODO  void insert (iterator position, size_type n, const value_type& val);
        //TODO template <class InputIterator>    void insert (iterator position, InputIterator first, InputIterator last);
        //TODO iterator erase (iterator position);iterator erase (iterator first, iterator last);

        void swap (vector& x)
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
        // TODO template <class... Args>iterator emplace (const_iterator position, Args&&... args);
        // TODO template <class... Args>  void emplace_back (Args&&... args);
         // end  Modifiers
         // start  Element access:
         reference operator[] (size_type n)const
         {        
            return(this->at(n));
         }
         const_reference operator[] (size_type n) 
         {
             return(this->at(n));
         }
         reference at (size_type n)
         {
            if (n >= size())
                throw out_of_range("out ouf range");
            return(container[n]);
         }
        const_reference at (size_type n) const
        {
            if (n >= size())
                throw out_of_range("out ouf range");
            return(&container[n]);
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
        
        value_type* data() 
        {
            return (this->container);
        }
        const value_type* data() const 
        {
            return (this->container);
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
            return(4611686018427387903);
        }
       void resize (size_type n, value_type val = value_type())
       {
        if (n < size())
            sizeOfContainer = n;
        while (n > size())
            push_back(val);
       }
       bool empty() const
       {
        return(!(size() > 0));
       }
       void reserve (size_type n)
       {
         this->capacityOfContainer = n;
       }
       void shrink_to_fit()
       {
         this->reserve(this->size());
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