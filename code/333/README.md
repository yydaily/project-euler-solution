## Special partitions

All positive integers can be partitioned in such a way that each and every term of the partition can be expressed as $2^i\times 3^j$, where $i,j ≥ 0$.

Let's consider only such partitions where none of the terms can divide any of the other terms.

For example, the partition of $17 = 2 + 6 + 9 = (2^1x3^0 + 2^1x3^1 + 2^0x3^2)$ would not be valid since $2$ can divide $6$. Neither would the partition $17 = 16 + 1 = (2^4x3^0 + 2^0x3^0)$ since $1$ can divide $16$. The only valid partition of $17$ would be $8 + 9 = (2^3x3^0 + 2^0x3^2)$.

Many integers have more than one valid partition, the first being $11$ having the following two partitions.

$11 = 2 + 9 = (2^1x3^0 + 2^0x3^2)$
$11 = 8 + 3 = (2^3x3^0 + 2^0x3^1)$

Let's define $P(n)$ as the number of valid partitions of $n$. For example, $P(11) = 2$.

Let's consider only the prime integers $q$ which would have a single valid partition such as $P(17)$.

The sum of the primes $q <100$ such that $P(q)=1$ equals $233$.

Find the sum of the primes $q <1000000$ such that $P(q)=1$.
