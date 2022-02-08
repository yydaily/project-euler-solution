# 判断参数
if [ $# == 0 ];then
	echo "not enough params"
	exit;
elif [ $# -gt 2 ]; then
	echo "too much params"
	exit;
fi

# 创建目录
if [ ! -d $1 ];then
	mkdir $1
fi

cd $1

# cpp
touch solution.cpp
echo "#include<iostream>/*{{{*/
#include<vector>
#include<set>
#include<math.h>
#include<map>
#include \"../template/bigint.cpp\"
const int e4 = 10000;
const int e8 = e4*e4;
const int mod = 1e9+7;
using namespace std;/*}}}*/

/*add{{{*/
template <typename T>
T base_add(T a, T b) {
	a %= mod;
	b %= mod;
	return (a+b)%mod;
}
template <typename T>
T add(const T &t) { return t; }
template <typename T, typename ... Args>
T add(const T &t, const Args&... args) { return base_add(t, add(args...)); }
/*}}}*/

/*{{{mul*/
template <typename T>
T base_mul(T a, T b) {
	a%=mod;
	b%=mod;
	T ret(0);
	while(b) {
		if(b&1) ret = (ret + a) % mod;
		b>>=1;
		a = (a+a)%mod;
	}
	return ret;
}
template <typename T>
T mul(const T &t) { return t; }
template <typename T, typename ... Args>
T mul(const T &t, const Args&... args) { return base_mul(t, mul(args...)); }
/*}}}*/

/*{{{qpow*/
template <typename T>
T qpow(T a, T b) {
	T ret(1);
	while(b) {
		if(b&1) ret = mul(ret, a);
		a = mul(a, a);
		b>>=1;
	}
	return ret;
}
/*}}}*/
int main() {
	return 0;
}" > solution.cpp

# go
touch solution.go
echo "package main /*{{{*/

import (
	\"fmt\"
)

const (
	e4 = int64(10000)
	e8 = e4*e4
	mod = 1e9+7
) /*}}}*/

func main() {
	fmt.Printf(\"1\")
}" > solution.go

# py
touch solution.py
echo "from random import random
from math import *" > solution.py

# md
touch README.md
