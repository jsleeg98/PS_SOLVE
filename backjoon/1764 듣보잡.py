import sys

N, M = map(int, input().split())

no_hear = {}
no_see = {}

for _ in range(N):
    name = sys.stdin.readline()[:-1]
    no_hear[name] = True

for _ in range(M):
    name = sys.stdin.readline()[:-1]
    no_see[name] = True

result = []

for k in no_hear.keys():
    if not no_see.get(k) == None:
        result.append(k)

result.sort()

print(len(result))
for i in result:
    print(i)
