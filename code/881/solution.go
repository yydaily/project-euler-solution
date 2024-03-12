package main /*{{{*/

import (
	"fmt"
)

var (
	prime = [30]int64{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113}
	ans   = int64(6)
)

func gen(a int) map[int]int {
	ret := map[int]int{}
	for i := 0; i <= a; i++ {
		ret[i] = 1
	}
	return ret
}

func merge(a, b map[int]int) map[int]int {
	ret := map[int]int{}
	for k, v := range a {
		for k2, v2 := range b {
			ret[k+k2] += v * v2
		}
	}
	return ret
}

func cal(v []int) int {
	x := map[int]int{0: 1}
	for _, vv := range v {
		x = merge(x, gen(vv))
	}
	ret := 0
	for _, v := range x {
		if v > ret {
			ret = v
		}
	}
	return ret
}

func dfs(prime_index, max_cnt int, now int64, v []int) {
	if prime_index >= 15 {
		return
	}
	if cal(v) >= 10000 {
		if now < ans {
			ans = now
		}
		return
	}

	p := prime[prime_index]
	for i := 1; i <= max_cnt; i++ {
		if now > ans/p {
			return
		}
		now *= p
		v = append(v, i)
		dfs(prime_index+1, i, now, v)
		v = v[:len(v)-1]
	}
}

func main() {
	for i := 0; i < 15; i++ {
		ans *= prime[i]
	}
	dfs(0, 62, 1, []int{})
	fmt.Println(ans)
}
