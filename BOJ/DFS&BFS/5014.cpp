#include <iostream>
#include <queue>
using namespace std;
int dist[1000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int f, s, g, u, d;
    cin >> f >> s >> g >> u >> d;

    queue<int> Q;
    
    fill(dist, dist + 1000001, -1);

    Q.push(s);
    dist[s] = 0;
    while (dist[g] == -1)
    {
        if (Q.empty())
        {
            cout << "use the stairs";
            return 0;
        }
        int cur = Q.front(); Q.pop();
        for (int v : {cur + u, cur - d})
        {
            if (v <= 0 || v > f) continue;
            if (dist[v] != -1) continue;
            dist[v] = dist[cur] + 1;
            Q.push(v);
        }
    }
    cout << dist[g];

    return 0;
}
