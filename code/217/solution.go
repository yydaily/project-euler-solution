package main /*{{{*/

import (
	"fmt"
	"reflect"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	e9  = e8 * 10
	mod = int64(14348907)
)

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
	num = [100]int64{}
	m   = map[int64]map[int64]int64{}
	m2  = map[int64]map[int64]int64{}
)

func cnt(len, sum int64, start bool) int64 { /*{{{*/
	if start && sum == 0 {
		return 0
	}
	if start && m[len][sum] > 0 {
		return m[len][sum]
	}
	if !start && m2[len][sum] > 0 {
		return m2[len][sum]
	}
	if len < 0 {
		return 0
	}
	if len == 0 && sum == 0 {
		return 1
	}
	if sum > 9*len {
		return 0
	}
	if sum == 0 {
		if start {
			return 0
		}
		return 1
	}
	v := int64(0)
	for i := int64(0); i <= 9; i++ {
		if start && i == 0 {
			i = 1
		}
		if i > sum {
			break
		}
		v = add(v, cnt(len-1, sum-i, false))
	}
	if start {
		if m[len] == nil {
			m[len] = map[int64]int64{}
		}
		m[len][sum] = v
	} else {
		if m2[len] == nil {
			m2[len] = map[int64]int64{}
		}
		m2[len][sum] = v
	}
	return v
} /*}}}*/
func cnt2(len, sum int64, start bool) int64 {
	if sum == 0 {
		return 1
	}
	if len == 0 {
		return 0
	}
	ret := int64(0)
	for i := int64(1); i <= len; i++ {
		ret = add(ret, cnt(i, sum, true))
	}
	return ret
}

func init() {
	num[0] = 1
	for i := 1; i < 100; i++ {
		num[i] = mul(num[i-1], 10)
	}
}

func pow10(a int64) int64 {
	return num[a]
}

func cal(len int64) int64 {
	sub_len := len / 2
	ret := int64(0)

	for i := int64(1); i <= sub_len*9; i++ {
		for j := int64(1); j <= sub_len; j++ {
			f := cnt2
			if j != 1 {
				f = cnt
			}
			for k := int64(1); k <= min(i, int64(9)); k++ {
				base1 := f(sub_len-1, i-k, true)
				base2 := 1
				if (len & 1) > 0 {
					base2 = 10
				}
				base3 := cnt2(sub_len, i, true)
				base4 := mul(k, pow10(sub_len+(len&1)+sub_len-j))
				ret = add(ret, mul(base1, base2, base3, base4))
			}
		}
	}

	if (len & 1) > 0 {
		for i := int64(1); i <= sub_len*9; i++ {
			for j := int64(1); j < 10; j++ {
				base1 := cnt(sub_len, i, true)
				base2 := cnt2(sub_len, i, true)
				ret = add(ret, mul(base1, base2, j, pow10(sub_len)))
			}
		}
	}

	for i := int64(1); i <= sub_len*9; i++ {
		for j := int64(1); j <= sub_len; j++ {
			for k := int64(1); k <= min(i, int64(9)); k++ {
				base1 := cnt(sub_len, i, true)
				base2 := cnt2(sub_len-1, i-k, true)
				base3 := 1
				if (len & 1) > 0 {
					base3 = 10
				}
				base4 := mul(k, pow10(j-1))
				ret = add(ret, mul(base1, base2, base3, base4))
			}
		}
	}
	return ret
}
func main() {
	ans := int64(45)
	for i := int64(2); i <= 47; i++ {
		ans = add(ans, cal(i))
	}
	fmt.Println(ans)
}

func min(a, b int64) int64 {
	if a < b {
		return a
	}
	return b
}
