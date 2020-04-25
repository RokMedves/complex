#include<iostream>
#include "complex.hh"

///
///
/// Example use of complex.hh
///
///

int main(int argc, char* argv[]){
  std::cout << "works" << std::endl;

  Complex z {1, 0};
  Complex w {1, 1};
  std::cout << z << std::endl;
  std::cout << w << std::endl;
  std::cout << z+w << std::endl;
  std::cout << z-w << std::endl;
  std::cout << z*w << std::endl;
  std::cout << z/w << std::endl;
  std::cout << (z == w) << std::endl;
  std::cout << (Complex(1,1) == w ? "yes" : "no") << std::endl;
  std::cout << complexFunction::exp(Complex(0, 3.1415)) << std::endl;
  std::cout << complexFunction::log(complexFunction::exp(Complex(0,3.1415))) << std::endl;

  std::cout << "please input a complex number" << std::endl;
  Complex u;
  std::cin >> u;
  std::cout << u << std::endl;
  std::cout << complexFunction::sin(u) << std::endl;
  std::cout << complexFunction::cos(u) << std::endl;
  u = z;
  std::cout << u << std::endl;
  return 0;
}
