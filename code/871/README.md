## Drifting Subsets

Let $f$ be a function from a finite set $S$ to itself. A drifting subset for $f$ is a subset $A$ of $S$ such that the number of elements in the union $A\cup f(A)$ is equal to twice the number of elements of $A$.

We write $D(f)$ for the maximal number of elements among all drifting subsets for $f$.

For a positive integer $n$, define $f_n$ as the function from $\{0,1,\dots,n-1\}$ to itself sending $x$ to $x^3+x+1 \bmod n$.

You are given $D(f_5)=1$ and $D(f_{10})=3$.

Find $\sum_{i=1}^{100} D(f_{10^5}+i)$.
