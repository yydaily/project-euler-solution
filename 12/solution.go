package main

import "fmt"

func cal(a int) int {
	cnt := 0
	for i := 1; i*i <= a; i++ {
		if a%i == 0 {
			cnt += 2
			if a/i == i {
				cnt--
			}
		}
	}
	return cnt
}

func main() {
	val := 1
	for i := 1; cal(val) <= 500; {
		i++
		val += i
	}
	fmt.Println(val)
}
