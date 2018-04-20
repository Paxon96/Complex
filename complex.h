#ifndef COMPLEX_H
#define COMPLEX_H
#include<iostream>
#include <stdlib.h>

using namespace std;

class Complex
{
	double Real, Img;
	
	public:
	Complex(double = 0,double = 0);
	~Complex();
	Complex & operator= (const Complex &_s);
	Complex operator== (const Complex &_s);
	
	Complex operator~();
	
	Complex & operator+=(Complex &_s);
	Complex & operator-=(Complex &_s);
	Complex & operator*=(Complex _s);
	Complex & operator/=(Complex &_s);
	
   	friend ostream & operator<< (ostream &c, const Complex &_s);
   	friend Complex operator*(Complex, Complex);
  	friend Complex operator-(Complex, Complex);
	friend Complex operator+(Complex, Complex);
	friend Complex operator/(Complex, Complex);
	
   	friend double czRzecz(const Complex &_s);
	friend double czUro(const Complex &_s);
	friend double amplituda(const Complex &_s);
	friend double faza(const Complex &_s);
	
	//	Complex operator+ (const Complex &_s) const;
	//	Complex operator* (const Complex &_s) const;
	//	Complex operator- (const Complex &_s) const;
	//	Complex operator/ (const Complex &_s) const;
	//	friend Complex operator*(const double n, const Complex &_s);
	//	friend Complex operator*(const Complex &_s, const double n);
	// 	friend Complex operator-(const double n, const Complex &_s);
	//  friend Complex operator/(const double n, const Complex &_s);
	//  friend Complex operator+(const double n, const Complex &_s);
};

#endif
