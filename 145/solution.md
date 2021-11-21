---
title: project euler 145
date: 2021-04-26
author: "zuhiul"
tags:
  - project euler
---

## problems

Some positive integers $n$ have the property that the sum [ $n$ + reverse($n$) ] consists entirely of odd (decimal) digits. For instance, $36 + 63 = 99$ and $409 + 904 = 1313$. We will call such numbers reversible; so $36, 63, 409$, and $904$ are reversible. Leading zeroes are not allowed in either $n$ or reverse($n$).

There are $120$ reversible numbers below one-thousand.

How many reversible numbers are there below one-billion ($10^9$)?

## translation

有些正整数 $n$ 满足这样一种性质：将它的数字逆序排列后和本身相加所得到的和[ $n$ + reverse($n$) ]的十进制表示只包含有奇数数字。例如，$36 + 63 = 99$，$409 + 904 = 1313$。我们称这样的数是可逆的；因此 $36，63，409$ 和 $904$ 都是可逆的。无论是 $n$ 还是reverse($n$)都不允许出现前导 $0$。

在小于一千的数中，一共有 $120$ 个可逆数。

在小于十亿（$10^9$）的数中，一共有多少个可逆数？



## solution.cpp

```cpp
#include<bits/stdc++.h>
using namespace std;
int rev(unsigned int a) {
	unsigned int ret = 0;
	while(a>0) {
		ret = ret * 10 + a % 10;
		a/=10;
	}
	return ret;
}

int check(unsigned int a) {
	if(a%10==0) return 0;
	a += rev(a);
	while(a>0) {
		if(a % 2 == 0) return 0;
		a/=10;
	}
	return 1;
}

int main() {
	int upper = 1000 * 1000 * 100;
	int ans = 0;
	for(int i = 1;i<=upper;i+=2) if(check(i)) ans++;
	cout<<(ans<<1)<<endl;
	return 0;
}
```

## solution.go 
```go
package main

import "fmt"

func rev(a int) int {
	ret := 0
	for a > 0 {
		ret = ret * 10 + a % 10
		a /= 10
	}
	return ret
}

func check(a int) int {
	if a % 10 == 0 {
		return 0
	}
	a += rev(a)
	for a > 0 {
		if a % 2 == 0 {
			return 0
		}
		a /= 10
	}
	return 1
}

func main() {
	upper := 1000 * 1000 * 100
	ans := 0
	for i := 1 ;i<=upper; i+=2 {
		if check(i) == 1 {
			ans++
		}
	}
	fmt.Printf("%d\n", (ans<<1))
}
```

## solution.py
```py
def rev(a):
	ret = 0
	while a > 0 :
		ret = ret * 10 + a % 10
		a = int(a/10)
	return ret

def check(a):
	if a % 10 == 0:
		return 0
	a += rev(a)
	while a > 0 :
		if a % 2 == 0:
			return 0
		a = int(a/10)
	return 1

upper = 1000 * 1000 * 100
ans = 0
for i in range(1, upper, 2):
	if i % 1000000==0:
		print(i)
	if check(i) == 1:
		ans += 2
print(ans)
```
