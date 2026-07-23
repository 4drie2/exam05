#pragma once

#include <iostream>

class vect2{
	int _x;
	int _y;
	public :
		vect2(int x = 0, int y = 0) : _x(x), _y(y) {};
		vect2(const vect2 &o) : _x(o._x), _y(o._y) {};
		vect2 &operator=(const vect2 &o);

		//access
		int operator[](int i) const;
		int &operator[](int i);

		//increment & decrement
		vect2 operator++(int);
		vect2 &operator++();
		vect2 operator--(int);
		vect2 &operator--();
		
		// maths
		vect2 operator+(const vect2 &o) const;
		vect2 &operator+=(const vect2 &o);

		vect2 operator-(const vect2 &o) const;
		vect2 &operator-=(const vect2 &o);

		vect2 operator*(int scalar)const ;
		vect2 &operator*=(int scalar);

		vect2 operator-() const;

		//bool
		bool operator==(const vect2 &o) const;
		bool operator!=(const vect2 &o) const;
};

vect2 operator*(int scalar, const vect2 &o);
std::ostream &operator<<(std::ostream &os, const vect2 &o);