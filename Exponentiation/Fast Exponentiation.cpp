//https://www.codechef.com/problems/FEXP
//https://www.codechef.com/viewsolution/1051331845

#include<bits/stdc++.h>

using namespace std;

int MOD = 1000000007;

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
    int m, n, t;

    cin >> t;
    while(t--)
    {
        cin >> m >> n;

        cout << PowAndMod(m, n) << "\n";
    }
}
