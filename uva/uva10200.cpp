#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

int dp[10001];

int isPrime(long long n)
{
    if (dp[n] != -1)
        return dp[n];

    int tmp = n;
    n = n * n + n + 41;
    for (long long i = 2; i * i <= n; ++i) 
        if (n % i == 0)
            return dp[tmp] = 0;
    return dp[tmp] = 1;
}

int main()
{
    long long a, b;
    fill(&dp[0], &dp[10001], -1);
    cout << setprecision(2) << fixed;
    while (1) {
       cin >> a >> b; 
       if (cin.eof())
           break;
       int primeCount = 0, count = 0;
       
       for (; a <= b; a++, count++)
           if (isPrime(a))
               primeCount++; 

        cout << ((double) primeCount / count) * 100.0f + 0.005 << endl; 
    }
    return 0;
}
