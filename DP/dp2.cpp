signed main()
{
    //La cantidad minimas de monedas para llegar a k o unbounded knapsack problem.
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("asd.txt", "r", stdin);
    // freopen("qwe.txt", "w", stdout);
    
    int n,k;
    cin>>n>>k;
    vector<int> dp(k+1,1e9);
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    dp[0]=0;
    for(int i=1;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i-a[j]>=0){
                dp[i]=min(dp[i],dp[i-a[j]]+1);
            }
        }
    }
    if(dp[k]==1e9)cout<<-1;
    else cout<<dp[k];
    
 
    return 0;
}
