package main

import "fmt"

var l = []int64{}
var ll = []int{}

func generate(num2, num3 int) { /*{{{*/
	if num2+num3 == 1 {
		a := int64(0)
		for _, i := range ll {
			a |= (int64(1) << i)
		}
		l = append(l, a)
		return
	}
	base := 0
	if len(ll) > 0 {
		base = ll[len(ll)-1]
	}
	if num2 > 0 {
		ll = append(ll, base+2)
		generate(num2-1, num3)
		ll = ll[:len(ll)-1]
	}
	if num3 > 0 {
		ll = append(ll, base+3)
		generate(num2, num3-1)
		ll = ll[:len(ll)-1]
	}
} /*}}}*/
var mat = [][]int{}

func gen(a []int64) []int64 { /*{{{*/
	ret := make([]int64, len(a))
	for i := 0; i < len(mat); i++ {
		for _, j := range mat[i] {
			ret[i] += a[j]
		}
	}
	return ret
} /*}}}*/
func main() {
	h := 10
	w := 32
	for i := w % 2; i*3 <= w; i += 2 {
		j := (w - i*3) / 2
		generate(j, i)
	}
	mat = make([][]int, len(l))
	for i := range l {
		for j := i + 1; j < len(l); j++ {
			if (l[i] & l[j]) == 0 {
				mat[i] = append(mat[i], j)
				mat[j] = append(mat[j], i)
			}
		}
	}
	ans := make([]int64, len(l))
	for i := 0; i < len(ans); i++ {
		ans[i] = 1
	}
	for i := 1; i < h; i++ {
		ans = gen(ans)
	}
	answer := int64(0)
	for _, i := range ans {
		answer += i
	}
	fmt.Printf("%d\n", answer)
}
