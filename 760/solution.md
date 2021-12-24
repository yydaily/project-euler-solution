---
title: project euler 760
date: 2021-07-01
author: "zuhiul"
tags:
  - project euler
---

## problems

Define

$$g(m, n)=(m \oplus n)+(m \vee n)+(m \wedge n)$$

where $\oplus, \vee, \wedge$ are the bitwise XOR, OR and AND operator respectively.

Also set
$$
G(N)=\sum_{n=0}^{N} \sum_{k=0}^{n} g(k, n-k)
$$

For example, $G(10)=754$ and $G(10^{2})=583766$.

Find $G\left(10^{18}\right)$. Give your answer modulo $1\ 000\ 000\ 007$.

## translation

定义

$$g(m, n)=(m \oplus n)+(m \vee n)+(m \wedge n)$$

其中 $\oplus, \vee, \wedge$ 是二进制的 异或，或，与等操作。

并且定义
$$
G(N)=\sum_{n=0}^{N} \sum_{k=0}^{n} g(k, n-k)
$$

例如，$G(10)=754$ 并且 $G(10^{2})=583766$。

求 $G\left(10^{18}\right)$. 并将答案对 $1\ 000\ 000\ 007$ 取模。

## solution.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long add(long long a, long long b) {a%=mod;b%=mod;return (a+b+mod) % mod;}
long long mul(long long a, long long b) {a%=mod;b%=mod;return a*b%mod;}
long long qpow(long long a, long long b) {/*{{{*/
	long long ret = 1;
	while(b) {
		if(b&1) ret = mul(ret, a);
		a = mul(a, a);
		b>>=1;
	}
	return ret;
}/*}}}*/
const long long upper = 1e18;
long long check(long long a, long long ind) {/*{{{*/
	return ind%(a*2) >= a ? 1 : 0;
}/*}}}*/
long long cal0(long long a, long long u) {
	u++;
	auto ans1 = u/(a*2)*a;
	auto ans2 = min(a, u%(a*2));
	return ans1+ans2;
}
long long cal(__int128 a) {
	__int128 r = cal0(a, upper);
	__int128 l = cal0(a, upper-a+1);
	__int128 first_num0 = 0;
	if(cal0(a, upper) == cal0(a, upper-1)) {
		first_num0 = r*a;
		r-=l;
		first_num0 -= r*(r+1) / 2;
	} else {
		first_num0 = l*a;
		r-=l;
		first_num0 += r*(r+1) / 2;
	}
	assert(first_num0>0);
	long long num0 = mul(mul(first_num0/a/a + 1, add(first_num0%mod, first_num0%(a*a)%mod)), qpow(2, mod-2));
	long long num1 = mul(upper+1, mul(upper+2, qpow(2, mod-2)));
	return mul(add(num1, -num0), mul(a, 2));
}
int main() {
	long long ans = 0;
	for(long long i = 1;i<=upper;i*=2) {
		ans = add(ans, cal(i));
	}
	cout<<ans<<endl;
	return 0;
}

```

