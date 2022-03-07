## Buckets of Water

There are $3$ buckets labelled $S$ (small) of $3$ litres, $M$ (medium) of $5$ litres and $L$ (large) of $8$ litres.

Initially $S$ and $M$ are full of water and $L$ is empty. By pouring water between the buckets exactly one litre of water can be measured.

Since there is no other way to measure, once a pouring starts it cannot stop until either the source bucket is empty or the destination bucket is full.

At least four pourings are needed to get one litre:

$$(3,5,0) \stackrel{M \rightarrow L}{\longrightarrow}(3,0,5) \stackrel{S \rightarrow M}{\longrightarrow}(0,3,5) \stackrel{L \rightarrow S}{\longrightarrow}(3,3,2) \stackrel{S \rightarrow M}{\longrightarrow}(1,5,2)$$

After these operations, there is exactly one litre in bucket $S$.

In general the sizes of the buckets $S,M,L$ are $a$, $b$, $a+b$ litres, respectively. Initially $S$ and $M$ are full and $L$ is empty. If the above rule of pouring still applies and $a$ and $b$ are two coprime positive integers with $a\le b$ then it is always possible to measure one litre in finitely many steps.

Let $P(a,b)$ be the minimal number of pourings needed to get one litre. Thus $P(3,5)=4$.
Also, $P(7,31)=20$ and $P(1234,4321)=2780$.

Find the sum of $P(2^{p^5}-1, 2^{q^{5}}-1)$ for all pairs of prime numbers $p,q$ such that $p \lt q \lt 1000$.
Give your answer modulo $1\ 000\ 000\ 007$.
