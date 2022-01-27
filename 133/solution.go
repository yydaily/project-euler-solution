package main

import "fmt"

var (
	remind = int64(0)
	base   = int64(0)
	mod    = int64(0)
	flag   = [123456]bool{}
	prime  = [123456]bool{}
)

func Init(mod_ int64) {
	remind = 1
	base = 10
	mod = mod_
}

func gen() int64 {
	basic := remind
	for i := 1; i < 10; i++ {
		remind = (remind*base + basic) % mod
	}
	basic = base
	for i := 1; i < 10; i++ {
		base = base * basic % mod
	}
	return remind
}

func handle(a int64) bool {
	Init(a)
	for i := int64(0); i < a; i++ {
		flag[i] = false
	}
	for i := 0; ; i++ {
		if remind == 0 {
			return true
		}
		if flag[remind] {
			return false
		}
		flag[remind] = true
		gen()
	}
}

func main() {
	sum := int64(0)
	for i := int64(2); i < 100000; i++ {
		if !prime[i] {
			if !handle(i) {
				sum += i
			}
			for j := i << 1; j < 100000; j += i {
				prime[j] = true
			}
		}
	}
	fmt.Printf("%d\n", sum)
}
