## The Ackermann function

For non-negative integers  $m,  n$, the Ackermann function  $A(m,n)$  is defined as follows: 

$$
A(m, n) = \left\{
\begin{aligned}
&n+1 && \text{if}\ m = 0\\
&A(m-1, 1) && \text{if} \ m > 0\ \text{and}\ n = 0\\
&A(m-1, A(m, n-1)) && \text{if} \ m>0 \ \text{and} \ n > 0
\end{aligned}
\right.
$$

For example  $A(1,0)=2,  A(2,2)=7$  and  $A(3,4)=125$.

Find  $\sum_{n=0}^6A(n,n)$  and give your answer mod  $14^8$.
