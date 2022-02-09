#!/usr/bin/python
# -*- coding: UTF-8 -*-
import os

ans = {}

def init_ans():
	with open("./answer.md", "r") as f:
		anss = f.readlines()
	for a in anss:
		a = a[:len(a)-1]
		if len(a) == 0:
			continue
		sa = a.split(":")
		if len(sa) != 2:
			print(sa, " size is not 2")
		ans[sa[0]] = sa[1]

def handle(path):
	if path not in ans:
		print(path, " has no ans")
		return 1/0
	all_file_in_dir = os.listdir("./" + path)
	read_me = ""
	cpp = ""
	go = ""
	py = ""
	for f in all_file_in_dir:
		if f[len(f)-3:] == ".md":
			read_me = f
		elif f[len(f)-4:] == ".cpp":
			cpp = f
		elif f[len(f)-3:] == ".go":
			go = f
		elif f[len(f)-3:] == ".py":
			py = f
	if len(read_me) == 0:
		print(path)
		return 1/0
	content = "|[" + str(path) + "](https://github.com/yydaily/project-euler-solution/blob/main/" + path + "/" + read_me + ")|"
	if len(cpp) > 0:
		content += "[c++](https://github.com/yydaily/project-euler-solution/blob/main/"+path+ "/" + cpp + ")"
	content += "|"
	if len(go) > 0:
		content += "[go](https://github.com/yydaily/project-euler-solution/blob/main/"+path+ "/" + go + ")"
	content += "|"
	if len(py) > 0:
		content += "[py](https://github.com/yydaily/project-euler-solution/blob/main/"+path+ "/" + py + ")"
	content += "|"
	content += ans[path]
	content += "|"

	with open("./README.md", "a") as f:
		f.write(content + "\n")


if __name__ == '__main__':
	init_ans()
	with open("./README.md", "w") as f:
		f.write('''
# Project Euler solutions


欧拉计划一些简单题的程序和答案。
我希望你能弄明白为什么是这样，而不是直接照搬答案。

some answer for easy problem in project euler.
I hope you can understand the principle instead of being a cheater.

プロジェクトオイラーのプログラムと簡単な質問への回答。
論理を理解していただければ幸いです，答えを直接コピーする代わりに。

|Problem|c++|go|python|answer|
|:------:|:------:|:------:|:------:|:------:|
''')

	all_file_and_dir = os.listdir(".")
	need_handle = []
	for f in all_file_and_dir:
		if os.path.isfile(f): # filter file
			continue
		if f == ".git": # filter git
			continue
		if f == "template": # filter template
			continue
		need_handle.append(int(f))
	for f in sorted(need_handle):
		handle(str(f))
