#include "vect2.hpp"

vect2	&vect2::operator=(const vect2 &o){
	if (this != &o){
		x = o.x;
		y = o.y;
	}
	return (*this);
}

// Accesses
int	vect2::operator[](int i) const { return (i == 0 ? x : y); }
int	&vect2::operator[](int i) { return (i == 0 ? x : y); }

// Increments & Decrements
vect2	&vect2::operator++(){
	++x;
	++y;
	return (*this);
}

vect2	vect2::operator++(int){
	vect2	c(*this);
	++x;
	++y;
	return (c);
}

vect2	&vect2::operator--(){
	--x;
	--y;
	return (*this);
}

vect2	vect2::operator--(int){
	vect2	c(*this);
	--x;
	--y;
	return (c);
}

// Maths
vect2	vect2::operator+(const vect2 &o) const { return (vect2(x + o.x, y + o.y)); }

vect2	&vect2::operator+=(const vect2 &o){
	x += o.x;
	y += o.y;
	return (*this);
}

vect2	vect2::operator-(const vect2 &o) const { return (vect2(x - o.x, y - o.y)); }

vect2	&vect2::operator-=(const vect2 &o){
	x -= o.x;
	y -= o.y;
	return (*this);
}

vect2	vect2::operator*(int s) const { return (vect2(x * s, y * s)); }

vect2	&vect2::operator*=(int s){
	x *= s;
	y *= s;
	return (*this);
}

// Unary Minus
vect2	vect2::operator-() const { return (vect2(-x, -y)); }

// Comparisons
bool	vect2::operator==(const vect2 &o) const { return (x == o.x && y == o.y); }
bool	vect2::operator!=(const vect2 &o) const { return (x != o.x || y != o.y); }

vect2	operator*(int s, const vect2 &o) { return (o * s); }

std::ostream	&operator<<(std::ostream &os, const vect2 &o){
	os << "{" << o[0] << ", " << o[1] << "}";
	return (os);
}
