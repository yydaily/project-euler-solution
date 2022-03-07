package main

import "fmt"

var mod = int64(1000000)
var length = int64(100000)
var pp []int64
var asist []int64

func Init() {
	pp = make([]int64, length)
	asist = make([]int64, length<<1)
	for i := int64(0); i < length; i++ {
		asist[i<<1] = i * (i*3 - 1) / 2
		asist[i<<1|1] = i * (i*3 + 1) / 2
	}
}

func Init2() {
	pp[0], pp[1], pp[2] = 1, 1, 2
	for i := int64(3); i < length; i++ {
		k := 0
		flags := 0
		for j := 2; asist[j] <= i; j++ {
			flags = k & 2
			if flags == 0 {
				pp[i] = (pp[i] + pp[i-asist[j]] + mod) % mod
			} else {
				pp[i] = (pp[i] - pp[i-asist[j]] + mod) % mod
			}
			k++
			k &= 7
		}
	}
}

func main() {
	Init()
	Init2()
	for i := int64(1); i < length; i++ {
		fmt.Printf("%d %d\n", i, pp[i])
		if pp[i] == 0 {
			break
		}
	}
}
