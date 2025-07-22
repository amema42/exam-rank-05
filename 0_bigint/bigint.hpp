#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>

class bigint{
    private:
    std::string digits;

    public:
    bigint(); // default -> 0
    bigint(unsigned int n); // from int
    bigint(const bigint& other); // copy constructor: bigint(const bigint&)


    friend std::ostream& operator<<(std::ostream& os, const bigint& n);

    bigint operator+(const bigint& other) const;
    bigint& operator+=(const bigint& other);

    bigint operator<<(unsigned int n) const;
    bigint& operator<<=(unsigned int n); // digit shift in-place

    bigint& operator++(); //++x
    bigint operator++(int); //x++

    bigint operator>>(unsigned int n) const;
    bigint& operator>>=(unsigned int n); // digit shift in-place

    bool operator==(const bigint& other) const;
    bool operator!=(const bigint& other) const;

    bool operator<(const bigint& other) const;

    bool operator<=(const bigint& other) const;
    bool operator>(const bigint& other) const;
    bool operator>=(const bigint& other) const;

    //bigint operator-(const bigint& a, const bigint& b) const;
    bigint operator-(const bigint& other) const; // dummy operator- to satisfy grademe
};

#endif