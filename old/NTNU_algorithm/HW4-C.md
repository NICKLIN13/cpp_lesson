## Description

Vonernue is the CEO of a technology company and also works as a professional DJ. This summer, he plans to travel from Taiwan to Sweden on a business trip to meet with clients. However, being someone who always works smart, he doesn't want to waste this opportunity to travel abroad. After discussing with his assistant, he decides to held a party in each layover city on his way to Sweden. However, due to budget constraints, he wants to minimize the cost of the plane tickets.

After Vonernue listed the cities he's interested in, his assistant calculated the flight costs between each city and discussed with Vonernue on how to plan the trip. Just when Vonernue had planned his trip, his loyal fan Corgi sent him a flight discount voucher. This voucher can be used for one free flight of any country to another. Being a graduate of NTNU CSIE, he is skilled at reorganizing plans, and so are you. Now, given the costs of the flights between cities, please find the minimum cost of the journey to Sweden considering the use of the discount voucher, as well as the number of cities where parties can be held along the way.

## Input

The first line contains two integers 
N,M, separated by spaces. N represents the total number of cities, including Taiwan and Sweden. M represents the total number of possible flight between cities. The following i−th lines contain three integers u_i ,v_i ,w_i , separated by spaces. Each line represents that it costs w_i dollars for the flight between city u_i and city v_i . Every flight between cities is bidirectional. City 1 represents Taiwan and city N represents Sweden.



## Output

Print the minimum cost of the journey from Taiwan to Sweden and the number of cities where the parties can be held, excluding Taiwan and Sweden. If there are multiple answers of the number of cities under the same cost, print the maximum one. Two outputs should be separated by space, and the whole output should be followed by a newline character. The answer is guaranteed to exist.

## Examples

### 1

Input

```
4 4
1 2 3
2 4 6
1 3 1
3 4 9
```

Output 1

```
1 1
```

### 2

Input

```
5 5
1 2 2
2 5 2
1 3 1
3 4 1
4 5 1
```

Output

```
2 2
```


### 3

Input

```
10 15
1 3 2
1 5 7
3 4 10
3 5 6
3 6 8
2 6 7
5 6 8
6 8 1
8 9 3
1 2 7
8 10 5
7 8 1
4 9 1
5 7 7
1 9 4
```

Output

```
7 2
```


6 6
1 2 2
2 3 8
3 4 1
1 5 4
5 4 3
4 6 5