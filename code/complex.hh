///
/// Class for using complex numbers
/// By Rok Medves - 24. 4. 2020 
/// Oxford
///


#ifndef COMPLEX_HH
#define COMPLEX_HH

#include<iostream>




class Complex {
public:
  Complex(double re = 0, double im = 0): re_ {re}, im_ {im}
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
  //arithmetic operators with Complex
  Complex operator+(const Complex& z) const;
  Complex operator-(const Complex& z) const;
  Complex operator*(const Complex& z) const;
  Complex operator/(const Complex& z) const;
  //arithmetic operators with double
  Complex operator+(const double& x) const;
  Complex operator-(const double& x) const;
  Complex operator*(const double& x) const;
  Complex operator/(const double& x) const;

  Complex operator+() const {return *this;}
  Complex operator-() const {return Complex(-re_, -im_);};
  
  Complex& operator+=(const Complex& z);
  Complex& operator-=(const Complex& z);
  Complex& operator*=(const Complex& z);
  Complex& operator/=(const Complex& z);
  //comparison operators
  bool operator>(const Complex& z) = delete;
  bool operator<(const Complex& z) = delete;
  bool operator==(const Complex& z) const;
  bool operator!=(const Complex& z);

  //iostream operators
  friend std::ostream& operator<<(std::ostream & out, const Complex& z);
  friend std::istream& operator>>(std::istream & in, Complex& z);

  //assignmnet operator
  Complex& operator= (const Complex & z);
private:
  double re_;
  double im_;
};


namespace complexFunction{
  double abs(const Complex & z);
  double arg(const Complex & z);
  Complex exp(const Complex & z);
  Complex log(const Complex & z);
  Complex cos(const Complex & z);
  Complex sin(const Complex & z);
}

#endif //COMPLEX_HH
