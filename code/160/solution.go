package main /*{{{*/

import (
	"fmt"
	"math"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	mod = int64(1e9 + 7)
)

func sqrt(a int64) int64 {
	x := math.Sqrt(float64(a))
	return int64(x)
}

/*}}}*/

const upper = int64(1e12)

func qpow(a, b int64) int64 { /*{{{*/
	ret := int64(1)
	for b > 0 {
		if (b & 1) > 0 {
			ret = ret * a % e5
		}
		a = a * a % e5
		b >>= 1
	}
	return ret
} /*}}}*/
func count(a, base int64) int64 { /*{{{*/
	ret := int64(0)
	for a > 0 {
		a /= base
		ret += a
	}
	return ret
} /*}}}*/
var cnt = [e5]int64{}

func main() {
	ans := int64(1)
	for a := int64(1); a <= upper; a <<= 1 {
		for b := int64(1); a*b <= upper; b *= 5 {
			x := upper / (a * b)
			for y := int64(1); y < e5; y += 2 {
				if y%5 == 0 {
					continue
				}
				cnt[y] += x / e5
				if x%e5 >= y {
					cnt[y]++
				}
			}
		}
	}
	for y := int64(1); y < e5; y++ {
		ans = ans * qpow(y, cnt[y]) % e5
	}
	ans = ans * qpow(2, count(upper, 2)-count(upper, 5)) % e5
	fmt.Println(ans)
}
