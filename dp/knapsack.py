#/usr/bin/env python
from tqdm import tqdm
"""
0-1 knapsack
test Case: https://github.com/likr/kplib

格式參考上面的測資，但是需要做一些修改成下面的格式
下面有註解，可以按照不同測資修改格式
format:
- n: 物品數量
- c: 容量最大值
```
n
c
v_1 w_1
v_2 w_2
…
v_n w_n
```

a. 大問題分解成子問題
- 最簡子問題: 沒有取物品的情況
- 子問題: 前一個子問題的特定重量的情況，並且判斷取不取最佳的結果 

b. 列表法
"""

# load test case
num, max_w = int(input()), int(input()) + 1
 
# dp[i][j] ::= dp[num][max_w]
# dp[i][j] ::= dp[i][w]
# 最簡子問題 + 不同物品的列表問題
dp = [[0] * max_w] + [[None] * max_w for _ in range(num)]

# table
for i in range(num):
    i += 1
    line = input().split()

    v_i, w_i = int(line[0]), int(line[1])
    #w_i, v_i = int(line[0]), int(line[1])

    for w in range(max_w):
        if w_i > w:
            dp[i][w] = dp[i - 1][w]
        else:
            pick = v_i + dp[i - 1][w - w_i]
            dont_pick = dp[i - 1][w]
            dp[i][w] = max(pick, dont_pick)
        #print(dp)

max_value = -1
for i in dp[num]:
    max_value = max(max_value, i)

"""
for i in range(num + 1):
    print(dp[i])
"""

print(max_value)