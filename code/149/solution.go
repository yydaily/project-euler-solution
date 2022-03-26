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
	mod = e6
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

var nouse = [e6<<2 | 1]int64{}
var num = [2010][2010]int64{}
var ans = [4][2010][2010]int64{}

func main() {
	for i := int64(1); i <= e6*4; i++ {
		if i <= 55 {
			nouse[i] = (100003-200003*i+300007*i*i*i)%mod - 500000
			num[(i-1)/2000+1][(i-1)%2000+1] = nouse[i]
		} else {
			nouse[i] = (nouse[i-24]+nouse[i-55]+1000000)%mod - 500000
			num[(i-1)/2000+1][(i-1)%2000+1] = nouse[i]
		}
	}

	rans := int64(0)
	for i := 1; i <= 2000; i++ {
		for j := 1; j <= 2000; j++ {
			ans[0][i][j] = max(ans[0][i-1][j], 0) + num[i][j]
			ans[1][i][j] = max(ans[1][i][j-1], 0) + num[i][j]
			ans[2][i][j] = max(ans[2][i-1][j-1], 0) + num[i][j]
			rans = max(max(rans, ans[0][i][j]), max(ans[1][i][j], ans[2][i][j]))
		}
		for j := 2000; j >= 1; j-- {
			ans[3][i][j] = max(ans[3][i-1][j+1], 0) + num[i][j]
			rans = max(rans, ans[3][i][j])
		}
	}
	fmt.Println(rans)
}

func max(a, b int64) int64 {
	if a > b {
		return a
	}
	return b
}
