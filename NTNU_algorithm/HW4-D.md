## Description

When Corgi was still in his high school HSNU, his computer science project was titled "Police Patrol Route Planning System - A Case Study of Da'an District, Taipei City". The research aimed to combine crime data statistics of the city and devise optimal patrol routes for various police stations in the city. The techniques applied in the project included DFS, Hamiltonian paths, Euler circuits, Route inspection problem, Floyd-Warshall, and Fleury algorithms. However, these techniques are irrelevant to the current problem, so it is not necessary to understand them :)

In a parallel universe, this project was considered a breakthrough research, and police agencies in major cities began to adopt the planning methods proposed in the study. However, before implementation, they encountered the issue of personnel reassignment. After numerous simulations, the police agencies determined the number of patrol officers required for each police station. Some police stations experienced a significant reduction in personnel needs, while others faced a substantial increase. To minimize dissatisfaction among the officers due to reassignments, commissioners of each police station conducted a survey to gather data on the most preferred police station for officers to be reassigned to. Now, the police agencies want to know the minimum accumulated shortage of patrol officers across all police stations under the condition of "meeting the preferences of the reassigned officers." Please help them find the answer.


## Input

The first line contain an integers N, represents the number of the police stations. The second line contain N integers a_i​ , represents the total number of patrol officers in i-th police station currently. The third line contain N integers b_i​ , represents the required total number of patrol officers in i-th police station before the patrol plan is implemented. The following N lines represent the results of the survey. The i-th line contains N integers x_ij​ , represents the number of officers who want to be reassigned from i-th police station to j-th police station. The integer x_ii​ in i-th line is guaranteed to be 0.

For all test data, it is guaranteed:

- 2 ≤ N ≤ 100
- 0 ≤ a_i​, b_i​ ≤ 10^7
- 0 ≤ x_ij​ ≤ 10^5
- ∑_{j=1}^{N}​{x ij}​ ≤ a_i​


## Output

Print the minimum accumulated shortage described in the problem, followed by a newline character.

## Examples

### 1

Input

```
3
4 2 1
2 2 3
0 1 1
0 0 1
0 0 0
```

Output 1

```
0
```

### 2

Input

```
3
5 1 1
2 2 3
0 1 0
0 0 1
0 0 0
```

Output

```
2
```


### 3

Input

```
4
7 3 1 9
3 8 5 5
0 1 1 1
0 0 0 1
0 1 0 0
1 1 1 0
```

Output

```
5
```
