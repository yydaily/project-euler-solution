#include <vector>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
public:
    static const int BASE = 100000000;
    static const int WIDTH = 8;
    bool sign;
    size_t length;
    vector<int> num;

    void cutLeadingZero();
    void setLength();
	int to_int();

    BigInteger(int n = 0);
    BigInteger(long long n);
    BigInteger(const char *n);
    BigInteger(const BigInteger &n);

    const BigInteger& operator=(int n);
    const BigInteger& operator=(long long n);
    const BigInteger& operator=(const char *n);
    const BigInteger& operator=(const BigInteger &n);

    size_t size() const;
    BigInteger e(size_t n) const;
    BigInteger abs() const;

    const BigInteger& operator+() const;
    friend BigInteger operator+(const BigInteger &a, const BigInteger &b);
    const BigInteger& operator+=(const BigInteger &n);
    const BigInteger& operator++();
    BigInteger operator++(int);

    BigInteger operator-() const;
    friend BigInteger operator-(const BigInteger &a, const BigInteger &b);
    const BigInteger& operator-=(const BigInteger &n);
    const BigInteger& operator--();
    BigInteger operator--(int);

    friend BigInteger operator*(const BigInteger &a, const BigInteger &b);
    const BigInteger& operator*=(const BigInteger &n);

    friend BigInteger operator/(const BigInteger &a, const BigInteger &b);
    const BigInteger& operator/=(const BigInteger &n);

    friend BigInteger operator%(const BigInteger &a, const BigInteger &b);
    const BigInteger& operator%=(const BigInteger &n);

    friend bool operator<(const BigInteger &a, const BigInteger &b);
    friend bool operator<=(const BigInteger &a, const BigInteger &b);
    friend bool operator>(const BigInteger &a, const BigInteger &b);
    friend bool operator>=(const BigInteger &a, const BigInteger &b);
    friend bool operator==(const BigInteger &a, const BigInteger &b);
    friend bool operator!=(const BigInteger &a, const BigInteger &b);

    friend bool operator||(const BigInteger &a, const BigInteger &b);
    friend bool operator&&(const BigInteger &a, const BigInteger &b);
    bool operator!();

    friend ostream& operator<<(ostream &out, const BigInteger &n);
    friend istream& operator>>(istream &in, BigInteger &n);
};
