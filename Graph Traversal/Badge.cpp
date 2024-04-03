//https://codeforces.com/problemset/problem/1020/B
#include<bits/stdc++.h>
using namespace std;

#define nl <<"\n"
vector<int> adj(1005); //I did not use a vector of vector because one student only point to another oner
                       //A adjacent vector would have only one element if I used vector of vector

int DFS(int node, bool vist[])
{
    vist[node] = 1;

    int it = adj[node]; //I only need one node to point to another node, so I don't need to use a 'for' loop

    if (!vist[it])
    {
        return DFS(it, vist);
    }
    else return it;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    int n; //n = the number of the naughty students
    cin >> n;

    int a[n];

    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        adj[i] = a[i];
    }


    for(int i = 1; i <= n; i++)
    {
        bool vist[1005] = {0};
        cout << DFS(i, vist) << " ";
    }
    cout nl;
}
