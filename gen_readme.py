#!/usr/bin/python
# -*- coding: UTF-8 -*-
import os

ans = {}
cnt = [0, 0, 0, 0] # cpp, py, go , pdf

# 获取有答案的题目，全局变量ans会被初始化
def init_ans():
    with open("./answer.md", "r") as f:
        ans_list = f.readlines()
    for one_ans in ans_list:
        one_ans = one_ans[: len(one_ans) - 1] # 去掉最后的回车
        if len(one_ans) == 0: # 为空说明这个题目没有答案，直接过滤掉
            continue
        index_and_ans = one_ans.split(":") # 按照冒号分割成题号和答案
        if len(index_and_ans) != 2:
            print(index_and_ans, " size is not 2")
        ans[index_and_ans[0]] = index_and_ans[1]


# 处理一个code下的子文件夹，用于生成read_me
def handle(path):
    if path not in ans:
        print(path, " has no ans")
        return 1 / 0
    all_file_in_dir = os.listdir("./code/" + path)
    file_paths = ["", "", "", "", ""] # read_me, cpp, go, py, pdf

    def handle_suffix(file_name, suffix, index):
        global cnt
        if file_name.endswith(suffix):
            file_paths[index] = file_name
            if index > 0:
                cnt[index-1] += 1

    for f in all_file_in_dir:
        handle_suffix(f, ".md", 0)
        handle_suffix(f, ".cpp", 1)
        handle_suffix(f, ".go", 2)
        handle_suffix(f, ".py", 3)
        handle_suffix(f, ".pdf", 4)
    if len(file_paths[0]) == 0:
        print(path, " has no read_me")
        return 1 / 0

    def gen_content(show, file_name):
        if len(file_name) == 0:
            return "|"
        return "[" + show + "](https://github.com/yydaily/project-euler-solution/tree/master/code/" + path + "/" + file_name + ")|"
    content = "|"
    content += gen_content(str(path), file_paths[0])
    content += gen_content("c++", file_paths[0])
    content += gen_content("go", file_paths[0])
    content += gen_content("py", file_paths[0])
    content += gen_content("pdf", file_paths[0])
    content += ans[path]
    content += "|"

    return content


def write_prefix(problem_cnt):
    def gen_ans_table():
        max_cnt = 0
        for k in ans:
            max_cnt = max(max_cnt, int(k))
        ret = "<table>"
        for i in range(1, max_cnt+1):
            if i % 10 == 1:
                ret += "\t<tr>"

            color = "#AFAFAF"
            index = str(i)
            if str(i) in ans:
                color = "#30C705"
                index = "<a href=https://github.com/yydaily/project-euler-solution/tree/master/code/"+index+">"+index+"</a>"
            ret += "\t\t<td bgcolor=" + color + "><center>" + index + "</center></td>\n"

            if i % 10 == 0 or i == max_cnt:
                ret += "\t</tr>\n"
        ret += "</table>\n"
        return ret


    with open("./README.md", "w") as f:
        f.write(
            """
# Project Euler solutions ({problem_cnt} solutions)


欧拉计划一些简单题的程序和答案。
我希望你能弄明白为什么是这样，而不是直接照搬答案。

some answer for easy problem in project euler.
I hope you can understand the principle instead of being a cheater.

プロジェクトオイラーのプログラムと簡単な質問への回答。
論理を理解していただければ幸いです，答えを直接コピーする代わりに。

{ans_table}

|Problem|c++|go|python|pdf|answer|
|:------:|:------:|:------:|:------:|:------:|:------:|
""".format(
                ans_table=gen_ans_table(),
                problem_cnt=problem_cnt
            )
        )

def show_cnt(total_cnt):
    print("Problem cnt=" + str(total_cnt))
    name_list = ["cpp", "go", "py", "pdf"]
    for index in range(4):
        print name_list[index] + " file cnt=" + str(cnt[index]) + " rate=" + str(cnt[index] * 100.0 / total_cnt) + "%"

if __name__ == "__main__":
    init_ans()
    all_file_and_dir = os.listdir("./code")
    need_handle = []
    filter_files = ["template", "gen.sh"]
    for f in all_file_and_dir:
        if os.path.isfile(f) or f in filter_files:  # filter file
            continue
        need_handle.append(int(f))
    cnt_prob = len(need_handle)
    write_prefix(cnt_prob)
    content = ""
    for f in sorted(need_handle):
        content += handle(str(f))
    with open("./README.md", "a") as f:
        f.write(content + "\n")
    show_cnt(cnt_prob)
