//https://atcoder.jp/contests/abc293/tasks/abc293_e
//https://atcoder.jp/contests/abc293/submissions/51420483

#include<bits/stdc++.h>

using namespace std;

long long MOD;

int PowAndMod(long long base, long long exponent) {
    long long result = 1;
    base %= MOD;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

long long GP(long long base, long long X) //This Geometric Progression function works in Binary way
{                                         //Similar to PowAndMod function
    if(!X) return 0;

    if(X % 2)
    {
        return (1 + base * GP(base, X - 1)) % MOD;
    }
    else return ((PowAndMod(base, X / 2) + 1) * GP(base, X / 2)) % MOD;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    long long A, x, ans;

    cin >> A >> x >> MOD;

    ans = GP(A, x);
    cout << ans << endl;
}
