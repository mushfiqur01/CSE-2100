//https://codeforces.com/problemset/problem/545/D
//https://codeforces.com/contest/545/submission/252568588

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    int n, t, satisfied = 0;
    long long current_time = 0;
    priority_queue<int, vector<int>, greater<int>> queue;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> t;
        queue.push(t);
    }

    while(!queue.empty())
    {
        if(queue.top() >= current_time)
        {
            satisfied++;
            current_time += queue.top();
        }
        queue.pop();
    }

    cout << satisfied << "\n";
}
