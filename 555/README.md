## McCarthy 91 function

The McCarthy 91 function is defined as follows:

$$

M_{91}(n) = \begin{cases}
n-10 & \text{if }n \gt 100\\
M_{91}(M_{91}(n+11)) & \text{if } 0\le n \le 100
\end{cases}
$$

We can generalize this definition by abstracting away the constants into new variables:

$$
M_{m,k,s}(n) = \begin{cases}
n-s & \text{if } n \gt m\\
M_{m,k,s}(M_{m,k,s}(n+k)) & \text{if } 0 \le n\le m
\end{cases}
$$

This way, we have $M_{91} = M_{100,11,10}$.

Let $F_{m,k,s}$ be the set of fixed points of $M_{m,k,s}$. That is,

$$
F_{m,k,s} = \{n \in \mathbb{N} | M_{m,k,s}(n) = n\}
$$

For example, the only fixed point of $M_{91}$ is $91$. In other words, $F_{100,11,10} = \{91\}$.

Now, define $SF(m,k,s)$ as the sum of the elements in $F_{m,k,s}$ and let $S(p,m) = \sum_{1\le s\lt k\le p}SF(m,k,s)$.

For example, $S(10,10)=225$ and $S(1000,1000) = 208724467$.

Find $S(10^6,10^6)$.
