/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoelhaim <yoelhaim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:28:53 by yoelhaim          #+#    #+#             */
/*   Updated: 2023/02/08 13:28:25 by yoelhaim         ###   ########.fr       */
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
// void check()
// {
//     system("leaks ft_container");
//     // std::cout << "bye";
// }

// class A {
    
//   private:
//     A()
//     {
//         std::cout << "hello from A" << '\n';
//     }

//     friend class B;
// };

// class B {
//   public:
//     int a;
//     void begin()
//     {
//         A a;
//     }
// };

int main()
{
    ft::vector<int> data1;
    data1.push_back(4);
    data1.push_back(9);
    data1.push_back(41);
    ///
    data1.push_back(120);
    data1.push_back(98);
    
    std::cout << data1.capacity() << " "<< data1.size() <<std::endl;
    
    ft::vector<int> data(7,2);
    // ft::vector<int>::iterator pw = data.begin();
    // std::cout << data1.size() << std::endl;
    data1.insert(data1.end() -2 , data.begin(),data.end());

    // // data1.erase(data1.begin());
    
    // std::cout << data1.size() << std::endl;

    
    // ft::vector <int > test (data.begin(),data.end());
    // ft::vector<int> data2(test.begin(), test.end());
    // ft::vector<int> data(5,9);
    // ft::vector<int> data1(1,6);
    // data.push_back(2);
    // data.push_back(4);
    // data.push_back(3);
    // data.push_back(4);
//    data1.swap(data);
    
ft::vector<int>::iterator p = data1.begin();
// ft::vector<int>::iterator p1 = data.begin();
// p1++;
// std::cout<<"sizeeeeee=> " << data2.size() << std::endl;
// std::cout << *p1 + *p << std::endl;
     int i=0;
    //  std::cout<< p[i] ;
  while( p < data1.end())
  {
    std::cout << i  + 1<< "   ";
    std::cout << *p<< std::endl;
    i++;
    p++;
  }
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
//     ft::vector<int> myvector (5, 10);
//    int* p = myvector.data();

//     *p = 10;
//     ++p;
//     *p = 20;
//      p[2] = 100;
//     myvector.resize(10, 7);

//   std::cout << "myvector contains:";
//   for (unsigned i=0; i<myvector.size(); ++i)
//     std::cout << ' ' << myvector[i];
//   std::cout << '\n';

//    system("leaks ft_container");
//   atexit(check);


// copy
    // ft::vector<int> a1(5,10);
    // ft::vector<int> a2(a1);
    

    // for (size_t i = 0; i < a1.size(); i++)
    // {
    //     std::cout << " "<< a2[i];
    // }

    //   for (size_t i = 0; i < a1.size(); i++)
    // {
    //     std::cout << " "<< a1[i];
    // }

    //swap

//     ft::vector<int> foo (3,100);   // three ints with a value of 100
//   ft::vector<int> bar (5,200);  
  
// //  if (foo==bar) std::cout << "foo and bar are equal\n";
//   if (foo!=bar) std::cout << "foo and bar are not equal\n";
// //   if (foo< bar) std::cout << "foo is less than bar\n";
// //   if (foo> bar) std::cout << "foo is greater than bar\n";
// //   if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// //   if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//    // five ints with a value of 200
//    std::cout <<  "--------------------\n before swap\n";
//     std::cout << foo.size() << std::endl;
//     std::cout << bar.size()<< std::endl << "--------------------\n";
//   foo.swap(bar);
//        std::cout <<  "--------------------\n before swap\n";
//     std::cout << foo.size() << std::endl;
//     std::cout << bar.size()<< std::endl << "--------------------\n";

//   ft::vector<int> foo;
//   foo.push_back(20);
//   foo.push_back(100);
//   foo.push_back(70);
//   foo.push_back(57);
  
//  ft::vector<int>::iterator p = foo.begin() ;
 
//   std::cout << (*p-=1) << std::endl;
//   std::cout << *p<< std::endl;
 
//  int i=0;
//   while( p < foo.end())
//   {
//     std::cout << i  + 1<< "   ";
//     std::cout << *p<< std::endl;
//     i++;
//     p++;
//   }


    // std::allocator<int> myAllocator;
 
    // // allocate space for five ints
    // int* container = myAllocator.allocate(5);

    // ft::vector<int>::iterator g(container);
    
    return 0;
  
}