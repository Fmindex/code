t = int(input())
for lap in range(t):
    s = input()
    res = ''
    op = 0
    for c in s:
        n = int(c)
        if op > n:
            diff = op - n
            toPrint = [')'] * diff
            res += "".join(toPrint)
            res += c
            op = n
        elif op < n:
            diff = n - op
            toPrint = ['('] * diff
            res += "".join(toPrint)
            res += c
            op = n
        else:
            res += c
    if op > 0:
        toPrint = [')'] * op
        res += "".join(toPrint)
    print("Case #{}: {}".format(lap + 1, res))