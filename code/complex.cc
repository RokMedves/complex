#include "complex.hh"
#include <cassert>

Complex::~Complex(){}

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
  assert(z.im_ != 0 && z.re_ != 0);
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

// bool Complex::operator!=(const Complex& z){
//   return !(re_ == z.re_ && im_ == z.im_);
// }

std::ostream& operator<<(std::ostream& out, const Complex& z){
  out << z.re_ << " + " << z.im_ << "i";
  return out;
}

#define _USE_MATH_DEFINES
#include<cmath>
namespace complexFunction{
  const Complex I (0, 1);
  double abs(const Complex & z){
    return z.real() * z.real() + z.imag() * z.imag();
  }
  double arg(const Complex & z){
    if(z.real() == 0){return M_PI_2;}
    return atan(z.imag() / z.real());
  }
  Complex exp(const Complex & z){
    return exp(z.real()) * Complex(cos(z.imag()),  sin(z.imag()));
  }
}

