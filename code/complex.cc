
/// store original cmath functions
#define _USE_MATH_DEFINES
#include<cmath>
namespace cmathFunction{
  double (&cmath_exp)(double x) = exp; //forward definition of this function; such that we include complex.hh only later
  double (&cmath_log)(double x) = log;
  double (&cmath_cos)(double x) = cos;
  double (&cmath_sin)(double x) = sin;
  double (&cmath_atan)(double x) = atan;
}


/// now do the complex.hh stuff
#include "complex.hh"
#include <cassert>


Complex::~Complex(){}


Complex Complex::operator+(const double& x) const{
  return Complex(re_ + x, im_);
}
Complex Complex::operator-(const double& x) const{
  return Complex(re_ - x, im_);
}
Complex Complex::operator*(const double& x) const{
  return Complex(re_ * x, im_);
}
Complex Complex::operator/(const double& x) const{
  assert(x != 0);
  return Complex(re_ / x, im_);
}

Complex Complex::operator+(const Complex& z) const{
  return Complex(re_ + z.re_, im_ + z.im_);
}
Complex Complex::operator-(const Complex& z) const{
  return Complex(re_ - z.re_, im_ - z.im_);
}
Complex Complex::operator*(const Complex& z) const{
  return Complex(re_ * z.re_ - im_ * z.im_,
		 re_ * z.im_ + im_ * z.re_);
}
Complex Complex::operator/(const Complex& z) const{
  assert(z.im_ != 0 || z.re_ != 0);
  double factor = z.re_ * z.re_ + z.im_ * z.im_;
  return Complex( (re_ * z.re_ + im_ * z.im_)  / factor,
		  (z.re_ * im_ - z.im_ * re_) / factor);
}

Complex& Complex::operator+=(const Complex& z){
    re_ += z.re_;
    im_ += z.im_;
    return *this;
}

Complex& Complex::operator-=(const Complex& z){
    re_ -= z.re_;
    im_ -= z.im_;
    return *this;
}

Complex& Complex::operator*=(const Complex& z){
  double temp_re = re_;
  double temp_im = im_;
  re_ = temp_re * z.re_ - temp_im * z.im_;
  im_ = temp_re * z.im_ + temp_im * z.re_;
  return *this;
}

Complex& Complex::operator/=(const Complex& z){
  assert(z.im_ != 0 && z.re_ != 0);
  double temp_re = re_;
  double temp_im = im_;
  double factor = z.re_ * z.re_ + z.im_ * z.im_;
  re_ = (temp_re * z.re_ + temp_im * z.im_) / factor;
  im_ = (-temp_re * z.im_ + temp_im * z.re_) / factor;
  return *this;
}

bool Complex::operator==(const Complex& z) const{
  return (re_ == z.re_ && im_ == z.im_);
}

bool Complex::operator!=(const Complex& z){
  return !(re_ == z.re_ && im_ == z.im_);
}

/// iostream overloads
std::ostream& operator<<(std::ostream& out, const Complex& z){
  out << z.re_ << " + " << z.im_ << "i";
  return out;
}
std::istream& operator>>(std::istream& in, Complex& z){
  in >> z.re_;
  in >> z.im_;
  return in;
}

///assignment operator
Complex & Complex::operator= (const Complex & z){
  re_ = z.re_;
  im_ = z.im_;
  return *this;
}

namespace complexFunction{
  const Complex I (0.0, 1.0);
  //double (*cmath_exp)(double x) = &exp ;
  double abs(const Complex & z){
    return z.real() * z.real() + z.imag() * z.imag();
  }
  double arg(const Complex & z){
    if(z.real() == 0){return M_PI_2;}
    return cmathFunction::cmath_atan(z.imag() / z.real());
  }
  Complex exp(const Complex & z){
    return  Complex(cmathFunction::cmath_cos(z.imag()),
		    cmathFunction::cmath_sin(z.imag())) *
      cmathFunction::cmath_exp(z.real());
  }
  Complex log(const Complex & z){
    return I * arg(z) + cmathFunction::cmath_log(abs(z));
  }
  Complex sin(const Complex & z){
    return ( exp(z) - exp(-z) ) / (I * 2);
  }
  Complex cos(const Complex & z){
    return ( exp(z) + exp(-z) ) / (2);
  }
}

