# import json

# x = '{}'

# json.loads(x)


m = [["a", 35],\
 ["b", 8],\
 ["c", 8],\
 ["d", 20],\
 ["e", 70],\
 ["f", 20],\
 ["g", 10],\
 ["h", 40],\
 ["i", 35],\
 ["k", 5],\
 ["l", 20],\
 ["m", 8],\
 ["n", 30],\
 ["o", 40],\
 ["p", 10],\
 ["q", 2],\
 ["r", 35],\
 ["s", 35],\
 ["t", 40],\
 ["u", 15],\
 ["v", 5],\
 ["w", 18],\
 ["y", 8],\
 ["z", 2]]
M = {}
for c in m:
  M[c[0]] = c[1]
nM = {}
page = 1


for i in range(2566):
  inp = input()
  for c in inp:
    c = c.lower()
    if c in nM:
      nM[c] += 1
      if nM[c] > M[c]:
        page += 1
        nM = {}
        nM[c] = 1
    else:
      nM[c] = 1

print(page)