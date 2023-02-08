/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iteratorTrait.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:59:42 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/08 23:20:39 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
    template <typename iter>
    class iteratorTrait
    {
    public:
        typedef typename iter::reference reference;
        typedef typename iter::difference_type difference_type;
        typedef typename iter::value_type value_type;
        typedef typename iter::pointer pointer;
        typedef typename iter::iterator_category iterator_category;
    };

} // namespace ft
