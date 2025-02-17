package main

import "strconv"
import "fmt"

func check(x int64) bool {
	z := strconv.FormatInt(x*x, 10)
	if z[len(z)/2] == '0' {
		return false
	}
	a, b := int64(0), int64(0)
	for i := 0; i < len(z)/2; i++ {
		a = a*10 + int64(z[i]-'0')
	}
	for i := len(z) / 2; i < len(z); i++ {
		b = b*10 + int64(z[i]-'0')
	}
	return a+b == x
}

func main() {
	ans := int64(0)
	for i := int64(9); i < 1e8; i++ {
		if check(i) {
			ans += i * i
		}
	}
	fmt.Println(ans)
}
