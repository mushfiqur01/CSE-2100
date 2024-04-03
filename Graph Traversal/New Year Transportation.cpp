#include<bits/stdc++.h>
using namespace std;

#define nl <<"\n"
vector<vector<int>> adj(30005);
bool vist[30005];

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    int n, dn, x, room; //n = number of edges, dn = destination
    cin >> n >> dn;

    for(int i = 1; i < n; i++)
    {
        cin >> x;
        adj[i].push_back(i + x);
    }

    queue<int> que;
    que.push(1);
    vist[1] = true;

    while (!que.empty())
    {
        room = que.front();
        if(room == dn) break;
        que.pop();

        for (auto it : adj[room])
        {
            if (!vist[it])
            {
                vist[it] = true;
                que.push(it);
            }
        }
    }

    if(vist[dn]) cout << "YES" nl;
    else cout << "NO" nl;
}
