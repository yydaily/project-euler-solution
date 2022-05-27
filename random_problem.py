from random import random
import webbrowser

solved = {}

def init():
	with open("./answer.md", "r") as f:
		lines = f.readlines()
		for l in lines:
			if len(l) <= 2: continue
			solved[int(l.split(":")[0])] = True

def get_one():
	return int(random()*800) + 1

def get_an_unsolve():
	while True:
		id = get_one()
		if id in solved:
			continue
		return id

if __name__ == '__main__':
	init()
	id = str(get_an_unsolve())
	webbrowser.open('https://projecteuler.net/problem=' + id)
	webbrowser.open('https://pe-cn.github.io/' + id)
