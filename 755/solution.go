package main

import "fmt"

var num = [100]int64{}
var sum = [100]int64{}

func init() {
	num[1] = 1
	sum[1] = 1
	num[2] = 2
	sum[2] = 3
	for i := 3; i < 63; i++ {
		num[i] = num[i-1] + num[i-2]
		sum[i] = sum[i-1] + num[i]
	}
}

func gao(a int, upper int64) int64 {
	if upper >= sum[a] {
		return int64(1) << a
	}
	ret := gao(a-1, upper)
	if upper >= num[a] {
		ret += gao(a-1, upper-num[a])
	}
	return ret
}

func main() {
	fmt.Printf("%d\n", gao(62, int64(1000)*int64(100000)*int64(100000)))
}
