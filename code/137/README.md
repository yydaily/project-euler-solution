## Fibonacci golden nuggets

Consider the infinite polynomial series $A_F(x) = xF_1 + x^2 F_2 + x^3 F_3 + \dots$, where $F_k$ is the $k$th term in the Fibonacci sequence: $1, 1, 2, 3, 5, 8, \dots$; that is, $F_k = F_{k-1} + F_{k-2}$, $F_1=1$ and $F_2=1$.

For this problem we shall be interested in values of $x$ for which $A_F(x)$ is a positive integer.

Surprisingly,

$$
\begin{aligned}
A_F\big(\frac{1}{2}\big) &= \big(\frac{1}{2}\big)\times 1 + \big(\frac{1}{2}\big)^2\times 1 + \big(\frac{1}{2}\big)^3\times 2 + \big(\frac{1}{2}\big)^4 \times 3 + \big(\frac{1}{2}\big)^5\times 5+ \dots\\
&= \frac{1}{2} + \frac{1}{4} + \frac{2}{8} + \frac{3}{16} + \frac{5}{32} + \dots\\
&= 2
\end{aligned}
$$

The corresponding values of $x$ for the first five natural numbers are shown below.

| $x$                     | $A_F(x)$ |
| ----------------------- | -------- |
| $\sqrt{2}-1$            | 1        |
| $\frac{1}{2}$           | 2        |
| $\frac{\sqrt{13}-2}{3}$ | 3        |
| $\frac{\sqrt{89}-5}{8}$ | 4        |
| $\frac{\sqrt{34}-3}{5}$ | 5        |

We shall call $A_F(x)$ a golden nugget if $x$ is rational, because they become increasingly rarer; for example, the $10$th golden nugget is $74049690$.

Find the $15$th golden nugget.
