#!/usr/bin/env python
# NA QQ
# N K
line = input().split()
cell_site = int(line[1])

# service point
service_point = sorted(input().split())
for i in range(len(service_point)):
    service_point[i] = int(service_point[i]);
max_point = service_point[-1]

# binary search
min_r = 1
max_r = max_point

def count_cell_site(cur_r, service_point):
    count = 1
    cur = service_point[0]
    for point in service_point:
        if cur + cur_r < point:
            count += 1
            cur = point

    return count

while min_r != max_r:
    mid_r = (max_r + min_r) // 2
    mid_cell_count = count_cell_site(mid_r, service_point)


    #print(min_r, mid_r, max_r)
    #print(mid_r, mid_cell_count)

    if min_r == mid_r and mid_cell_count == cell_site:
        print(mid_r)
        break

    #assert max_r != mid_r
    #assert min_r != mid_r


    
    if mid_cell_count < cell_site:
        max_r = max(mid_r - 1, mid_r)
    elif mid_cell_count > cell_site:
        min_r = min(mid_r + 1, max_r)
    elif min_r != max_r and mid_cell_count == cell_site:
        max_r = mid_r

    if min_r == max_r:
        print(mid_r)
        #print(mid_r, '1', mid_cell_count)


