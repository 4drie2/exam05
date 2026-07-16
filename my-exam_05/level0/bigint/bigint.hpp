#pragma once

#include <iostream>
#include <string>

class bigint {
    std::string s;
    public :
        bigint(unsigned int n = 0);
        bigint(const bigint &o);
        ~bigint();

        const std::string &str() const;
        bigint &operator=(const bigint &o);

        //add
        bigint operator+(const bigint &o) const;
        bigint &operator+=(const bigint &o);

        //incr
        bigint operator++(int);
        bigint &operator++();

        //with num
        bigint operator<<(unsigned int n) const;
        bigint &operator<<=(unsigned int n);

        //with obj
        bigint operator>>(const bigint &o)const;
        bigint &operator>>=(const bigint &o);

        //bool
        bool operator<(const bigint &o)const;
        bool operator<=(const bigint &o)const;
        bool operator>(const bigint &o)const;
        bool operator>=(const bigint &o)const;
        bool operator==(const bigint &o)const;
        bool operator!=(const bigint &o)const;
};

std::ostream &operator<<(std::ostream &os, const bigint &n);