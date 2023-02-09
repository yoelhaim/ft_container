/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:59:34 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/09 20:25:51 by yoelhaim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "vector/vector.hpp"
using namespace std;
int main()
{

    // ? test 1
    cout << "-------------------test 1 --------------------\n";
    {
        ft::vector<int> my_con(20, 10);
        std::vector<int> con(20, 10);
          my_con.assign(50,20);
        con.assign(50,20);

        // ft::vector<int>::iterator my_it = my_con.begin();
        // std::vector<int>::iterator it = con.begin();

        // // ! test contructor
        // cout << "********** start contructor **********" << endl;
        
        // cout << "-----  my Resultat ------" << endl;
        
        // for (; my_it < my_con.end(); my_it++)
        //     cout << *my_it << " ";
            
        // cout << "\n-----  sys Resultat ------" << endl;
        
        // for (; it < con.end(); it++)
        //     cout << *it << " ";

        //     cout << " \nsize  "<< con.size() << " capacity " << con.capacity()<< endl;
        //     cout << "size  "<< my_con.size() << " capacity " <<  my_con.capacity()<< endl;
            
        // cout << "\n********** end contructor **********" << endl<< endl;

        my_con.reserve(1000);
        for (ft::vector<int>::iterator it = my_con.begin(); it < my_con.end(); it++)
            cout << *it << " ";
        
        
    }
    // {
        
    //     ft::vector<int> v;
    //     ft::vector<int> a = v;
        
    //     a.push_back(10);
        
    //     std::cout << 

        
    // }


    //   // ? test 2
    // cout << "-------------------test 2 --------------------\n";
    // {
    //     ft::vector<int> my_con(10, 10);
    //     std::vector<int> con(10, 10);

    //     ft::vector<int>::iterator my_it = my_con.begin();
    //     std::vector<int>::iterator it = con.begin();

    //     // ! test contructor
    //     cout << "********** start contructor **********" << endl;
        
    //     cout << "-----  my Resultat ------" << endl;
        
    //     for (; my_it < my_con.end(); my_it++)
    //         cout << *my_it << " ";
            
    //     cout << "\n-----  sys Resultat ------" << endl;
        
    //     for (; it < con.end(); it++)
    //         cout << *it << " ";
            
    //     cout << "\n********** end contructor **********" << endl;
    // }
    

    // {
    //     std::vector<int> t;
    //     t.push_back(1);
    //     t.push_back(2);
    //     t.push_back(3);
    //     ft::vector<int>::reverse_iterator it = t.rbegin();
    //     // while (it != t.rend())
    //     // {
    //     // }
        
    //         std::cout <<  *it << endl;

        
        
    // }
}