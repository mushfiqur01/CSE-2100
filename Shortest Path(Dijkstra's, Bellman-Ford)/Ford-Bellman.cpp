//https://www.eolymp.com/en/problems/1453
//https://vjudge.net/status#un=Mushfiqur01&OJId=EOlymp&probNum=1453&res=0&language=&onlyFollowee=false

//You may not see my submitted code on vjudge, but you can see that it was accepted.
//This is the same code that I submitted.

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

    for(int i = 0; i < n; i++)
    {
        if(distance[i] == numeric_limits<int>::max()) cout << "30000 ";
        else cout << distance[i] << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n, edg, a, b, w;
    cin >> n >> edg;

    vector<vector<pair<int, int>>> graph(n);

    for(int i = 0; i < edg; i++)
    {

        cin >> a >> b >> w;
        a--, b--;
        graph[a].push_back({b, w});
    }

    BellmanFord(graph, 0);
}
