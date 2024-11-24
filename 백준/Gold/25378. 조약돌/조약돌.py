N = int(input())
rock = [*map(int,input().split())]
DP = [0]*N
for i in range(N):
  DP[i] = max(DP[i],DP[i-1])
  x = rock[i]
  for j in range(i+1,N):
    x = rock[j]-x
    if x<0:
      break
    if x==0:
      DP[j] = max(DP[j],DP[i-1]+1)
      break
print(N-DP[-1])