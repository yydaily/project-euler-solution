## Digital root sums of factorisations

A composite number can be factored many different ways. For instance, not including multiplication by one, $24$ can be factored in $7$ distinct ways:

$$
\begin{aligned}
24 &= 2\times 2\times 2\times 3  \\
24 &= 2\times 3\times\times 4  \\
24 &= 2\times 2\times 6  \\
24 &= 4\times 6  \\
24 &= 3\times 8  \\
24 &= 2\times 12  \\
24 &= 24\\
\end{aligned}
$$

Recall that the digital root of a number, in base $10$, is found by adding together the digits of that number, and repeating that process until a number is arrived at that is less than $10$. Thus the digital root of $467$ is $8$.

We shall call a Digital Root Sum (DRS) the sum of the digital roots of the individual factors of our number.  
The chart below demonstrates all of the DRS values for $24$.

| Factorisation               | Digital Root Sum |
| --------------------------- | ---------------- |
| $2\times 2\times 2\times 3$ | $9$              |
| $2\times 3\times 4$         | $9$              |
| $2\times 2\times 6$         | $10$             |
| $4\times 6$                 | $10$             |
| $3\times 8$                 | $11$             |
| $2\times 12$                | $5$              |
| $24$                        | $6$              |

The maximum Digital Root Sum of $24$ is $11$.  
The function mdrs(n) gives the maximum Digital Root Sum of n. So mdrs($24$)=$11$.  

Find ∑ mdrs(n) for $1$ < n < $1$,$000$,$000$.
