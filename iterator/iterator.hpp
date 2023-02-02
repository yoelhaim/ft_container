/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:22:51 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/02 19:18:38 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
namespace ft
{

    template <class T>
    class Iterator
    {
    public:
        
        iterator()
        {
            std::cout << "d c" << std::endl;
        }
        ~iterator();
    };

} // namespace ft
