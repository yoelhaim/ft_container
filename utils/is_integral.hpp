#include <type_traits>
template <class T>

struct is_integral;

template<>
struct is_integral<bool>
{
    
};
template<>
struct is_integral<char>
{
    
};
template<>
struct is_integral<char16_t>
{
    
};
template<>
struct is_integral<char32_t>
{
    
};
template<>
struct is_integral<wchar_t>
{
    
};
template<>
struct is_integral<signed char>
{
    
};
template<>
struct is_integral<short int>
{
    
};
template<>
struct is_integral<int>
{
    
};
template<>
struct is_integral<long int>
{
    
};
template<>
struct is_integral<unsigned char>
{
    
};
template<>
struct is_integral<long long int>
{
    
};
template<>
struct is_integral<unsigned short int>
{
    
};
template<>
struct is_integral<unsigned int>
{
    
};
template<>
struct is_integral<unsigned long int>
{
    
};
template<>
struct is_integral<unsigned long long int>
{
    
};
