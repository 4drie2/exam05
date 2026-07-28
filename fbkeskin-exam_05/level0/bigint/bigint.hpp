// #ifndef BIGINT
// #define BIGINT

// #include <sstream>
// #include <iostream>
// #include <string>
// #include <cstdlib>

// class bigint {
// 	private:
// 		std::string str;
// 		//std::string result;
// 	public:
// 		bigint();
// 		bigint(unsigned int num);
// 		bigint(const bigint& source);

// 		std::string getStr()const;

// 		bigint& operator=(const bigint& source);

// 		// addition
// 		bigint operator+(const bigint& other)const;
// 		bigint& operator+=(const bigint& other);

// 		// increments
// 		bigint operator++(int); // x++
// 		bigint& operator++(); // ++x

// 		// shift with num
// 		bigint operator<<(unsigned int n)const;
// 		bigint operator>>(unsigned int n)const;
// 		bigint& operator<<=(unsigned int n);
// 		bigint& operator>>=(unsigned int n);

// 		//shift with object
// 		bigint operator<<(const bigint& other)const;
// 		bigint operator>>(const bigint& other)const;
// 		bigint& operator<<=(const bigint& other);
// 		bigint& operator>>=(const bigint& other);

// 		// ==, !=, <, >, <=, >=
// 		bool operator==(const bigint& other) const;
// 		bool operator!=(const bigint& other) const;
// 		bool operator<(const bigint& other) const;
// 		bool operator>(const bigint& other) const;
// 		bool operator<=(const bigint& other) const;
// 		bool operator>=(const bigint& other) const;

// 		// ~bigint();

// };

// std::ostream& operator<<(std::ostream& output, const bigint& obj);

// #endif



// ------------------------------------------------------------
// ---------------- C version ---------------------------------
// ------------------------------------------------------------



#pragma once
#include <iostream>
#include <string>

class bigint{
	std::string s;
	public:
		bigint(unsigned int n = 0);
		bigint(const bigint &o);
		~bigint();
		
		const std::string &str() const;
		bigint &operator=(const bigint &o);
		
		// add
		bigint operator+(const bigint &o) const;
		bigint &operator+=(const bigint &o);
		
		//increment
		bigint operator++(int);
		bigint &operator++();
		
		//shift
		bigint operator<<(const bigint &o) const;
		bigint &operator<<=(const bigint &o);
		
		// with obj
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
std::ostream &operator<<(std::ostream &os, const bigint &n);
