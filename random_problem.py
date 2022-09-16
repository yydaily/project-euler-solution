from random import randrange
import os
import sys
import webbrowser

solved = {}
unsolved = {}
work_path = os.path.dirname(__file__)

def init():
	with open(work_path + "/answer.md", "r") as f:
		lines = f.readlines()
		for l in lines:
			if len(l) <= 2: continue
			solved[int(l.split(":")[0])] = True

def get_one():
	return randrange(1, 800)

def get_old():
	if not os.path.exists(work_path + "/unsolved"):
		return -1
	with open(work_path + "/unsolved", "r+") as f:
		lines = f.readlines()
		for l in lines:
			unsolved[int(l)] = True
		if len(lines) > 0:
			return int(lines[randrange(0, len(lines))])
	return -1

def get_an_unsolve():
	while True:
		if len(sys.argv) <= 2 or sys.argv[2] != 'new':
			id = get_old()
			if id not in solved and id > 0:
				return id
		id = get_one()
		if id in solved:
			continue
		return id

if __name__ == '__main__':
	init()
	id = str(get_an_unsolve())
	if id not in unsolved and len(sys.argv) > 2 and sys.argv[2] == 'new':
		with open(work_path + "/unsolved", "a+") as f:
			f.write(str(id) + '\n')
	webbrowser.open('https://projecteuler.net/problem=' + id)
	webbrowser.open('https://pe-cn.github.io/' + id)
