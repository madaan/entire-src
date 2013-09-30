#sg

import sys
data = sys.stdin.readlines()
N = int(data[0])
ratings = [int(i) for i in data[1:]]
candies = [0] * N
candies[0] = 1
for i in range(1, N):
    if(ratings[i - 1] >= ratings[i]):
        candies[i] = 1
    else:
        candies[i] = candies[i - 1] + 1

for i in range(N - 2, -1, -1):
    if(ratings[i] > ratings[i + 1] and candies[i] <= candies[i + 1]):
        candies[i] = candies[i + 1] + 1

print sum(candies)
