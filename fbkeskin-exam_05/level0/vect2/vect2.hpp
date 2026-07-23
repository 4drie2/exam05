#pragma once

#include <iostream>

class	vect2{
	int	x;
	int	y;
	public:
		vect2(int x = 0, int y = 0) : x(x), y(y) {};
		vect2(const vect2 &o) : x(o.x), y(o.y) {};
		vect2	&operator=(const vect2 &o);

		// Accesses
		int	operator[](int i) const;
		int	&operator[](int i);

		// Increments & Decrements
		vect2	&operator++();		// ++x
		vect2	operator++(int);	// x++
		vect2	&operator--();		// --x
		vect2	operator--(int);	// x--

		// Maths
		vect2	operator+(const vect2 &o) const;
		vect2	&operator+=(const vect2 &o);

		vect2	operator-(const vect2 &o) const;
		vect2	&operator-=(const vect2 &o);

		vect2	operator*(int s) const;
		vect2	&operator*=(int s);

		// Unary Minus
		vect2	operator-() const;

		// Comparisons
		bool	operator==(const vect2 &o) const;
		bool	operator!=(const vect2 &o) const;
};

vect2	operator*(int s, const vect2 &o);

std::ostream	&operator<<(std::ostream &os, const vect2 &o);
