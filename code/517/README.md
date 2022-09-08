## A real recursion

For every real number $a>1$ is given the sequence $g_a$ by:

$g_a(x)=1$ for $x<a$

$g_a(x)=g_a(x-1)+g_a(x-a)$ for $x\ge a$

$G(n)=g_{\sqrt{n}}(n)$

$G(90)=7564511$.

Find $\Sigma G(p)$ for $p$ prime and $10000000<p<10010000$

Give your answer modulo $1000000007$.
