package main

import "fmt"
import "strconv"

var m = map[string]int64{}

func to_binary_string(a int) string {
	ret := ""
	for a > 0 {
		ret = strconv.Itoa(a%2) + ret
		a /= 2
	}
	return ret
}

func filter(s string, index int) string {
	ret := s[:index] + s[index+1:]
	for len(ret) > 0 && ret[0] == '0' {
		ret = ret[1:]
	}
	if len(ret) == 0 {
		ret = "0"
	}
	return ret
}

func check(n int) int64 {
	now := to_binary_string(n)
	if m[now] != 0 {
		return m[now]
	}

	for i := 0; i < len(now); i++ {
		nxt := filter(now, i)
		if m[nxt] == -1 {
			m[now] = 1
			return 1
		}
	}
	m[now] = -1
	return -1
}

var pow9 = [100]int64{}

func init() {
	pow9[0] = 1
	for i := 1; i < 100; i++ {
		pow9[i] = pow9[i-1] * 9
	}
}

func builtin_popcount(n int) int {
	ret := 0
	for n > 0 {
		ret += n & 1
		n >>= 1
	}
	return ret
}

func W(n int64) int64 {
	m["0"] = -1
	x := -1
	for n > 0 {
		x++
		n /= 10
	}

	ans := int64(0)
	for i := 1; i < (1 << x); i++ {
		if check(i) == 1 {
			ans += pow9[builtin_popcount(i)]
		}
	}
	return ans
}

func main() {
	fmt.Println(W(100))
	fmt.Println(W(10000))
	fmt.Println(W(10000 * 10000 * 10000 * 10000 * 100))
}
