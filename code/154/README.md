## Exploring Pascal's Pyramid


A triangular pyramid is constructed using spherical balls so that each ball rests on exactly three balls of the next lower level.

![](https://projecteuler.net/resources/images/0154_pyramid.png?1678992052)

Then, we calculate the number of paths leading from the apex to each position:

A path starts at the apex and progresses downwards to any of the three spheres directly below the current position.

Consequently, the number of paths to reach a certain position is the sum of the numbers immediately above it (depending on the position, there are up to three numbers above it).

The result is  **Pascal's pyramid**  and the numbers at each level  $n$  are the coefficients of the trinomial expansion  $(x+y+z)^n$.

How many coefficients in the expansion of  $(x+y+z)^{200000}$  are multiples of  $10^{12}$?
