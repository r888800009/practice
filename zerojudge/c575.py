#!/usr/bin/env python
# NA QQ
while True:
    # N K
    cell_site = -1
    try:
        line = input().split()
        cell_site = int(line[1])
    except EOFError:
        break

    # service point
    service_point = input().split()
    for i in range(len(service_point)):
        service_point[i] = int(service_point[i]);
    service_point = list(set(service_point))
    #print(service_point)
    max_diff = service_point[-1] - service_point[0]

    # binary search
    min_r = 1
    max_r = max_diff

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

        """
        print(min_r, mid_r, max_r)
        print(f"r:{mid_r}, count:{mid_cell_count}")
        """

        #assert max_r != mid_r
        #assert min_r != mid_r

        # 直徑越小，基地台越多
        # 直徑越大，基地台越少
        # 代表
        # 基地台要減少時，直徑要增加
        # 基地台要增加時，直徑要減少
        # 上升下界可以增加直徑 (搜尋直徑範圍 mid+1~max)
        # 下降上界可以減少直徑 (搜尋直徑範圍 min~mid)

        # 基地台太少需要增加，直徑要減少，下降上界
        if mid_cell_count < cell_site:
            #max_r = max(mid_r - 1, min_r)
            # why max_r 上界不需要 - 1? (可能跟整數除法有關)
            max_r = mid_r
        # 基地台太多需要減少，直徑要增加，上升下界
        elif mid_cell_count > cell_site:
            min_r = min(mid_r + 1, max_r)
        # 基地台剛好，但是可能會有相同基地台數量，因此下降上界減少直徑
        elif min_r != max_r and mid_cell_count == cell_site:
            max_r = mid_r

    print(min_r)


