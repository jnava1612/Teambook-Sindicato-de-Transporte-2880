signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("asd.txt", "r", stdin);
    // freopen("qwe.txt", "w", stdout);
    
    int n;
    cin>>n;
    int dp[n+1];
    dp[0]=1;
    //dice combinations
    fore(i,1,n+1){
        dp[i]=0;
        fore(j,1,7){
            if(i-j>=0){
                dp[i]+=dp[i-j];
                dp[i]%=MOD;
            }
        }
    }
    cout << dp[n] << '\n';
 
    return 0;
}