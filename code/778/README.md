## Freshman's Product

If $a, b$ are two nonnegative integers with decimal representations $a=(\dots a_2a_1a_0)$ and $b=(\dots b_2b_1b_0)$ respectively, then the *freshman's product* of $a$ and $b$, denoted $a \otimes b$, is the integer $c$ with decimal representation $c=(\dots c_2c_1c_0)$ such that $c_i$ is the last digit of $a_i\cdot b_i$.
For example, $234\otimes 765=480$.

Let $F(R,M)$ be the sum of $x_1\otimes\dots\otimes x_R$ for all sequences of integers $(x_1,\dots,x_R)$ with $0\le x_i\le M$.
For example, $F(2,7)=204$, and $F(23,76) \equiv 5870548 (\bmod\ 1\ 000\ 000\ 009)$.

Find $F(234567,765432)$, give your answer modulo $1\ 000\ 000\ 009$.
