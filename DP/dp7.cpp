/You are in a book shop which sells n
 different books. You know the price and number of pages of each book.

You have decided that the total price of your purchases will be at most x
. What is the maximum number of pages you can buy? You can buy each book at most once.#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> price(n), pages(n);
  for (int i;i<n;i++) cin >> price[i];
  for (int i;i<n;i++) cin >> pages[i];
  vector<vector<int>> dp(n+1,vector<int>(x+1,0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = dp[i-1][j];
      int left = j-price[i-1];
      if (left >= 0) {
	dp[i][j] = max(dp[i][j], dp[i-1][left]+pages[i-1]);
      }
    }
  }
  cout << dp[n][x] << endl;
}