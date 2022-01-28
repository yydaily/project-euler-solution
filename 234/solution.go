package main

import "fmt"

const upper = int64(999966663333)

var (
	p   = [1000010]bool{}
	cnt = int64(0)
	sum = int64(0)
)

func handle(pi, pj int64) {
	l := pi*pi + 1
	r := pj*pj - 1
	if r > upper {
		r = upper
	}
	if l > r {
		return
	}
	for i := l / pi * pi; i <= r; i += pi {
		if i < l || i%pj == 0 {
			continue
		}
		cnt++
		sum += i
	}
	for i := l / pj * pj; i <= r; i += pj {
		if i < l || i%pi == 0 {
			continue
		}
		cnt++
		sum += i
	}
}

func Handle() {
	last := int64(-1)
	for i := int64(2); i < 1000000; i++ {
		if !p[i] {
			if last != -1 {
				handle(last, i)
			}
			last = i
			for j := i << 1; j < 1000000; j += i {
				p[j] = true
			}
		}
	}
}

func main() {
	Handle()
	fmt.Printf("%d %d\n", cnt, sum)
}
