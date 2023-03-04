#include <bits/stdc++.h>
using namespace std;

int main() {
// there is one way to reach (0,0), dp[0][0] = 1.
//Consider an n*n grid whose squares may have traps. It is not allowed to move to a square with a trap.Your task is to calculate the number of paths from the upper-left square to the lower-right square. You can only move right or down
  int mod = 1e9+7;
  int n;
  cin >> n;
  vector<vector<int>> dp(n, vector<int>(n, 0));
  dp[0][0] = 1;
  for (int i = 0; i < n; i++) {
    string row;
    cin >> row;
    for (int j = 0; j < n; j++) {
      if (row[j] == '.') {
	if (i > 0) {
	  (dp[i][j] += dp[i-1][j]) %= mod;
	}
	if (j > 0) {
	  (dp[i][j] += dp[i][j-1]) %= mod;
	}
      } else {
	dp[i][j] = 0;
      }
    }
  }
  cout << dp[n-1][n-1] << endl;
}