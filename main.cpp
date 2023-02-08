/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:28:53 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/08 14:00:29 by yoelhaim         ###   ########.fr       */
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
    ft::vector<int>  v(10,3);
    ft::vector<int>::iterator it = v.begin();
    it = v.insert(v.begin(), 1, 4);

// ? test iterator vector 
    for (int i = 1;it < v.end();it++, i++)std::cout<< i <<" " << *it<< std::endl;
  
    
    
    
    return 0;
  
}