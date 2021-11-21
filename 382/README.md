A **polygon** is a flat shape consisting of straight line segments that are joined to form a closed chain or circuit. A polygon consists of at least three sides and does not self-intersect.

A set S of positive numbers is said to *generate a polygon* P if:

- no two sides of P are the same length,
- the length of every side of P is in S, and
- S contains no other value.

For example:
The set {$3, 4, 5$} generates a polygon with sides $3, 4$, and $5$ (a triangle).
The set {$6, 9, 11, 24$} generates a polygon with sides $6, 9, 11$, and $24$ (a quadrilateral).
The sets {$1, 2, 3$} and {$2, 3, 4, 9$} do not generate any polygon at all.

Consider the sequence s, defined as follows:

- $s_1 = 1, s_2 = 2, s_3 = 3$
- $s_n = s_{n-1} + s_{n-3}$ for $n > 3$.

Let Un be the set {$s_1, s_2, \dots, s_n$}. For example, $U_{10}$ = {$1, 2, 3, 4, 6, 9, 13, 19, 28, 41$}.
Let $f(n)$ be the number of subsets of $U_n$ which generate at least one polygon.
For example, $f(5) = 7, f(10) = 501$ and $f(25) = 18635853$.

Find the last $9$ digits of $f(10^{18})$.

