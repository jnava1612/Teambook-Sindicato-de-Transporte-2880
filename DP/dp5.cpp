#include <bits/stdc++.h>
using namespace std;
//You are given an integer n On each step, you may subtract one of the digits from the number.How many steps are required to make the number equal to 0
int main() {
  int n;
  cin >> n;
  vector<int> dp(n+1,1e9);
  dp[0] = 0;
  for (int i = 0; i <= n; i++) {
    for (char c : to_string(i)) {
      dp[i] = min(dp[i], dp[i-(c-'0')]+1);
    }
  }
  cout << dp[n] << endl;
}