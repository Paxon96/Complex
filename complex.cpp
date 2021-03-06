#include<iostream>
#include<math.h>
#include <stdlib.h>
#include "complex.h"

using namespace std;
#define PI 3.14159265


// funkcja z faz� i aplitud� 
Complex::Complex(double _Real, double _Img)
{
	this->Real = _Real;
	this->Img = _Img;
}


Complex::~Complex()
{
	Real = 0;
	Img = 0;
}

Complex& Complex::operator= (const Complex &_s)
{
	Real = _s.Real;
	Img = _s.Img;
	
	return *this;
}

Complex& Complex::operator+=(Complex &_s)
{
	Real = Real + _s.Real;
	Img = Img + _s.Img;
	
	return *this;
}

Complex Complex::operator== (const Complex &_s)
{
	if(Real == _s.Real && Img == _s.Img)
		return true;
	else 
		return false;
}

Complex& Complex::operator-=(Complex &_s)
{
	Real = Real - _s.Real;
	Img = Img - _s.Img;
	
	return *this;
}

Complex& Complex::operator*=(Complex _s)
{
	double temp = Real;
	Real = (temp * _s.Real) - (Img * _s.Img);
	Img = temp * _s.Img + _s.Real * Img;
	return *this;
}

Complex& Complex::operator/=(Complex &_s)
{
	double R, I;
	double w = (_s.Real*_s.Real + _s.Img*_s.Img);
	
	R = (Real * _s.Real) + (Img * _s.Img);
	I = (Img * _s.Real) - (Real * _s.Img);
	
	Real = (R / w);
	Img =  (I / w);

	return *this;
}

ostream & operator << (ostream &c, const Complex &_s)
  {
    c << "(" << _s.Real << " , " << _s.Img << "i"<< ")";
    
    return c;
  };
  
  double czRzecz(const Complex &_s)
{	
	double n = _s.Real;
	return n;
}

double czUro(const Complex &_s)
{	
	double n = _s.Img;
	return n;
}

Complex Complex::operator~()
{
	return Complex(Real, -Img);
}

double amplituda(const Complex &_s)
{
	double mod;

	mod = sqrt(pow(_s.Real,2)+pow(_s.Img,2));

	return mod;
}

 double faza(const Complex &_s)
{
	double argument;
	
	if(_s.Real>0)
		argument = atan(_s.Img / _s.Real) * (180/PI);
	else if(_s.Real<0)
		argument = (atan(_s.Img / _s.Real) * (180/PI)) + PI;
	else if(_s.Real == 0 && _s.Img > 0)
		argument = 0.5 * PI;
	else if(_s.Real ==0 && _s.Img < 0)
		argument = -0.5 * PI;
	else 
		abort();
	
	return argument;
	
}
inline Complex operator* (Complex _s, Complex _c)
{
	Complex n(_s);
	return n *= _c;
}

inline Complex operator- (Complex _s, Complex _c)
{
	Complex n(_s);
	return n -=_c;
}

inline Complex operator/(Complex _s, Complex _c)
{
	Complex n(_s);
	return n/=_c;
}

inline Complex operator+(Complex _s, Complex _c)
{
	Complex n(_s);
	return n+=_c;
}
/*Complex operator*(const double n, const Complex &_s)
{
	return Complex(n*_s.Real, n*_s.Img);
}

Complex operator*(const Complex &_s, const double n)
{
	return Complex(n*_s.Real, n*_s.Img);
}

Complex operator-(const double n, const Complex &_s)
{
	return Complex(n - _s.Real, _s.Img);
}

Complex operator-(const Complex &_s, const double n)
{
	return Complex(_s.Real - n, _s.Img);
}

Complex operator+(const double n, const Complex &_s)
{
	return Complex(n + _s.Real, _s.Img);
}

Complex operator+(const Complex &_s, const double n)
{
	return Complex(_s.Real + n, _s.Img);
}

Complex operator/(const double n, const Complex &_s)
{
	Complex temp = _s;
	temp = -temp;
	double w = _s.Real * temp.Real + _s.Real * temp.Img + _s.Img * temp.Real - _s.Img * temp.Img;
	return Complex((n*temp.Real)/w,(n*temp.Img)/w);
}

Complex operator/(const Complex &_s, const double n)
{
	return Complex(_s.Real / n, _s.Img / n);
}
Complex Complex::operator* (const Complex &_s) const
{
	return Complex ((Real * _s.Real) - (Img * _s.Img) , Real * _s.Img + _s.Real * Img);
}

/*Complex Complex::operator- (const Complex &_s) const
{
	return Complex (this->Real - _s.Real, this->Img - _s.Img);
}

Complex Complex::operator/ (const Complex &_s) const
{
	return Complex (((this->Real * _s.Real) + (this->Img * _s.Img)) / (pow(_s.Real,2) + pow(_s.Img,2)), ((this->Img * _s.Real) - (this->Real * _s.Img)) / (pow(_s.Real,2) + pow(_s.Img,2)));
}

Complex Complex::operator+ (const Complex &_s) const
{
	return Complex (this->Real + _s.Real, this->Img + _s.Img);
}

*/


