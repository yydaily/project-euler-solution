package main /*{{{*/

import (
	"fmt"
)

var x = []int64{0, 1, 2, 3, 11, 12, 13, 21, 22, 23, 31, 32, 33, 111}

func C(a, b int64) int64 {
	ret := int64(1)
	for i := int64(1); i <= b; i++ {
		ret = ret * (a - b + i) / i
	}
	return ret
}

func cal2(a, b, c int64) int64 {
	return C(a+b+c, a) * C(b+c, b)
}

var v = [][]int64{}

func cal(length int64) int64 {
	ret := int64(0)
	v = [][]int64{}

	for i := 0; x[i] <= length; i++ {
		for j := 0; x[i]+x[j] <= length; j++ {
			for k := 0; x[i]+x[j]+x[k] <= length; k++ {
				if x[i]+x[j]+x[k] != length {
					continue
				}
				ret += cal2(x[i], x[j], x[k])
				buf := []int64{x[i], x[j], x[k]}
				v = append(v, buf)
			}
		}
	}
	return ret
}

func solve(index, length, mod int64) int64 {
	ret := int64(0)
	cnt := [3]int64{0, 0, 0}
	for i := int64(0); i < length; i++ {
		for j := int64(1); j <= 3; j++ {
			cnt[j-1]++
			solutions := int64(0)
			for _, a := range v {
				if a[0] < cnt[0] || a[1] < cnt[1] || a[2] < cnt[2] {
					continue
				}
				solutions += cal2(a[0]-cnt[0], a[1]-cnt[1], a[2]-cnt[2])
			}
			cnt[j-1]--

			if solutions < index {
				index -= solutions
			} else {
				cnt[j-1]++
				ret = (ret*10 + j) % mod
				break
			}
		}
	}
	return ret
}

func F(index, mod int64) int64 {
	if index <= 12 {
		return x[index]
	}
	index -= 12
	for length := int64(3); ; length++ {
		now := cal(length)
		if index > now {
			index -= now
			continue
		}
		return solve(index, length, mod)
	}
}

func main() {
	mod := int64(1000000000000037)
	fmt.Println(F(4, mod))
	fmt.Println(F(10, mod))
	fmt.Println(F(40, mod))
	fmt.Println(F(1000, mod))
	fmt.Println(F(6000, mod))
	fmt.Println(F(111111111111222333, 123123123))
}
