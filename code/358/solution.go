package main /*{{{*/

import (
	"fmt"
)

func check(a int64) (bool, int64) {
	ret := int64(0)
	for i := int64(2); i*i <= a; i++ {
		if a%i == 0 {
			return false, 0
		}
	}

	remind := int64(1)
	l := int64(0)
	for remind != 1 || l == 0 {
		l++
		ret += (remind * 10) / a
		remind = (remind * 10) % a
	}
	return l+1 == a, ret
}

func main() {
	_, v := check(7)
	fmt.Println(v)

	_, v = check(17)
	fmt.Println(v)

	for a := int64(724709891); a < int64(729909892); a += 100000 {
		ok, v := check(a)
		if ok {
			fmt.Println(v)
		}
	}
}
