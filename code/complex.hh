///
/// Class for using complex numbers
/// By Rok Medves - 24. 4. 2020 
/// Oxford
///


#ifndef COMPLEX_HH
#define COMPLEX_HH

#include<iostream>
#define _USE_MATH_DEFINES
#include<cmath>

class Complex {
public:
  Complex(double re, double im = 0): re_ {re}, im_ {im}
  {}
  Complex(const Complex& z) = default;

  ~Complex();

  double real() const{
    return re_;
  }
  double imag() const{
    return im_;
  }
  double abs() const{
    return re_*re_ + im_*im_;
  }
  
  /// overloading operators
  //arithmetic operators
  Complex operator+(const Complex& z) const;
  Complex operator-(const Complex& z) const;
  Complex operator*(const Complex& z) const;
  Complex operator/(const Complex& z) const;
  Complex& operator+=(const Complex& z);
  Complex& operator-=(const Complex& z);
  Complex& operator*=(const Complex& z);
  Complex& operator/=(const Complex& z);
  //comparison operators
  bool operator>(const Complex& z) = delete;
  bool operator<(const Complex& z) = delete;
  bool operator==(const Complex& z) const;
  //bool operator!=(const Complex& z);
  friend std::ostream& operator<<(std::ostream& out, const Complex& z) ;
  
private:
  double re_;
  double im_;
};


namespace complexFunction{
  double abs(const Complex & z);
  double arg(const Complex & z);
  Complex exp(const Complex & z);
}

#endif //COMPLEX_HH
