/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:59:34 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/01/31 22:26:29 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <memory>
int main()
{
    std::vector<int> test;

    std::allocator<int> myAllocator;

    int *alloc = myAllocator.allocate(3);
    alloc[0] = 1;

    std::cout << alloc[0] << std::endl;
}