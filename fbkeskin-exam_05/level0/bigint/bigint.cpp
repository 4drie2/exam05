/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigint.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fatkeski <fatkeski@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 14:27:29 by fatkeski          #+#    #+#             */
/*   Updated: 2025/07/26 18:15:45 by fatkeski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "bigint.hpp"

// bigint::bigint()
// {
// 	this->str = "0";
// }

// bigint::bigint(unsigned int num)
// {
// 	std::stringstream ss;
// 	ss << num;
// 	this->str = ss.str();
// 	// std::cout << "str: " << str << std::endl;
// }

// bigint::bigint(const bigint& source)
// {
// 	(*this) = source;
// }

// bigint& bigint::operator=(const bigint& source)
// {
// 	if(this == &source)
// 		return(*this);
// 	this->str = source.str;
// 	return(*this);
// }

// std::string bigint::getStr() const
// {
// 	return(this->str);
// }

// std::string reverse(const std::string& str)
// {
// 	std::string revStr;
// 	for(size_t i = str.length(); i > 0; i--)
// 	{
// 		revStr.push_back(str[i - 1]);
// 	}
// 	return(revStr);
// }

// std::string addition(const bigint& obj1, const bigint& obj2)
// {
// 	std::string str1 = reverse(obj1.getStr());
// 	std::string str2 = reverse(obj2.getStr());
// 	std::string result;
// 	size_t len1 = str1.length();
// 	size_t len2 = str2.length();

// 	if(len1 > len2)
// 	{
// 		int diff = len1 - len2;
// 		while(diff > 0)
// 		{
// 			str2.push_back('0');
// 			diff--;
// 		}
// 	}
// 	else if(len2 > len1)
// 	{
// 		int diff = len2 - len1;
// 		while(diff > 0)
// 		{
// 			str1.push_back('0');
// 			diff--;
// 		}
// 	}

// 	int carry = 0;
// 	int digit1;
// 	int digit2;
// 	size_t len = str1.length();
// 	for(size_t i = 0; i < len; i++)
// 	{
// 		digit1 = str1[i] - '0';
// 		// std::cout <<  "digit1:" << digit1 << std::endl;
// 		digit2 = str2[i] - '0';
// 		// std::cout << "digit2:" << digit2 << std::endl;
// 		int res = digit1 + digit2 + carry;
// 		// std::cout << res << std::endl;
// 		if(res > 9)
// 		{
// 			carry = res / 10;
// 			result.push_back((res % 10) + '0');
// 		}
// 		else
// 			result.push_back(res + '0');
// 	}
// 	if(carry != 0)
// 		result.push_back(carry + '0');
// 	return(reverse(result));
// }

// bigint bigint::operator+(const bigint& other)const
// {
// 	bigint temp(other);
// 	temp.str.clear();
// 	std::string result = addition(*this, other);
// 	temp.str = result;
// 	//std::cout << "r: " << result << std::endl;

// 	return(temp);
// }

// bigint& bigint::operator+=(const bigint& other)
// {
// 	(*this) = (*this) + other;
// 	return(*this);
// }

// bigint& bigint::operator++()
// {
// 	*(this) = *(this) + bigint(1);
// 	return(*this);
// }

// bigint bigint::operator++(int)
// {
// 	bigint temp = (*this);
// 	*(this) = *(this) + bigint(1);
// 	return(temp);
// }


// bigint bigint::operator<<(unsigned int n)const
// {
// 	bigint temp = *this;

// 	temp.str.insert(temp.str.end(), n, '0');
// 	//std::cout << temp.str << std::endl;
// 	return(temp);
// }

// bigint bigint::operator>>(unsigned int n)const
// {
// 	bigint temp = *this;
// 	size_t len = temp.str.length();
// 	if(n >= len)
// 		temp.str = "0";
// 	else
// 	{
// 		temp.str.erase(temp.str.length() - n, n); // ilk parametre: silme yapacağın yerin başlangıç indexi, diğeri: kaç tane eleman silinecek
// 	}
// 	return(temp);
// }

// bigint& bigint::operator<<=(unsigned int n)
// {
// 	(*this) = (*this) << n;
// 	return(*this);
// }

// bigint& bigint::operator>>=(unsigned int n)
// {
// 	(*this) = (*this) >> n;
// 	return(*this);
// }

// unsigned int stringToUINT(std::string str)
// {
// 	std::stringstream ss(str);
// 	unsigned int res;
// 	ss >> res;
// 	return (res);
// }

// bigint bigint::operator<<(const bigint& other)const
// {
// 	bigint temp;
// 	temp = (*this) << stringToUINT(other.str);
// 	return(temp);
// }

// bigint bigint::operator>>(const bigint& other)const
// {
// 	bigint temp;
// 	temp = (*this) >> stringToUINT(other.str);
// 	return(temp);
// }

// bigint& bigint::operator<<=(const bigint& other)
// {
// 	(*this) = (*this) << stringToUINT(other.str);
// 	return(*this);
// }

// bigint& bigint::operator>>=(const bigint& other)
// {
// 	(*this) = (*this) >> stringToUINT(other.str);
// 	return(*this);
// }


// bool bigint::operator==(const bigint& other) const
// {
// 	if(this->getStr() == other.getStr())
// 		return(true);
// 	return(false);
// }

// bool bigint::operator!=(const bigint& other) const
// {
// 	return(!((*this) == (other)));
// }

// bool bigint::operator<(const bigint& other) const
// {
// 	std::string str1 = this->str;
// 	std::string str2 = other.getStr();
// 	size_t len1 = str1.length();
// 	size_t len2 = str2.length();

// 	if(len1 != len2)
// 		return(len1 < len2);
// 	return(str1 < str2);  // thanks for your feedback, mjuicha!! o7
// }

// bool bigint::operator>(const bigint& other) const
// {
// 	return(!(((*this) < other)));
// }

// bool bigint::operator<=(const bigint& other) const
// {
// 	return((((*this) < other) || ((*this) == other)));
// }

// bool bigint::operator>=(const bigint& other) const
// {
// 	return((((*this) > other) || ((*this) == other)));
// }

// // non member func
// std::ostream& operator<<(std::ostream& output, const bigint& obj)
// {
// 	output << obj.getStr();
// 	return(output);
// }


// ------------------------------------------------------------
// ---------------- C version ---------------------------------
// ------------------------------------------------------------


#include "bigint.hpp"

bigint::bigint(unsigned int n){
	if (!n)
		s = "0";
	while (n){
		s.insert(s.begin(), char('0' + n % 10));
		n /= 10;
	}
}
bigint::bigint(const bigint &o) : s(o.s) {}
bigint::~bigint() {}

const std::string &bigint::str() const { return s; }
bigint &bigint::operator=(const bigint &o){
	s = o.s;
	return *this;
}
//add
bigint bigint::operator+(const bigint &o) const{
	bigint r(*this);
	return r += o;
}

bigint &bigint::operator+=(const bigint &o){
	std::string r;
	int i = s.size() - 1;
	int j = o.s.size() - 1;
	int c = 0;
	while (i >= 0 || j >= 0 || c){
		int a = i >= 0 ? s[i--] - '0' : 0;
		int b = j >= 0 ? o.s[j--] - '0' : 0;
		r.insert(r.begin(), char('0' + (a + b + c) % 10));
		c = (a + b + c) / 10;
	}
	s = r;
	return *this;
}
//incr
bigint bigint::operator++(int){
	bigint r(*this);
	++*this;
	return r;
}

bigint &bigint::operator++() { return *this += 1; }
//shift
bigint bigint::operator<<(const bigint &o) const{
	bigint r(*this);
	return r <<= o;
}

bigint &bigint::operator<<=(const bigint &o){
	unsigned long n = 0;
	for (size_t i = 0; i < o.s.size(); ++i)
		n = n * 10 + o.s[i] - '0';
	if (s != "0")
		s.append(n, '0');
	return *this;
}
//with obj
bigint bigint::operator>>(const bigint &o) const{
	bigint r(*this);
	return r >>= o;
}

bigint &bigint::operator>>=(const bigint &o){
	unsigned long n = 0;
	for (size_t i = 0; i < o.s.size(); ++i){
		n = n * 10 + o.s[i] - '0';
		if (n >= s.size()){
			s = "0";
			return *this;
		}
	}
	s.erase(s.size() - n);
	if (s.empty())
		s = "0";
	return *this;
}
//bool
bool bigint::operator<(const bigint &o) const { return s.size() == o.s.size() ? s < o.s : s.size() < o.s.size(); }
bool bigint::operator<=(const bigint &o) const { return !(o < *this); }
bool bigint::operator>(const bigint &o) const { return o < *this; }
bool bigint::operator>=(const bigint &o) const { return !(*this < o); }
bool bigint::operator==(const bigint &o) const { return s == o.s; }
bool bigint::operator!=(const bigint &o) const { return s != o.s; }

std::ostream &operator<<(std::ostream &os, const bigint &n) { return os << n.str(); }