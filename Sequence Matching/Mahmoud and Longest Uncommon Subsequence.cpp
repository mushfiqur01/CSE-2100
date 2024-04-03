//https://codeforces.com/problemset/problem/766/A

#include<bits/stdc++.h>
using namespace std;

#define nl <<"\n"
int LUcS(string X, string Y) //LUcS = Longest Uncommon Subsequence
{
    if(X == Y) return -1;
    else return max(X.size(), Y.size());
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);

    string S1, S2;
    cin >>  S1 >> S2;

    int ans = LUcS(S1, S2);
    cout << ans nl;
}
