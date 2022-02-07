package main

import "fmt"

const mod = int64(1e9 + 7)

func add(params ...int64) int64 { /*{{{*/
	ret := int64(0)
	for _, i := range params {
		ret = (ret + i) % mod
		ret = (ret + mod) % mod
	}
	return ret
} /*}}}*/
func mul(params ...int64) int64 { /*{{{*/
	ret := int64(1)
	for _, i := range params {
		ret = (ret * i) % mod
		ret = (ret + mod) % mod
	}
	return ret
} /*}}}*/
func qpow(a, b int64) int64 { /*{{{*/
	ret := int64(1)
	for b > 0 {
		if (b & 1) > 0 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
} /*}}}*/
func cal(n int64) int64 { /*{{{*/
	inv_81 := qpow(81, mod-2)
	base := mul(9, n, qpow(10, n))
	base = add(base, -qpow(10, n), 1)
	return mul(base, inv_81)
} /*}}}*/
func S(a int64) int64 { /*{{{*/
	cnt := a / 9
	m := a - cnt*9
	inv_9 := qpow(9, mod-2)
	inv_2 := qpow(2, mod-2)

	x := mul(add(qpow(10, cnt), -1), inv_9)
	ans := mul(45, x)
	ans = add(ans, mul(a, 9, x))
	ans = add(ans, -mul(81, cal(cnt)))
	ans = add(ans, mul(m, m+1, inv_2, qpow(10, cnt)))
	return ans
} /*}}}*/

func main() {
	a, b := int64(1), int64(1)
	ans := int64(0)
	for i := 2; i <= 90; i++ {
		ans = add(ans, S(b))
		a, b = b, a+b
	}
	fmt.Println(ans)
}
