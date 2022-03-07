## Concatenation Coincidence

A non-decreasing sequence of integers $a_n$ can be generated from any positive real value $\theta$ by the following procedure:

<center>$b_1=\theta$</center>
<center>$b_n=\lfloor b_{n-1}\rfloor(b_{n-1}-\lfloor b_{n-1}\rfloor+1)\ \  \forall n \ge 2 $</center>
<center>$a_n=\lfloor b_n \rfloor$</center>

Where $\lfloor . \rfloor$ is the floor function.

For example, $\theta=2.956938891377988\dots$  generates the Fibonacci sequence: $2, 3, 5, 8, 13, 21, 34, 55, 89, \dots$

The *concatenation* of a sequence of positive integers $a_n$ is a real value denoted $\tau$ constructed by concatenating the elements of the sequence after the decimal point, starting at $a_1:a_1.a_2a_3a_4\dots$ 

For example, the Fibonacci sequence constructed from $\theta=2.956938891377988\dots$ yields the concatenation $\tau=2.3581321345589\dots$ Clearly, $\tau \neq \theta$ for this value of $\theta$.

Find the only value of $\theta$ for which the generated sequence starts at $a_1=2$ and the concatenation of the generated sequence equals the original value: $\tau = \theta$. Give your answer rounded to $24$ places after the decimal point.
