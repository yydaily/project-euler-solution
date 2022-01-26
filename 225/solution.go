package main

import "fmt"

func check(a int) bool {
	t := [3]int{1, 1, 1}
	for true {
		tar := (t[0] + t[1] + t[2]) % a
		if tar == 0 {
			return false
		}
		t[0], t[1], t[2] = t[1], t[2], tar
		if t[0] == t[1] && t[1] == t[2] && t[2] == 1 {
			return true
		}
	}
	return true
}

func main() {
	cnt := 0
	for i := 27; ; i += 2 {
		if check(i) {
			cnt++
		}
		if cnt == 124 {
			fmt.Printf("%d\n", i)
			break
		}
	}
}
