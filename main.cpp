/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pro <pro@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:28:53 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/10 21:18:00 by pro              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define stt 0

#if stt
    #include <vector>
    namespace ft = std;
#else
    #include "vector/vector.hpp"
#endif



int main()
{
    ft::vector<int>  v;
    ft::vector<int>  v1(5,100);
    
    for (size_t i = 0; i < 10; i++)v.push_back(i + 1);

    ft::vector<int>::reverse_iterator it= v.rend();
    std::cout << *it<< std::endl;

    //  for (int i = 0;it < v.end();it++, i++)std::cout<< i <<" " << *it<< std::endl;
    
    // v.erase(v.begin());
    
    // ft::vector<int>::iterator it = v.begin(); 
   
    // std::cout << "size : " << v.size() << " capacity : " << v.capacity() << std::endl;

    // v.assign(v1.begin(),v1.end());
    // ? test iterator vector   
    // for (int i = 0;it < v.end();it++, i++)std::cout<< i <<" " << *it<< std::endl;
  
    return 0;
  
}