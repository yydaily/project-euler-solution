## Bitwise-OR operations on random integers

Let $y_0, y_1, y_2$,... be a sequence of random unsigned $32$ bit integers
(i.e. $0 ≤ y_i < 2^{32}$, every value equally likely).

For the sequence xi the following recursion is given:

- $x_0 = 0$ and

- $x_i = x_{i-1}| y_{i-1}$, for $i > 0$. ( $|$ is the bitwise-OR operator)

It can be seen that eventually there will be an index $N$ such that $x_i = 2^{32}-1$ (a bit-pattern of all ones) for all $i ≥ N$.

Find the expected value of $N$.
Give your answer rounded to $10$ digits after the decimal point.
