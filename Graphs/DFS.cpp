vector<vector<int>> g(tam);
vector<bool> vis(tam);

void dfs(int u){
    vis[u]=true;
    ans++;
    for(int v: g[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
}

signed main()
{
    int n,m;
    cin>>n>>m; // n nodes, m edges
    g.assign(tam,vector<int>());
    vis.assign(tam, false);
    for(int i=0; i<m;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ll res = 0;
    for(int i=1; i<=n;i++){
        if(!vis[i]){
            ans=0;
            dfs(i);
            res = max(res,ans);
        }
    }
    g.clear();
    vis.clear();
    return 0;
}
