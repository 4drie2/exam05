#pragma once

#include <string>
#include <iostream>

class bigint{
    std::string s;
    public:
        bigint(unsigned int n = 0);
        bigint(const bigint &o);
        ~bigint();
        
        const std::string &str() const;
        bigint &operator=(const bigint &o);
        
        //add
        bigint operator+(const bigint &o) const;
        bigint &operator+=(const bigint &o);

        //increment
        bigint operator++(int);
        bigint &operator++();

        //shift
        bigint operator<<(const bigint &o) const;
        bigint &operator<<=(const bigint &o);
        bigint operator>>(const bigint &o) const;
        bigint &operator>>=(const bigint &o);

        //bool
		bool operator<(const bigint &o) const;
		bool operator<=(const bigint &o) const;
		bool operator>(const bigint &o) const;
		bool operator>=(const bigint &o) const;
		bool operator==(const bigint &o) const;
		bool operator!=(const bigint &o) const;
};

std::ostream &operator<<(std::ostream &os, const bigint &o);