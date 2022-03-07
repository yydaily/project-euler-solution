package main /*{{{*/

import (
	"fmt"
	"io/ioutil"
	"os"
	"reflect"
	"sort"
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

func check(num []int64) bool {
	m := map[int64]int64{}
	val := []int64{}
	for i := int64(0); i < (1 << len(num)); i++ {
		sum, cnt := int64(0), int64(0)
		for j := int64(0); j < int64(len(num)); j++ {
			if (i & (1 << j)) != 0 {
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
}
func main() {
	file, err := os.Open("./in")
	if err != nil {
		panic(err)
	}
	defer file.Close()
	content, err := ioutil.ReadAll(file)
	if err != nil {
		panic(err)
	}
	queries := strings.Split(string(content), "\n")
	ans := int64(0)
	for _, query := range queries {
		if len(query) <= 1 {
			continue
		}
		num := strings.Split(query, ",")
		ints := []int64{}
		for _, n := range num {
			x, err := strconv.ParseInt(n, 10, 64)
			if err != nil {
				panic(err)
			}
			ints = append(ints, x)
		}
		if check(ints) {
			for _, i := range ints {
				ans += i
			}
		}
	}
	fmt.Println(ans)
}
