## Prime Guessing

A prime is drawn uniformly from all primes not exceeding $N$. The prime is written in binary notation, and a player tries to guess it bit-by-bit starting at the least significant bit. The player scores one point for each bit they guess correctly. Immediately after each guess, the player is informed whether their guess was correct, and also whether it was the last bit in the number - in which case the game is over.

Let $E(N)$ be the expected number of points assuming that the player always guesses to maximize their score. For example, $E(10)=2$, achievable by always guessing "1". You are also given $E(30)=29$.

Find $E(10^8)$. Give your answer rounded to eight digits after the decimal point.
