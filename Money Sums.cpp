#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> coins(n);
  for (int i = 0; i < n; i++)
    cin >> coins[i];
  long sum = accumulate(coins.begin(), coins.end(), 0);
  vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
  dp[0][0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= sum; j++) {
      dp[i][j] = dp[i - 1][j];
      if (j >= coins[i - 1] && dp[i - 1][j - coins[i - 1]]) {
        dp[i][j] = true;
      }
    }
  }
  vector<int> ans;
  for (int i = 1; i <= sum; i++) {
    if (dp[n][i]) {
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (auto it : ans) {
    cout << it << " ";
  }
}