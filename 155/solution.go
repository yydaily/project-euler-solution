package main
import "fmt"
const mod = int(1e9+7)
func cal_add(a, b int) int {
	return (a+b)%mod
}
func mul(a, b int) int {
	x := int64(a) * int64(b)
	return int(x%int64(mod))
}
func qpow(a, b int) int {
	ret := 1
	for b > 0 {
		if (b&1) != 0 {
			ret = mul(ret, a)
		}
		a = mul(a, a)
		b >>= 1
	}
	return ret
}
func cal(a, b int) int {
	return mul(mul(a, b), qpow(cal_add(a, b), mod-2))
}
var ans = [][]int{}
func add(a, x, y int) {
	for _, i := range ans[x] {
		for _, j := range ans[y] {
			ans[a] = append(ans[a], cal_add(i, j))
			ans[a] = append(ans[a], cal(i, j))
		}
	}
}
func unique(a []int) []int {
	m := map[int]bool{}
	ret := []int{}
	for _, v := range a {
		if acc, ok := m[v]; acc && ok {
			continue
		}
		ret = append(ret, v)
		m[v] = true
	}
	return ret
}
func show() {
	a := []int{}
	for i := 1;i<19;i++ {
		for _, j := range ans[i] {
			a = append(a, j)
			//add(i, j, i-j)
		}
		a = unique(a)
		//fmt.Printf("%d %d\n", i, a)
	}
	fmt.Printf("%d\n", len(a))
}
func main() {
	ans = make([][]int, 20)
	ans[1] = append(ans[1], 1)
	for i := 2;i<=18;i++ {
		for j := 1;j*2<=i;j++ {
			add(i, j, i-j)
		}
		ans[i] = unique(ans[i])
	}
	show()
}
