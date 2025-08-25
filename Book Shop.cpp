#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> price(n);
  vector<int> pages(n);
  for (int i = 0; i < n; i++) {
    cin >> price[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> pages[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= x; i++) {
    dp[0][i] = 0;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = x; j >= 1; j--) {
      long take = 0;
      long ntake = 0;
      ntake = dp[i - 1][j];
      if (price[i - 1] <= j) {
        take = pages[i - 1] + dp[i - 1][j - price[i - 1]];
      }
      dp[i][j] = max(take, ntake);
    }
  }
  cout << dp[n][x] << endl;
}