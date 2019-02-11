#ifndef UTILITY_HPP
#define UTILITY_HPP

#include <iostream>

/**
* No practical use, for practice only.
*/
template<int N, unsigned pow>
struct Pow
{
  enum { Answer = N * Pow<N,pow-1U>::Answer };
};

template<int N>
struct Pow<N,1U>
{
  enum { Answer = N };
};

/**Factorial*/
template<unsigned T1>
struct Factorial
{
  enum { Answer = T1 * (Factorial<T1-1U>::Answer) };
};

template<>
struct Factorial<2U>
{
  enum { Answer = 2 };
};

template<>
struct Factorial<1U>
{
  enum { Answer = 1 };
};

/**0! = 1*/
template<>
struct Factorial<0U>
{
  enum { Answer = 1 };
};

template<int T1, int ... Args>
struct Sum
{
  enum { Answer = (Sum<T1>::Answer) + (Sum<Args...>::Answer)  };
};

template<int T1>
struct Sum<T1>
{
  enum { Answer = T1 };
};

template<int ... T>
std::ostream& operator<<(std::ostream& os, Sum<T...> const& )
{
  os << Sum<T...>::Answer;
  return os;
}


#endif

