#!/usr/bin/env python

# 等差數列總和，缺少一項

# 定義上下界限
# 1 <= sum <= 10 ^ 8
# 上: 14143 # 10 ^ 8 求出等差數列n與最後項得出
# 下: 1

def sum(n):
    return (1 + n) * n / 2

while True:
    sum1 = int(input("give me sum:"))
    print(sum1)
    up = 14143
    down = 1

    while down < up and not down + 1 == up:
        mid = (down + up) // 2
        if sum(mid) > sum1:
            up = mid
        elif sum(mid) < sum1:
            down = mid
        else:
            up = down = mid + 1
    if sum(up) - sum1 <= up:
        print('{} {}'.format(sum(up) - sum1, up))
    else:
        print("好像有一些問題")

