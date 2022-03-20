## Efficient exponentiation

The most naive way of computing $n^{15}$ requires fourteen multiplications:

$n × n × ... × n = n^{15}$

But using a "binary" method you can compute it in six multiplications:

$$
\begin{aligned}
n × n = n^{2}  
n^{2} × n^{2} = n^{4}  
n^{4} × n^{4} = n^{8}  
n^{8} × n^{4} = n^{12}  
n^{12} × n^{2} = n^{14}  
n^{14} × n = n^{15}
\end{aligned}
$$

However it is yet possible to compute it in only five multiplications:

n × n = n^{2}  
n^{2} × n = n^{3}  
n^{3} × n^{3} = n^{6}  
n^{6} × n^{6} = n^{12}  
n^{12} × n^{3} = n^{15}

We shall define $m(k)$ to be the minimum number of multiplications to compute nk; for example $m(15) = 5$.

For $1 ≤ k ≤ 200$, find $\sum m(k)$.
