package main

import (
	"fmt"
)

var (
	upper = 75000000
	ans   = 0
	vis   = map[string]bool{}
)

func dfs(a, b, c int) {
	if a > b {
		a, b = b, a
	}
	if a > c {
		a, c = c, a
	}
	if b > c {
		b, c = c, b
	}
	if a+b+c > upper {
		return
	}
	s := fmt.Sprintf("%d %d %d", a, b, c)
	if vis[s] {
		return
	}
	vis[s] = true
	ans++
	dfs(2*c+b-2*a, 2*c+2*b-a, 3*c+2*b-2*a)
	dfs(2*c+b+2*a, 2*c+2*b+a, 3*c+2*b+2*a)
	dfs(2*c-2*b+a, 2*c-b+2*a, 3*c-2*b+2*a)
}

func main() {
	dfs(2, 2, 3)
	fmt.Println(ans)
}
