package main

import (
	"fmt"
)

const (
	upper = int64(2500)
	mod   = int64(50515093)
)

var (
	x     = [upper]int64{}
	y     = [upper]int64{}
	start = int64(290797)
	edges = map[int64][][2]int64{}
)

func Gen() int64 {
	start = (start * start) % mod
	return (start % 2000) - 1000
}

func gcd(a, b int64) int64 {
	if a == 0 {
		return b
	}
	return gcd(b%a, a)
}

func gen(ind1, ind2 int64) {
	dirx := x[ind1] - x[ind2]
	diry := y[ind1] - y[ind2]
	if dirx < 0 {
		dirx, diry = -dirx, -diry
	}
	if dirx == 0 && diry < 0 {
		diry = -diry
	}
	g := gcd(dirx, abs(diry))
	dirx /= g
	diry /= g
	index := dirx*10000 + (diry + 3000)
	poi := [2]int64{x[ind1], y[ind1]}
	edges[index] = append(edges[index], poi)
}

var a = []int64{}
var sum_a = int64(0)

func handle() {
	for k, v := range edges {
		dirx := k / 10000
		diry := k - dirx*10000 - 3000
		edge_cnt := int64(0)
		for i := range v {
			unique := true
			for j := i + 1; j < len(v); j++ {
				if diry*(v[j][0]-v[i][0]) == dirx*(v[j][1]-v[i][1]) {
					unique = false
					break
				}
			}
			if unique {
				edge_cnt++
			}
		}
		sum_a += edge_cnt
		a = append(a, edge_cnt)
	}
	ans := int64(0)
	fmt.Printf("%d\n", sum_a)
	for _, i := range a {
		ans += (sum_a - i) * i
	}
	fmt.Printf("%d\n", ans)
}

func main() {
	for i := int64(0); i < upper; i++ {
		x[i] = Gen()
		y[i] = Gen()
	}
	for i := int64(0); i < upper; i++ {
		for j := i + 1; j < upper; j++ {
			gen(i, j)
		}
	}
	handle()
}

func abs(a int64) int64 {
	if a < 0 {
		return -a
	}
	return a
}
