## Searching a triangular array for a sub-triangle having minimum-sum

In a triangular array of positive and negative integers, we wish to find a sub-triangle such that the sum of the numbers it contains is the smallest possible.

In the example below, it can be easily verified that the marked triangle satisfies this condition having a sum of $−42$.

![](https://projecteuler.net/project/images/p150.gif)

We wish to make such a triangular array with one thousand rows, so we generate $500500$ pseudo-random numbers $s_k$ in the range $±2^{19}$, using a type of random number generator (known as a Linear Congruential Generator) as follows:

t := 0
for k = 1 up to k = 500500:
    t := (615949*t + 797807) modulo $2^{20}$
    $s_k$ := t - $2^{19}$

因此，$s_1 = 273519，s_2 = −153582，s_3 = 450905$，依此类推。

接下来就将这些伪随机数填入三角形数组：

$$
s_1\\
s_2\ \ s_3\\
s_4\ \ s_5\ \ s_6\\
s_7\ \ s_8\ \ s_9\ \ s_{10}\\
\cdots
$$

子三角形可以从数组中的任意元素开始，向下可以延伸至无限长（先取下一行的两个元素，再取接下来一行的三个元素，依此类推）。
“子三角形的和”被定义为其中所有元素的和。
求最小的子三角形的和。
