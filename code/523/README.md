## First Sort I

Consider the following algorithm for sorting a list:

1. Starting from the beginning of the list, check each pair of adjacent elements in turn.
2. If the elements are out of order:
a. Move the smallest element of the pair at the beginning of the list.
b. Restart the process from step 1.
3. If all pairs are in order, stop.
For example, the list { 4 1 3 2 } is sorted as follows:

4 1 3 2 (4 and 1 are out of order so move 1 to the front of the list)
1 4 3 2 (4 and 3 are out of order so move 3 to the front of the list)
3 1 4 2 (3 and 1 are out of order so move 1 to the front of the list)
1 3 4 2 (4 and 2 are out of order so move 2 to the front of the list)
2 1 3 4 (2 and 1 are out of order so move 1 to the front of the list)
1 2 3 4 (The list is now sorted)

Let F(L) be the number of times step 2a is executed to sort list L. For example, F({ 4 1 3 2 }) = 5.

Let E(n) be the expected value of F(P) over all permutations P of the integers {1, 2, ..., n}.
You are given E(4) = 3.25 and E(10) = 115.725.

Find E(30). Give your answer rounded to two digits after the decimal point.
