//https://codeforces.com/problemset/problem/20/C
//https://codeforces.com/contest/20/submission/255904533

#include <bits/stdc++.h>

using namespace std;

void dijkstra(const vector<vector<pair<int, long long>>>& graph, int source, int destination)
{
    int n = graph.size();
    vector<long long> distance(n, numeric_limits<long long>::max());
    vector<bool> visited(n, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<int> path(n, -1);

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        pair<long long, int> current = pq.top();
        pq.pop();

        int u = current.second;

        if(u == destination) break;
        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& neighbor : graph[u])
        {
            long long v = neighbor.first;
            long long weight = neighbor.second;

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                path[v] = u;
                pq.push({distance[v], v});
            }
        }
    }
    if(distance[destination] < numeric_limits<long long>::max())
    {
        stack<int> AnsPath;
        int i = destination;
        while(path[i] > -1)
        {
            AnsPath.push(i);
            i = path[i];
        }
        AnsPath.push(i);

        while(!AnsPath.empty())
        {
            cout << AnsPath.top() + 1 << " ";
            AnsPath.pop();
        }
        cout << "\n";
    }
    else cout << -1 << "\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n, edg, a, b, w;
    cin >> n >> edg;

    vector<vector<pair<int, long long>>> graph(n);

    for(int i = 0; i < edg; i++)
    {

        cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    dijkstra(graph, 0, n - 1);
}
