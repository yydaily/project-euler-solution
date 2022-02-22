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
const long long e2 = 100;
const long long e3 = e2*10;
const long long e4 = e3*10;
const long long e5 = e4*10;
const long long e6 = e4*e2;
const long long e7 = e6*10;
const long long e8 = e7*10;
const long long mod = 1e9+7;
using namespace std;/*}}}*/

/*add{{{*/
long long base_add(long long a, long long b) {
	a %= mod;
	b %= mod;
	return (a+b)%mod;
}
long long add(initializer_list<long long> args) {
	long long ret = 0;
	for(auto i : args) ret = base_add(ret, i);
	return ret;
}
/*}}}*/

/*{{{mul*/
long long base_mul(long long a, long long b) {
	a%=mod;
	b%=mod;
	long long ret = 0;
	while(b) {
		if(b&1) ret = (ret + a) % mod;
		b>>=1;
		a = (a+a)%mod;
	}
	return ret;
}
long long mul(initializer_list<long long> args) {
	long long ret = 1;
	for(auto i : args) ret = base_mul(ret, i);
	return ret;
}/*}}}*/

/*{{{qpow*/
long long qpow(long long a, long long b) {
	long long ret = 1;
	while(b) {
		if(b&1) ret = mul({ret, a});
		a = mul({a, a});
		b>>=1;
	}
	return ret;
} /*}}}*/
int main() {
	return 0;
}" > solution.cpp

# go
touch solution.go
echo "package main /*{{{*/

import (
	\"reflect\"
	\"fmt\"
)

const (
	e4 = int64(10000)
	e5 = int64(100000)
	e6 = int64(1000000)
	e7 = int64(10000000)
	e8 = e4*e4
	mod = int64(1e9+7)
) 

func add(list ...interface{}) int64 {/*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(0)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String(){
			case \"int\":
				buf = int64(i.(int))
			case \"int64\":
				buf = i.(int64)
		}
		ret = (ret + buf)%mod
	}
	return ret
}/*}}}*/
func mul(list ...interface{}) int64 {/*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(1)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String() {
			case \"int\":
				buf = int64(i.(int))
			case \"int64\":
				buf = i.(int64)
		}
		buf %= mod
		base := ret
		ret = 0
		for buf > 0 {
			if (buf&1) == 1 {
				ret = add(ret, base)
			}
			base = add(base, base)
			buf>>=1
		}
	}
	return ret
}/*}}}*/
func qpow(a, b int64) int64 {/*{{{*/
	ret := int64(1)
	for b > 0 {
		if (b&1) == 1 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b>>=1
	}
	return ret
}/*}}}*/
/*}}}*/

func main() {
	fmt.Printf(\"1\")
}" > solution.go

# py
touch solution.py
echo "from random import random
from math import *" > solution.py

# md
touch README.md
