//https://www.spoj.com/status/LASTDIG,mushfiqur_1/

#include<bits/stdc++.h>
using namespace std;

#define nl <<"\n"
int lastdigt(int a, int n)
{
    int b = a % 10; //b = base

    if(n == 0) return 1;
    if(b == 0 || b == 1 || b == 5 || b == 6) return b;

    int exp = n % 4;
    if(exp == 0) exp = 4;

    int r = 1; //r = result
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            r *= b;
        }
        b *= b;
        exp /= 2;
    }
    return r % 10;
}

int main()
{
    int t, a, n; //t = number of test cases
    cin >> t;

    while(t--)
    {
        cin >> a >> n;
        cout << lastdigt(a, n) nl;
    }
}
