N = 10
M = N

ls = [(i, i+1) for i in range(1, N)]
ls += (N, 1)

R = len(ls)
print(N, M)
print(R)

for l in ls:
    print(l[0], l[1])