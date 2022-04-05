#!/usr/bin/python
# -*- coding: UTF-8 -*-
import os

ans = {}
cnt_cpp = 0
cnt_py = 0
cnt_go = 0
cnt_pdf = 0


def init_ans():
    with open("./answer.md", "r") as f:
        anss = f.readlines()
    for a in anss:
        a = a[: len(a) - 1]
        if len(a) == 0:
            continue
        sa = a.split(":")
        if len(sa) != 2:
            print(sa, " size is not 2")
        ans[sa[0]] = sa[1]


def handle(path):
    global cnt_cpp, cnt_py, cnt_go, cnt_pdf
    if path not in ans:
        print(path, " has no ans")
        return 1 / 0
    all_file_in_dir = os.listdir("./code/" + path)
    read_me = ""
    cpp = ""
    go = ""
    py = ""
    pdf = ""
    for f in all_file_in_dir:
        if f[len(f) - 3 :] == ".md":
            read_me = f
        elif f[len(f) - 4 :] == ".cpp":
            cnt_cpp += 1
            cpp = f
        elif f[len(f) - 3 :] == ".go":
            cnt_go += 1
            go = f
        elif f[len(f) - 3 :] == ".py":
            cnt_py += 1
            py = f
        elif f[len(f) - 4 :] == ".pdf":
            cnt_pdf += 1
            pdf = f
    if len(read_me) == 0:
        print(path)
        return 1 / 0
    content = (
        "|["
        + str(path)
        + "](https://github.com/yydaily/project-euler-solution/tree/master/code/"
        + path
        + "/"
        + read_me
        + ")|"
    )
    if len(cpp) > 0:
        content += (
            "[c++](https://github.com/yydaily/project-euler-solution/tree/master/code/"
            + path
            + "/"
            + cpp
            + ")"
        )
    content += "|"
    if len(go) > 0:
        content += (
            "[go](https://github.com/yydaily/project-euler-solution/tree/master/code/"
            + path
            + "/"
            + go
            + ")"
        )
    content += "|"
    if len(py) > 0:
        content += (
            "[py](https://github.com/yydaily/project-euler-solution/tree/master/code/"
            + path
            + "/"
            + py
            + ")"
        )
    content += "|"
    if len(pdf) > 0:
        content += (
            "[pdf](https://github.com/yydaily/project-euler-solution/tree/master/code/"
            + path
            + "/"
            + pdf
            + ")"
        )
    content += "|"
    content += ans[path]
    content += "|"

    with open("./README.md", "a") as f:
        f.write(content + "\n")


def write_prefix(problem_cnt):
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

|Problem|c++|go|python|pdf|answer|
|:------:|:------:|:------:|:------:|:------:|:------:|
""".format(
                problem_cnt=problem_cnt
            )
        )


if __name__ == "__main__":
    init_ans()
    all_file_and_dir = os.listdir("./code")
    need_handle = []
    for f in all_file_and_dir:
        if os.path.isfile(f):  # filter file
            continue
        if f == "template":  # filter template
            continue
        if f == "gen.sh":  # filter gen.sh
            continue
        need_handle.append(int(f))
    cnt_prob = len(need_handle)
    write_prefix(cnt_prob)
    for f in sorted(need_handle):
        handle(str(f))
    print("Problem cnt=" + str(cnt_prob))
    print(
        "cpp file cnt="
        + str(cnt_cpp)
        + " rate="
        + str(cnt_cpp * 100.0 / cnt_prob)
        + "%"
    )
    print(
        "go file cnt=" + str(cnt_go) + " rate=" + str(cnt_go * 100.0 / cnt_prob) + "%"
    )
    print(
        "py file cnt=" + str(cnt_py) + " rate=" + str(cnt_py * 100.0 / cnt_prob) + "%"
    )
    print(
        "pdf file cnt="
        + str(cnt_pdf)
        + " rate="
        + str(cnt_pdf * 100.0 / cnt_prob)
        + "%"
    )
