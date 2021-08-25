#include <iostream>
#include <deque>
#include <utility>

using namespace std;

#define MAX_WH 1000
bool map[MAX_WH][MAX_WH], visited[MAX_WH][MAX_WH];

int h, w;

#define POOL true
#define BLOCK false

#define POOL_CHAR '.'
#define BLOCK_CHAR '#'

typedef pair<int, int> XY;
const int direct_size = 4;
int direct[direct_size][2] = {
    //{-1, 1},
    {0, 1},
    //{1, 1},
    {1, 0},
    //{1, -1},
    {0, -1},
    //{-1, -1},
    {-1, 0},
};

int find_x, find_y;
void init()
{
    string line_map;
    // load and init map
    for (int y = 0; y < h; y++)
    {
        cin >> line_map;
        for (int x = 0; x < w; x++)
        {
            visited[x][y] = false;
            map[x][y] = (line_map.at(x) == POOL_CHAR) ? POOL : BLOCK;
        }
    }

    // init find_empty() value
    find_x = 0;
    find_y = 0;
}

XY find_empty()
{
    while (find_x < w)
    {
        if (map[find_x][find_y] == POOL && visited[find_x][find_y] == false)
            return XY(find_x, find_y);

        find_y += 1;
        if (find_y >= h)
            find_y = 0, find_x += 1;
    }

    return XY(-1, -1);
}

void visit(deque<XY> &bfs_queue, int x, int y)
{
    visited[x][y] = true;
    bfs_queue.push_back(XY(x, y));
}

void push_not_visited(deque<XY> &bfs_queue, int x, int y)
{
    for (int i = 0; i < direct_size; i++)
    {
        int new_x = x, new_y = y;
        new_x += direct[i][0];
        new_y += direct[i][1];

        // check
        if (new_y < 0 || new_x < 0 || new_x >= w || new_y >= h)
            continue;

        if (visited[new_x][new_y])
            continue;

        if (map[new_x][new_y] == BLOCK)
            continue;
        //cout << new_x << '.' << new_y << '\n';

        // push and set visited
        visit(bfs_queue, new_x, new_y);
    }
}

int bfs()
{
    deque<XY> bfs_queue;
    int count = 0;

    XY next_xy = find_empty();
    while (next_xy.first != -1)
    {
        if (!visited[next_xy.first][next_xy.second])
        {
            visit(bfs_queue, next_xy.first, next_xy.second);
            count += 1;
        }

        //cout << next_xy.first << '_' << next_xy.second << '\n';
        while (!bfs_queue.empty())
        {
            XY xy = bfs_queue.front();
            bfs_queue.pop_front();
            push_not_visited(bfs_queue, xy.first, xy.second);
            //cout << xy.first << ' ' << xy.second << '\n';
        }

        // next round
        next_xy = find_empty();
    }

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int total;
    cin >> total;

    for (int i = 0; i < total; i++)
    {
        cin >> h >> w;
        init();
        cout << bfs() << '\n';
    }

    return 0;
}