package main

import "fmt"

var mod = int64(1e9)

func add(a, b int64) int64 {
	return (a + b) % mod
}

func mul(a, b int64) int64 {
	return a * b % mod
}

type matrix struct {
	num [][]int64
}

func newMatrix() matrix {
	ret := matrix{}
	ret.num = make([][]int64, 11)
	for i := 0; i < 11; i++ {
		ret.num[i] = make([]int64, 11)
	}
	return ret
}

func Mul(a, b matrix) matrix {
	ret := newMatrix()
	for i := 0; i < 11; i++ {
		for j := 0; j < 11; j++ {
			for k := 0; k < 11; k++ {
				ret.num[i][k] = add(ret.num[i][k], mul(a.num[i][j], b.num[j][k]))
			}
		}
	}
	return ret
}

func qpow(a matrix, b int64) matrix {
	ret := newMatrix()
	for i := 0; i < 11; i++ {
		ret.num[i][i] = 1
	}
	for b > 0 {
		if (b & 1) == 1 {
			ret = Mul(ret, a)
		}
		a = Mul(a, a)
		b >>= 1
	}
	return ret
}

func main() {
	base := newMatrix()
	num := [][]int64{
		{1, 0, 0, 2, 1, 0, 0, 1, 1, 7, mod - 2},
		{0, 0, 0, 1, 1, 0, 0, 0, 1, 1, mod - 1},
		{0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 1, 0, 0, 0, 1, 0, 6, mod - 1},
		{0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0},
		{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	}
	base.num = num
	power := int64(1e18)
	ret := qpow(base, power-4)
	ans := int64(0)
	ans = add(ans, mul(2, ret.num[0][0]))
	ans = add(ans, mul(2, ret.num[0][5]))
	ans = add(ans, ret.num[0][9])
	ans = add(ans, ret.num[0][10])
	fmt.Printf("%d\n", ans)
}
