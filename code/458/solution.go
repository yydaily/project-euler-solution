package main /*{{{*/

import (
	"fmt"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	e9  = e8 * 10
	mod = e9
)

type matrix struct {
	num [7][7]int64
}

func mul(a, b matrix) matrix {
	ret := matrix{}
	ret.num = [7][7]int64{}
	for i := 0; i < 7; i++ {
		for j := 0; j < 7; j++ {
			for k := 0; k < 7; k++ {
				ret.num[i][k] = (ret.num[i][k] + a.num[i][j]*b.num[j][k]) % mod
			}
		}
	}
	return ret
}

func qpow(a matrix, b int64) matrix {
	ret := matrix{num: [7][7]int64{}}
	for i := range ret.num {
		ret.num[i][i] = 1
	}
	for b > 0 {
		if b%2 == 1 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
}

func solve(a int64) int64 {
	start := matrix{num: [7][7]int64{}}
	start.num[0][1] = 7
	for i := 1; i < 7; i++ {
		for j := 1; j <= 6; j++ {
			if j > i+1 {
				break
			}
			start.num[i][j] = 1
			if j == i+1 {
				start.num[i][j] = int64(7 - i)
			}
		}
	}
	start = qpow(start, a)
	ans := int64(0)
	for i := 1; i < 7; i++ {
		ans = (ans + start.num[0][i]) % mod
	}
	return ans
}

func main() {
	fmt.Println(solve(e6 * e6))
}
