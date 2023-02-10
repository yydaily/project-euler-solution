package main /*{{{*/

import (
	"fmt"
)

const (
	mod = int64(1008691207)
	e8  = int64(1e8)
)

func cal(a int64) int64 {
	fac := int64(1)
	ans1 := int64(1)
	ans2 := int64(0)
	for i := int64(1); i < a; i++ {
		ans2 = (ans2 + fac*(a-i)) % mod
		fac = fac * i % mod
		ans1 = (ans1 + fac*2) % mod
	}
	return ((fac*a-ans1+ans2)%mod + mod) % mod
}

func main() {
	fmt.Println(cal(3))
	fmt.Println(cal(5))
	fmt.Println(cal(e8))
}
