#include <iostream>

using namespace std;

#define CITY_SIZE 800

bool map[CITY_SIZE][CITY_SIZE];
bool visited_city[CITY_SIZE];

int city_size, road_size;

bool dfs(int src, int dist)
{
    if (src == dist)
        return true;

    visited_city[src] = true;

    for (int i = 0; i < city_size; i++)
    {
        if (map[src][i] && !visited_city[i])
        {
            bool result = dfs(i, dist);
            if (result)
                return true;
        }
    }

    return false;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    while(cin >> city_size >> road_size) {
        // init map
        for (int i = 0; i < city_size; i++)

        {
            for (int j = 0; j < city_size; j++)
            {
                map[i][j] = false;
            }
            visited_city[i] = false;
        }

        // load map
        for (int i = 0; i < road_size; i++)
        {
            int a, b;
            cin >> a >> b;
            map[a - 1][b - 1] = true;
        }

        int a, b;
        cin >> a >> b;

        if (dfs(a - 1, b - 1))
            cout << "Yes!!!\n";
        else
            cout << "No!!!\n";

    }
    return 0;
}

