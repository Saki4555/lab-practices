#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
#define ll long long

ll dp[N];
int h[N];

int main()
{
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
  {
    cin >> h[i];
  }

  dp[0] = 0;
  for (int i = 1; i < n; ++i)
  {
    dp[i] = 1e18;
    for (int j = 1; j <= k; ++j)
    {
      
      if (i - j < 0) break;
      
        dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
      
    }
  }

  cout << dp[n - 1] << endl;
  return 0;
}