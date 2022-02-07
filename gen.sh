# 判断参数
if [ $# == 0 ];then
	echo "not enough params"
	exit;
elif [ $# -gt 2 ]; then
	echo "too much params"
	exit;
fi

# 创建目录
if [ ! -d $1 ];then
	mkdir $1
fi

cd $1

# cpp
touch solution.cpp
echo "#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;
int main() {
	return 0;
}" > solution.cpp

# go
touch solution.go
echo "package main

import \"fmt\"

func main() {
	fmt.Printf(\"1\")
}" > solution.go

# py
touch solution.py
echo "from random import random
from math import *" > solution.py

# md
touch README.md
