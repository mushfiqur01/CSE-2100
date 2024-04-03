//https://codeforces.com/problemset/problem/1446/A
//https://codeforces.com/contest/1446/submission/254786575

#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    int t;
    long long N, W;
    cin >> t;
    while(t--)
    {
        cin >> N >> W;

        vector<int> a(N), taken;
        long long sum = 0, goal = (W + 1) / 2;
        bool f = 0;

        for(int i = 0; i < N; i++)
        {
            cin >> a[i];
        }

        for(int i = 0; i < N; i++)
        {
            if(a[i] > W) continue;
            else
            {
                if(a[i] < goal && sum < goal)
                {
                    taken.push_back(i);
                    sum += a[i];
                }
                else if(a[i] >= goal)
                {
                    f = 1;
                    cout << 1 << "\n" << i + 1 << "\n";
                    break;
                }
                else break;
            }
        }

        if(f) continue;
        else if(sum < goal) cout << -1 << "\n";
        else
        {
            cout << taken.size() << "\n";
            for(auto x : taken) cout << x + 1 << " ";
            cout << "\n";
        }
    }
}
