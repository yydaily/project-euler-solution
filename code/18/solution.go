package main /*{{{*/

import (
	"fmt"
	"os"
	"reflect"
	"strconv"
	"strings"
)

const (
	e4  = int64(10000)
	e5  = int64(100000)
	e6  = int64(1000000)
	e7  = int64(10000000)
	e8  = e4 * e4
	mod = int64(1e9 + 7)
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

var num = [100][100]int64{}

func main() {
	content, err := os.ReadFile("./in")
	if err != nil {
		panic(err)
	}
	nums := strings.Split(string(content), "\n")
	ans := int64(0)
	length, _ := strconv.ParseInt(nums[0], 10, 64)
	for i := int64(0); i < length; i++ {
		number := strings.Split(nums[i+1], " ")
		for j := int64(0); j <= i; j++ {
			num[i][j], _ = strconv.ParseInt(number[j], 10, 64)
			if i > 0 {
				addition := num[i-1][j]
				if j > 0 && num[i-1][j-1] > addition {
					addition = num[i-1][j-1]
				}
				num[i][j] += addition
			}
			if num[i][j] > ans {
				ans = num[i][j]
			}
		}
	}
	fmt.Println(ans)
}
