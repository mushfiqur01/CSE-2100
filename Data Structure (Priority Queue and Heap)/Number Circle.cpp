//https://codeforces.com/problemset/problem/1189/B
//https://codeforces.com/contest/1189/submission/252700908

#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    int n, x, i;
    priority_queue<int> queue;
    cin >> n;

    vector<long long> a(n);

    for(i = 0; i < n; i++)
    {
        cin >> x;
        queue.push(x);
    }

    a[n - 2] = queue.top();
    queue.pop();
    a[n - 1] = queue.top();
    queue.pop();

    for(int i = n - 3; i >= 0; i--)
    {
        a[i] = queue.top();
        queue.pop();
    }

    bool condition = true;

    if(a[0] >= a[n - 1] + a[1]) condition = false;          //
    if(a[n - 1] >= a[0] + a[n - 2]) condition = false;      //
                                                            //
    i = 1, n--;                                             //
    while(i < n && condition)                               //Checking the condition
    {                                                       //
        if(a[i] >= a[i - 1] + a[i + 1]) condition = false;  //
        i++;                                                //
    }                                                       //

    if(condition)
    {
        cout << "YES" << "\n";
        for(i = 0; i <= n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    else cout << "NO" << "\n";
}
