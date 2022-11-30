package main /*{{{*/

import (
	"fmt"
	"sort"
)

const e6 = 1000 * 1000

var (
	ans   = [e6 + 10]int{}
	num   = []int{}
	cache = []int{}
	p     = [e6 + 10]bool{}
	prime = []int{}
)

func init() {
	for i := 2; i < e6; i++ {
		if !p[i] {
			prime = append(prime, i)
			for j := 2 * i; j < e6; j += i {
				p[j] = true
			}
		}
	}

	a := 1
	for a < e6 {
		b := a
		for b < e6 {
			if b == 1 {
				b = 3
				continue
			}
			num = append(num, b)
			b *= 3
		}
		a *= 2
	}
	sort.Slice(num, func(i, j int) bool {
		return num[i] < num[j]
	})
}

func dfs(now int, index int) {
	ans[now]++
	for i := index; i < len(num); i++ {
		if now+num[i] > e6 {
			break
		}
		can_add := true
		for _, j := range cache {
			if num[i]%j == 0 {
				can_add = false
				break
			}
		}
		if can_add {
			cache = append(cache, num[i])
			dfs(now+num[i], i+1)
			cache = cache[:len(cache)-1]
		}
	}
}

func main() {
	dfs(0, 0)
	rans := 0
	for _, i := range prime {
		if ans[i] == 1 {
			rans += i
		}
	}
	fmt.Println(rans)
}
