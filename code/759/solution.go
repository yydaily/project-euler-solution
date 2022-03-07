package main

import "fmt"

const mod = int64(1e9 + 7)

func add(a, b int64) int64 {
	return (a + b) % mod
}
func mul(a, b int64) int64 { /*{{{*/
	a %= mod
	b %= mod
	return a * b % mod
} /*}}}*/
var C [][]int64

func init() { /*{{{*/
	C = make([][]int64, 100)
	for i := range C {
		C[i] = make([]int64, 100)
	}
	for i := range C {
		C[i][0] = 1
		C[i][i] = 1
		for j := 1; j < i; j++ {
			C[i][j] = add(C[i-1][j-1], C[i-1][j])
		}
	}
} /*}}}*/
func cal2(x, a int64) int64 { /*{{{*/
	ret := int64(0)
	one := int64(1)
	for i := int64(0); i < x; i++ {
		for j := int64(0); j <= i; j++ {
			if i == j {
				ret = add(ret, mul(C[x-1][a-1], mul(one<<i, one<<i)))
			} else if a >= 2 {
				ret = add(ret, mul(mul(2, C[x-2][a-2]), mul(one<<i, one<<j)))
			}
		}
	}
	return ret
} /*}}}*/
func cal(x, a int64) int64 { /*{{{*/
	one := int64(1)
	return mul(C[x-1][a-1], add(one<<x, -1))
} /*}}}*/
func Sum(x, add_cnt, add_val int64) int64 {
	ans := mul(add_cnt, add_val)
	ans = mul(ans, ans)
	for i := int64(1); i <= x; i++ {
		base := mul(add_cnt+i, add_cnt+i)
		prefix := mul(mul(add_val, add_val), C[x][i])
		suffix := cal2(x, i)
		mid := mul(2, mul(add_val, cal(x, i)))
		ans = add(ans, mul(base, add(prefix, add(suffix, mid))))
	}
	return ans
}
func main() {
	upper := int64(10000)
	upper = upper * upper
	upper = upper * upper
	upper = upper + 1
	lower := int64(0)
	cnt := int64(0)
	ans := int64(0)
	one := int64(1)
	for upper != lower {
		diff := int64(0)
		for upper-lower >= (one << diff) {
			diff++
		}
		diff--
		ans = add(ans, Sum(diff, cnt, lower))
		cnt++
		lower += one << diff
	}
	fmt.Printf("%d\n", ans)
}
