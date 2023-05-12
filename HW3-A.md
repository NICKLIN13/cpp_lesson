Input:

First line containing two integers, N and M.

N represents the number of shops, which are numbered from 0 to N−1, and M represents the number of edges.

Following that, there will be M lines, each containing two numbers separated by a space, a_i​ , b_i​ , represents a connection between shops a_i​  and b_i​ .

. For all test data, it is guaranteed:

$$
- aia\_iai​ ≠\\neq\= bib\_ibi​
- 0≤ai,bi≤N−10 \\leq a\_i, b\_i \\leq N - 10≤ai​,bi​≤N−1
- 2≤N≤1062 \\leq N \\leq 10^62≤N≤106
- N−1≤M≤N(N−1)/2≤106N-1\\le M\\le N(N-1)/2\\le 10^6N−1≤M≤N(N−1)/2≤106
- There are no repeated connections.
$$

Output:

Output all roads that, if under maintenance, will cause certain shops to be unable to reach certain other shops. The output format should be the two shop numbers connected by the road, listed in ascending order of their numbers, means that a_i < b_i.

Each road listed in ascending order by a_i. If there are two edges with the same a_i, then they should be ordered by b_i in ascending order. If there are no critical road, output "No Critical Road".
