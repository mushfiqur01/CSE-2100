#include<bits/stdc++.h>
using namespace std;

#define nl <<"\n"
vector<vector<int>> adj(100005);

bool vist[100005];

double DFS(int node)
{
    vist[node] = 1;

    double total_len = 0, total_path = 0;

    for (auto it : adj[node])
    {
        if (!vist[it])
        {
            total_path++;
            total_len += DFS(it) + 1;
        }
    }

    return total_path == 0 ? 0 : (total_len / total_path);
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    int n; //n = number of cities
    cin >> n;

    int x, y;
    for(int i = 1; i < n; i++)
    {
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    double sum = DFS(1);

    cout << fixed << setprecision(8) << sum nl;
}
