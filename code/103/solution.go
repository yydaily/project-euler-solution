package main /*{{{*/

import (
	"fmt"
	"reflect"
	"sort"
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
		ret = (buf % mod * ret) % mod
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

const length = int64(7)

func check(length int64, num []int64) bool { /*{{{*/
	m := map[int64]int64{}
	val := []int64{}
	for i := int64(1); i < (1 << length); i++ {
		sum := int64(0)
		cnt := int64(0)
		for j := int64(0); j < length; j++ {
			if (i & (1 << j)) > 0 {
				sum += num[j]
				cnt++
			}
		}
		if m[sum] > 0 {
			return false
		}
		val = append(val, sum)
		m[sum] = cnt
	}
	sort.Slice(val, func(i, j int) bool {
		return val[i] < val[j]
	})
	for i := 1; i < len(val); i++ {
		if m[val[i]] < m[val[i-1]] {
			return false
		}
	}
	return true
} /*}}}*/

var closeAll = false

func dfs(l, remain, minm int64, num []int64) { /*{{{*/
	maxm := remain / l
	if l == 1 {
		num[length-1] = remain
		if check(length, num) {
			for i := int64(0); i < length; i++ {
				fmt.Printf("%d ", num[i])
			}
			fmt.Printf("\n")
			closeAll = true
			return
		}
		return
	}
	for i := minm; i <= maxm; i++ {
		num[length-l] = i
		if !check(length-l+1, num) {
			continue
		}
		dfs(l-1, remain-i, i, num)
	}
	return
} /*}}}*/

func main() {
	num := []int64{}
	for i := int64(0); i < length; i++ {
		num = append(num, 0)
	}
	for i := int64(1); !closeAll; i++ {
		dfs(length, i, 1, num)
	}
}
