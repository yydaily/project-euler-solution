package main

import (
	"fmt"
)

var (
	r = int64(5)
	c = int64(6)
)

type m struct {
	mat [][]int64
	val int128
}

func (x *m) getVal() int128 {
	x.val.lo = 0
	x.val.hi = 0
	base := int128{lo: 1, hi: 0}
	for i := int64(0); i < r; i++ {
		for j := int64(0); j < c; j++ {
			v := x.mat[i][j]
			if v == 0 {
			} else if v == 1 || v == 3 {
				x.val.add(base)
			} else if v == 2 || v == 8 {
				x.val.add(*base.mulInt64(2))
			} else if v == 4 {
				x.val.add(*base.mulInt64(3))
			} else if v == 5 || v == 6 {
				x.val.add(*base.mulInt64(4))
			} else if v == 7 {
				x.val.add(*base.mulInt64(5))
			} else {
				x.val.add(*base.mulInt64(6))
			}
			base.mulInt64(7)

		}
	}
	return x.val
}

func (x *m) show() {
	for i := int64(0); i < r; i++ {
		for j := int64(0); j < c; j++ {
			switch x.mat[i][j] {
			case 0:
				fmt.Printf("\033[47m  \033[0m")
			case 1, 3:
				fmt.Printf("\033[41m  \033[0m")
			case 2, 8:
				fmt.Printf("\033[42m  \033[0m")
			case 4:
				fmt.Printf("\033[44m  \033[0m")
			case 5, 6:
				fmt.Printf("\033[43m  \033[0m")
			case 7:
				fmt.Printf("\033[46m  \033[0m")
			default:
				fmt.Printf("\033[45m  \033[0m")
			}
		}
		fmt.Printf("\n")
	}
	fmt.Printf("\n")
}

func (x *m) Init() {
	x.mat = make([][]int64, r)
	for ind := range x.mat {
		x.mat[ind] = make([]int64, c)
	}
	x.mat[0][0] = 0
	x.mat[0][1] = 1
	x.mat[0][2] = 1
	x.mat[0][3] = 2
	x.mat[0][4] = 3
	x.mat[0][5] = 3
	x.mat[1][0] = 0
	x.mat[1][1] = 1
	x.mat[1][2] = 2
	x.mat[1][3] = 2
	x.mat[1][4] = 3
	x.mat[1][5] = 6
	x.mat[2][0] = 9
	x.mat[2][1] = 10
	x.mat[2][2] = 4
	x.mat[2][3] = 4
	x.mat[2][4] = 5
	x.mat[2][5] = 6
	x.mat[3][0] = 11
	x.mat[3][1] = 12
	x.mat[3][2] = 4
	x.mat[3][3] = 4
	x.mat[3][4] = 5
	x.mat[3][5] = 8
	x.mat[4][0] = 13
	x.mat[4][1] = 14
	x.mat[4][2] = 7
	x.mat[4][3] = 7
	x.mat[4][4] = 8
	x.mat[4][5] = 8

	x.getVal()
}

func cc(x m) m {
	ret := m{}
	ret.Init()
	for i := int64(0); i < r; i++ {
		for j := int64(0); j < c; j++ {
			ret.mat[i][j] = x.mat[i][j]
		}
	}
	ret.getVal()
	return ret
}

var x = map[int128]bool{}
var s = NewStack()

var dirx = []int64{1, -1, 0, 0}
var diry = []int64{0, 0, 1, -1}

func check(mat m, ind int64, dir int64) (checker bool) {
	for i := int64(0); i < r; i++ {
		for j := int64(0); j < c; j++ {
			if int64(mat.mat[i][j]) == ind {
				x := i + dirx[dir]
				y := j + diry[dir]
				if x < 0 || x >= r || y < 0 || y >= c {
					checker = false
					return
				}
				if mat.mat[x][y] != 0 && int64(mat.mat[x][y]) != ind {
					checker = false
					return
				}
			}
		}
	}
	checker = true
	return
}

func move(matt m, ind int64, dir int64) m {
	mat := cc(matt)
	type pair struct {
		first  int64
		second int64
	}
	remove := []pair{}
	add := []pair{}
	for i := int64(0); i < r; i++ {
		for j := int64(0); j < c; j++ {
			if int64(mat.mat[i][j]) == ind {
				remove = append(remove, pair{first: i, second: j})
				add = append(add, pair{first: i + dirx[dir], second: j + diry[dir]})
			}
		}
	}
	for i := 0; i < len(remove); i++ {
		mat.mat[remove[i].first][remove[i].second] = 0
	}
	for i := 0; i < len(add); i++ {
		mat.mat[add[i].first][add[i].second] = ind
	}
	return mat
}

func handle(a m) {
	for i := int64(1); i <= 14; i++ {
		for j := int64(0); j < 4; j++ {
			if check(a, i, j) {
				s.push(move(a, i, j))
			}
		}
	}
}

func main() {
	origin := m{}
	origin.Init()
	////origin = move(origin, 9, 1)
	////origin.show()

	////origin.show()
	////handle(origin)
	////for !s.empty() {
	////	x := s.pop()
	////	x.show()
	////}

	s.push(origin)
	for !s.empty() {
		handle(s.pop())
	}
	fmt.Printf("%d\n", len(x))
}

// ====================int128 package ====================
var mod = int64(1152921504606846976)

type int128 struct {
	lo int64
	hi int64
}

func (a *int128) addInt64(v int64) *int128 {
	a.lo += v
	a.hi += a.lo / mod
	a.lo %= mod
	return a
}

func (a *int128) add(v int128) *int128 {
	a.lo += v.lo
	a.hi += v.hi + a.lo/mod
	a.lo %= mod
	return a
}

func (a *int128) mulInt64(v int64) *int128 {
	c := int128{
		lo: 0,
		hi: 0,
	}
	for v > 0 {
		if v%2 != 0 {
			c.add(*a)
		}
		a.add(*a)
		v /= 2
	}
	a.lo, a.hi = c.lo, c.hi
	return a
}

// =====================stack package====================
type stack struct {
	item    []m
	itemCnt int64
}

func NewStack() *stack {
	ret := stack{}
	ret.item = make([]m, 3000000)
	ret.itemCnt = 0
	return &ret
}

func (s *stack) push(a m) {
	if vis, ok := x[a.getVal()]; vis && ok {
		return
	}
	x[a.getVal()] = true
	s.itemCnt++
	s.item[s.itemCnt] = a
}

func (s *stack) empty() bool {
	return s.itemCnt == 0
}

func (s *stack) pop() m {
	ret := s.item[s.itemCnt]
	s.itemCnt--
	return ret
}
