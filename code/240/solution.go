package main /*{{{*/

import (
	"fmt"
	"math"
	"reflect"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	e9  = e8 * 10
	mod = int64(1e9 + 7)
)

func sqrt(a int64) int64 {
	x := math.Sqrt(float64(a))
	return int64(x)
}

func add(list ...interface{}) int64 { /*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(0)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String() {
		case "int":
			buf = int64(i.(int))
		case "int64":
			buf = i.(int64)
		}
		ret = (ret + buf) % mod
	}
	return ret
} /*}}}*/
func mul(list ...interface{}) int64 { /*{{{*/
	if len(list) == 0 {
		return 0
	}
	ret := int64(1)
	for _, i := range list {
		buf := int64(0)
		switch reflect.TypeOf(i).String() {
		case "int":
			buf = int64(i.(int))
		case "int64":
			buf = i.(int64)
		}
		buf %= mod
		base := ret
		ret = 0
		for buf > 0 {
			if (buf & 1) == 1 {
				ret = add(ret, base)
			}
			base = add(base, base)
			buf >>= 1
		}
	}
	return ret
} /*}}}*/
func qpow(a, b int64) int64 { /*{{{*/
	ret := int64(1)
	for b > 0 {
		if (b & 1) == 1 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
} /*}}}*/
/*}}}*/

var (
	num        = [100]int64{}
	C          = [100][100]int64{}
	ans        = int64(0)
	a, b, c, d int64
)

func init() {
	for i := 0; i < 100; i++ {
		for j := 0; j <= i; j++ {
			if j == 0 {
				C[i][j] = 1
				continue
			}
			C[i][j] = C[i-1][j-1] + C[i-1][j]
		}
	}
}

func check() int64 {
	total, need_cnt, last, buf_ans := int64(0), c, a, int64(1)
	for i := b; i >= 1; i-- {
		total += i * min(need_cnt, num[i])
		need_cnt -= min(need_cnt, num[i])
		buf_ans *= C[last][num[i]]
		last -= num[i]
	}
	if total != d {
		return 0
	}
	return buf_ans
}

func dfs(a, b int64) {
	if b == 1 {
		num[b] = a
		ans += check()
		return
	}
	for i := int64(0); i <= a; i++ {
		num[b] = i
		dfs(a-i, b-1)
	}
}

func main() {
	a, b, c, d = 20, 12, 10, 70
	dfs(a, b)
	fmt.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
