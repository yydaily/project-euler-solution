from random import random
import os
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

def get_old():
	if not os.path.exists("./unsolved"):
		return -1
	with open("./unsolved", "r+") as f:
		lines = f.readlines()
		if len(lines) > 0:
			return int(lines[0])
	return -1

def get_an_unsolve():
	while True:
		id = get_old()
		if id not in solved and id > 0:
			return id
		if os.path.exists("./unsolved"):
			os.remove("./unsolved")
		id = get_one()
		if id in solved:
			continue
		return id

if __name__ == '__main__':
	init()
	id = str(get_an_unsolve())
	with open("./unsolved", "w+") as f:
		f.write(id)
	webbrowser.open('https://projecteuler.net/problem=' + id)
	webbrowser.open('https://pe-cn.github.io/' + id)
