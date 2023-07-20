package main /*{{{*/

import (
	"fmt"
)

const len = 2e5 + 10

var (
	fac2 = [len]int{}
	fac5 = [len]int{}
)

func cal(a, base int) int {
	ret := 0
	for a%base == 0 {
		ret++
		a /= base
	}
	return ret
}

func init() {
	for i := 2; i < len; i++ {
		fac2[i] = fac2[i-1] + cal(i, 2)
		fac5[i] = fac5[i-1] + cal(i, 5)
	}
}

func C(a, b int, fac *[len]int) int {
	return fac[a] - fac[b] - fac[a-b]
}

func solve(upper, need2, need5 int) int64 {
	ans := int64(0)
	for i := 0; i <= upper; i++ {
		cnt2 := C(upper, i, &fac2)
		cnt5 := C(upper, i, &fac5)
		for j := 0; i+j <= upper; j++ {
			cnt22 := cnt2 + C(upper-i, j, &fac2)
			cnt55 := cnt5 + C(upper-i, j, &fac5)
			if cnt22 >= need2 && cnt55 >= need5 {
				ans++
			}
		}
	}
	return ans
}

func main() {
	fmt.Println(solve(200000, 12, 12))
}
