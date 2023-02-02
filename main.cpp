/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:28:53 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/02 19:45:52 by yoelhaim         ###   ########.fr       */
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


//  namespace  std

// namespace ft = std;
void check()
{
    system("leaks ft_container");
    // std::cout << "bye";
}
int main()
{
    // ft::vector<int> s;
    // ft::vector<int> s2;
    // s2.push_back(1); // s1  c1
    // s2.push_back(-3); // s2 c2
    // s.push_back(2); // s3  c4
    // s.push_back(10); // s4  c4
    // s.push_back(6);  // s5  c8
    // s.push_back(5);  // s6  c8
    // s.push_back(115);  
    // s.push_back(89);  
    // s.push_back(1000);  
    // s.push_back(12);  
    // s.push_back(99);  
    // s.push_back(102);  
    // s.push_back(3);  
    // s.push_back(-5);  
    // // s.assign(3,100);
    // // s.pop_back();
    // // s.pop_back();

    // std::cout <<  "--------------------\n before swap\n";
    // std::cout << s.size() << std::endl;
    // std::cout << s2.size()<< std::endl << "--------------------\n";
    // s.swap(s2);
    // s.clear();
    // // for (size_t i = 0; i < s.size(); i++)
    // // {
    // //     std::cout << s[i]<< "\n";
    // // }
    // // return 0;
    
    // std::cout << "after swap\n";
    // std::cout << s.size() << std::endl;
    // std::cout << "maxsize => "<< s.max_size() << std::endl;
    // std::cout << s2.size()<< std::endl << "--------------------\n";
    // std::cout << "maxsize => "<< s2.max_size() << std::endl;
    // std::cout << "--------------------\n";
    // s.test();
    // std::cout <<"--------------------\n";
    // s2.test();
    // std::cout <<"--------------------\n";

    // for (size_t i = 0; i < s.size(); i++)
    // {
    //     std::cout << s[i]<< std::endl;
    // }



    //? test resize 
    
    // ft::vector<int> capacity;
    
    // for (size_t i = 1; i <= 10; i++)capacity.push_back(i);
    // capacity.resize(5);
    // capacity.resize(8,1000);

    // std::cout << capacity.size()<< std::endl;
    // capacity.test(); 

    // std::cout << "the vector is empty ? : " << capacity.empty() << std::endl;

    //! test shrink-fill
//    ft::vector<int> myvector (100);
//   std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

//   myvector.resize(10);
//   std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';

//   myvector.shrink_to_fit();
//   std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';


//operator []

//     ft::vector<int>  op;
//     for (size_t i = 0; i < 10; i++)op.push_back(i+ 6);
//     for (size_t i = 0; i < op.size(); i++)std::cout << " "<< op[i];
    
//  std::cout << std::endl;
//      std::cout <<  "at  "<< op.at(9)<< std::endl;
//      std::cout <<  "front  "<< op.front()<< std::endl;
//      std::cout <<  "back  "<< op.back()<< std::endl;
//     try
//     {
//         std::cout << op[-1];
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//data
    ft::vector<int> myvector (5, 10);
   int* p = myvector.data();

    *p = 10;
    ++p;
    *p = 20;
     p[2] = 100;
    myvector.resize(10, 7);

  std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

//    system("leaks ft_container");
//   atexit(check);
  return 0;
  
}