## Bézout's Game

Two players play a game with two piles of stones. They take alternating turns. If there are currently $a$ stones in the first pile and $b$ stones in the second, a turn consists of removing $c\ge 0$ stones from the first pile and $d\ge 0$ from the second in such a way that $ad-bc=\pm 1$. The winner is the player who first empties one of the piles.

Note that the game is only playable if the sizes of the two piles are coprime.

A game state $(a,b)$ is a winning position if the next player can guarantee a win with optimal play. Define $H(N)$ to be the number of winning positions $(a, b)$ with $gcd(a, b)=1$, $a\gt 0$, $b\gt 0$ and $a+b\le N$. Note the order matters, so for example $(2,1)$ and $(1,2)$ are distinct positions.

You are given $H(4)=5$ and $H(100)=2043$.

Find $H(10^9)$.
