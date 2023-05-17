Solve this problem by C++:

Input:

First line containing two integers, N and M.

N represents the number of shops, which are numbered from 0 to N−1, and M represents the number of edges.

Following that, there will be M lines, each containing two numbers separated by a space, u​ v​, represents a connection between shops u​ and v​.

For all test data, it is guaranteed:


- u != v
- 0 <= u, v <= N−1
- 2 <= N <= 10^6
- N−1 <= M <= N(N−1)/2 <= 10^6
- There are no repeated connections.


Output:

Output all roads that, if under maintenance, will cause certain shops to be unable to reach certain other shops. The output format should be the two shop numbers connected by the road, listed in ascending order of their numbers, means that u < v.

Each road listed in ascending order by u. If there are two edges with the same u, then they should be ordered by v in ascending order. If there are no critical road, output "No Critical Road".
