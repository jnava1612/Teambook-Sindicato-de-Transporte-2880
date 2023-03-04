//combination de monedas en orden
ll dp[1000001];

const int MOD = (int) 1e9 + 7;

int main(){
	int n, x; cin >> n >> x;
	vi coins(n);
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}
	dp[0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int weight = 0; weight <= x; weight++) {
			if(weight - coins[i - 1] >= 0) {  // prevenir casos bound
				dp[weight] += dp[weight - coins[i - 1]];
				dp[weight] %= MOD;
			}
		}
	}
	cout << dp[x] << '\n';
}