package main /*{{{*/

import (
	"fmt"
	"reflect"
	"sync"
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

var prime = []int64{}

func init() { /*{{{*/
	prime = append(prime, 2)
	for i := int64(3); i < 2e6; i += 2 {
		isPrime := true
		for _, j := range prime {
			if j*j > i {
				break
			}
			if i%j == 0 {
				isPrime = false
				break
			}
		}
		if isPrime {
			prime = append(prime, i)
		}
	}
} /*}}}*/

func cal(b int64) int64 {
	max_prime := int64(-1)
	for _, i := range prime {
		if i*i > b {
			break
		}
		if b%i == 0 {
			b /= i
			if i > max_prime {
				max_prime = i
			}
			for b%i == 0 {
				b /= i
			}
		}
	}
	if b > max_prime {
		max_prime = b
	}
	return max_prime
}
func Cal(a int64) int64 {
	ret := int64(0)
	for i := a; i <= 2000000; i += 10 {
		ans1 := cal(i + 1)
		ans2 := cal(i*i - i + 1)
		if ans1 > ans2 {
			ret += ans1
		} else {
			ret += ans2
		}
		ret--
	}
	return ret
}
func main() {
	ans := int64(0)
	wg := sync.WaitGroup{}
	ch := make(chan int64, 10)
	wg.Add(10)
	for i := int64(1); i <= 10; i++ {
		go func(a int64) {
			defer wg.Done()
			ch <- Cal(a)
		}(i)
	}
	wg.Wait()
	close(ch)
	for num := range ch {
		ans += num
	}
	fmt.Println(ans)
}
