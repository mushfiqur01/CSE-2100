//https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B
//https://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=9081863#1

#include <bits/stdc++.h>

using namespace std;

void BellmanFord(const vector<vector<pair<int, int>>>& graph, int source)
{
    int n = graph.size();
    vector<int> distance(n, numeric_limits<int>::max());

    distance[source] = 0;

    for (int i = 0; i < n - 1; ++i)
    {
        for (int u = 0; u < n; ++u)
        {
            for (const auto& neighbor : graph[u])
            {
                int v = neighbor.first;
                int weight = neighbor.second;

                if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v])
                {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    for (int u = 0; u < n; ++u)
    {
        for (const auto& neighbor : graph[u])
        {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (distance[u] != numeric_limits<int>::max() && distance[u] + weight < distance[v])
            {

                cout << "NEGATIVE CYCLE" << "\n";
                return ;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        if(distance[i] == numeric_limits<int>::max()) cout << "INF" << "\n";
        else cout << distance[i] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n, edg, a, b, w, source;
    cin >> n >> edg >> source;

    vector<vector<pair<int, int>>> graph(n);

    for(int i = 0; i < edg; i++)
    {

        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }

    BellmanFord(graph, source);
}
