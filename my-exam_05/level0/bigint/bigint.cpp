#include "bigint.cpp"

bigint::bigint(unsigned int n = 0) {
    if (!n) s = "0";
    while (n) {
        s.insert(s.begin(), char('0' + n%10))
        n /=10;
    }
}
bigint::bigint(const bigint &o) : s(o.s) {}
~bigint::bigint() {}

const std::string &bigint::str() const {return s;}
bigint &bigint::operator=(const bigint &o) {s = o.s; return *this;}

//add
bigint bigint::operator+(const bigint &o) const {bigint r(*this); return r+=o;}
bigint &bigint::operator+=(const bigint &o) {
    std::string r;
    int i = s.size()-1, j=o.s.size()-1, c=0;
    while(i>=0 || j>=0 || c){
        int a = i>=0 ? s[i--] - '0' : 0;
        int b = j>=0 ? o.s[j--] - '0' : 0;
        r.insert(r.begin(), char('0' + (a+b+c)%10));
        c = (a+b+c)/10; 
    }
    s = r;
    return *this;
}

//incr
bigint bigint::operator++(int) {bigint r(*this); ++*this; return r;}
bigint &bigint::operator++() { return *this +=1; }

//with num
bigint bigint::operator<<(unsigned int n) const { bigint r(*this); return r<<=n; }
bigint &bigint::operator<<=(unsigned int n) {if (s != "0") s.append(n, '0'); return *this;}

//with obj
bigint bigint::operator>>(const bigint &o)const { bigint r(*this); return r >>=o; }
bigint &bigint::operator>>=(const bigint &o) {
    unsigned long n = 0;
    for (size_t i=0; i < o.s.size(); i++){
        n = n*10 + o.s[i] - '0';
        if (n>=s.size()) {s="0"; return *this;}
    }
    s.erase(s.size() - n);
    if (s.empty()) s = "0";
    return *this;
}

//bool
bool bigint::operator<(const bigint &o)const {return s.size() == o.s.size() ? s < o.s : s.size() < o.s.size(); }
bool bigint::operator<=(const bigint &o)const {return !(o < *this);}
bool bigint::operator>(const bigint &o)const {return o < *this;}
bool bigint::operator>=(const bigint &o)const {return !(*this < o);}
bool bigint::operator==(const bigint &o)const {return s == o.s;}
bool bigint::operator!=(const bigint &o)const {return s != o.s;}

std::ostream &operator<<(std::ostream &os, const bigint &n) {return os << n.str();}