#include "vect2.hpp"

vect2 vect2::operator-() const{ return vect2(-x, -y); }
vect2 &vect2::operator=(const vect2 &o) {
    x = o.x;
    y = o.y;
    return *this;
}

//access
int vect2::operator[](int i) const { return (i == 0 ? x : y); }
int &vect2::operator[](int i) { return (i == 0 ? x : y); }
//increment - decrement
vect2 vect2::operator++(int) {
    vect2 r(*this);
    ++*this;
    return r;
}
vect2 &vect2::operator++() {
    ++x;
    ++y;
    return *this;
}
vect2 vect2::operator--(int) { 
    vect2 r(*this);
    --*this;
    return r;
}
vect2 &vect2::operator--(){
    --x;
    --y;
    return *this;
}
//math
vect2 vect2::operator+(const vect2 &o) const {
    vect2 r(*this);
    return r+=o;
}
vect2 &vect2::operator+=(const vect2 &o){
    x += o.x;
    y += o.y;
    return *this;
}
vect2 vect2::operator-(const vect2 &o) const{
    vect2 r(*this);
    return r -= o;
}
vect2 &vect2::operator-=(const vect2 &o){
    x -= o.x;
    y -= o.y;
    return *this;
}
vect2 vect2::operator*(int s) const {
    vect2 r(*this);
    return r*=s;
}
vect2 &vect2::operator*=(int s) {
    x *=s;
    y *=s;
    return *this;
}
//bool
bool vect2::operator==(const vect2 &o) const {return (x == o.x && y == o.y); }
bool vect2::operator!=(const vect2 &o) const {return (x != o.x || y != o.y); }
vect2 operator*(int s, const vect2 &o) {return (o * s); }
std::ostream &operator<<(std::ostream &os, const vect2 &o){
    os << "{" << o[0] << ", " << o[1] << "}";
    return os;
}