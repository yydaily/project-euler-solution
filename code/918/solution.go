package main /*{{{*/

import (
	"fmt"
)

const siz = int64(3 * 10000 * 1000)

var cache = make([]int64, siz)

func a(n int64) int64 {
	if n < siz && cache[n] > 0 {
		return cache[n]
	}
	ret := int64(0)
	if n%2 == 1 {
		ret = a(n/2) - 3*a(n/2+1)
	} else {
		ret = 2 * a(n/2)
	}
	if n < siz {
		cache[n] = ret
	}
	return ret
}

func S(n int64) int64 {
	x := n / 2
	ret := int64(1)
	for x%2 == 0 {
		x /= 2
		ret *= 2
	}

	ret *= a(x)
	return 4 - ret
}

func main() {
	cache[1] = 1
	fmt.Println(S(10))
	fmt.Println(S(10000 * 10000 * 10000))
}
