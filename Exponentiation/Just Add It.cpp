//https://www.spoj.com/problems/ZSUM/en/
//https://www.spoj.com/submit/ZSUM/id=32793586

#include<bits/stdc++.h>

using namespace std;

int MOD = 10000007;

int PowAndMod(long long base, int exponent)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    long long n, k, Z, S, P;

    while(1)
    {
        cin >> n >> k;

        if(n == 0) break;

        S = (PowAndMod(n, k) + 2 * PowAndMod(n - 1, k)); //S = S(n) + S(n - 1) - 2S(n - 2)
        P = (PowAndMod(n, n) + 2 * PowAndMod(n - 1, n - 1)); //P = P(n) + P(n - 1) - 2P(n - 2)

        Z = (S + P) % MOD;

        cout << Z << "\n";
    }
}
