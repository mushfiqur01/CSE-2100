//https://www.spoj.com/problems/SHPATH/
//https://www.spoj.com/status/SHPATH,mushfiqur_1/

#include <bits/stdc++.h>

using namespace std;

int dijkstra(const vector<vector<pair<int, int>>>& graph, int source, int destination)
{
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());
    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    distance[source] = 0;
    pq.push({0, source});

    while (!pq.empty())
    {
        pair<int, int> current = pq.top();
        pq.pop();

        int u = current.second;

        if(u == destination) return distance[u];
        if (visited[u]) continue;
        visited[u] = true;

        for (const auto& neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                pq.push({distance[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;

        vector<vector<pair<int, int>>> graph(n);
        vector<string> s(n);

        for(int i = 0; i < n; i++)
        {
            cin >>s[i];
            int edg, w, ne;
            cin >> ne;
            while(ne--)
            {
                cin >> edg >> w;
                graph[i].push_back({edg - 1, w});
            }
        }

        int jrny, start, end;
        string a, b;
        cin >> jrny;

        while(jrny--)
        {
            cin >> a >> b;
            start = -1, end = -1;
            for(int i = 0; i < n; i++)
            {
                if(start < 0 || end < 0)
                {
                    if(s[i] == a)
                    {
                        start = i;
                    }
                    if(s[i] == b)
                    {
                        end = i;
                    }
                }
                else break;
            }

            cout << dijkstra(graph, start, end) << "\n";
        }
    }
}
