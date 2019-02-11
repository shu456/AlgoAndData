#include <iostream>

#include "../Source/utility.hpp"

constexpr int Test()
{
  return 50;
}

int main(void)
{
  Sum<2,5,10,Test()> a;
  std::cout << a << std::endl;
  std::cout << Sum<2,5,12,5,10,9>() << std::endl;
  
	return 0;
}