## Recursive Sequence Summation

The sequence $a_n$ is defined by $a_1=1$, and then recursively for $n>=1$:

$$
a_{2n} = 2a_n\\
a_{2n+1} = a_n - 3a_{n+1}
$$
 
The first ten terms are $1,2,-5,4,17,-10,-17,8,-47,34$.

Define $S(N) = \sum_{n=1}^N a_n$. You are given $S(10) = -13$

Find $S(10^{12})$.
