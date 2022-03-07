package main /*{{{*/

import (
	"encoding/json"
	"fmt"
	"reflect"
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

var upper = int64(0)
var min_prime = [e6 + 1]int64{}

func init() { /*{{{*/
	for i := int64(2); i <= e6; i++ {
		if min_prime[i] == 0 {
			for j := i; j <= e6; j += i {
				min_prime[j] = i
			}
		}
	}
} /*}}}*/
var m = map[string]bool{}

func gen(p []int64) string {
	s, _ := json.Marshal(p)
	return string(s)
}

func cal(v []int64) int64 { /*{{{*/
	if m[gen(v)] {
		return 0
	}
	m[gen(v)] = true

	base := int64(1)
	for _, i := range v {
		base *= i * i * i
	}
	base = upper / base
	if base == 0 {
		return 0
	}

	ret := int64(0)
	num := []int64{}
	num = append(num, 1)
	for true {
		nxt := []int64{}
		vis := map[int64]bool{}
		for _, i := range num {
			ret += base / i
			for _, j := range v {
				if i*j <= base && !vis[i*j] {
					vis[i*j] = true
					nxt = append(nxt, i*j)
				}
			}
		}
		num = []int64{}
		if len(nxt) == 0 {
			break
		}
		num = append(num, nxt[0])
		for _, i := range nxt {
			if i == num[len(num)-1] {
				continue
			}
			num = append(num, i)
		}
	}
	//fmt.Println("cal: ", v, ret)
	return ret
} /*}}}*/

func Cal(u int64) int64 {
	m = map[string]bool{}
	upper = u
	ans := upper
	for i := int64(2); i*i*i <= upper; i++ {
		v := []int64{}
		vis := map[int64]bool{}
		base := i
		for base != 1 {
			if !vis[min_prime[base]] {
				vis[min_prime[base]] = true
				v = append(v, min_prime[base])
			}
			base /= min_prime[base]
		}
		ans += cal(v)
	}
	return ans
}

func main() {
	fmt.Println(16, Cal(16))
	fmt.Println(100, Cal(100))
	fmt.Println(10000, Cal(10000))
	fmt.Println(1000000000000000000, Cal(1000000000000000000))
}
