package main

import "fmt"

var mod = int64(1307674368000)

func add(a int64, b int64) int64 {
	return (a + b) % mod
}

func mul(a int64, b int64) int64 {
	ret := int64(0)
	for b > 0 {
		if (b & 1) == 1 {
			ret = add(ret, a)
		}
		a = add(a, a)
		b >>= 1
	}
	return (ret + mod) % mod
}

type matrix struct {
	num [3][3]int64
}

func Mul(a matrix, b matrix) matrix {
	ret := matrix{num: [3][3]int64{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}}}
	for i := range a.num {
		for j := range a.num[i] {
			for k := range b.num {
				ret.num[i][k] = add(ret.num[i][k], mul(a.num[i][j], b.num[j][k]))
			}
		}
	}
	return ret
}

func qpow(a matrix, b int64) matrix {
	ret := matrix{num: [3][3]int64{{1, 0, 0}, {0, 1, 0}, {0, 0, 1}}}
	for b > 0 {
		if (b & 1) == 1 {
			ret = Mul(ret, a)
		}
		a = Mul(a, a)
		b >>= 1
	}
	return ret
}

func cal(n int64, x int64) int64 {
	n -= 2
	base := matrix{num: [3][3]int64{{1, x, mul(x, x)}, {0, x, mul(x, x)}, {0, 1, 0}}}
	r := matrix{num: [3][3]int64{{add(x, mul(x, x)), 0, 0}, {mul(x, x), 0, 0}, {x, 0, 0}}}
	return Mul(qpow(base, n), r).num[0][0]
}

func main() {
	ans := int64(0)
	n := int64(1)
	for i := 1; i <= 15; i++ {
		n *= 10
	}
	for i := 0; i <= 100; i++ {
		ans = add(ans, cal(n, int64(i)))
	}
	fmt.Printf("%d\n", ans)
}
