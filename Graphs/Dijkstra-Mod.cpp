// Dijkstra Modification thanks to pacha2880

vi dijkstra(int n, vector<vii> &g, int s, vi &par)
{
    vi dis(n, MOD), vis(n);
    dis[s] = 0;
    priority_queue<ii> que;
    que.push({0, s});
    while(!que.empty())
    {
        int node = que.top().s;
        que.pop();
        if(vis[node]) continue;
        vis[node] = 1;
        for(ii go : g[node])
            if(dis[go.f] > dis[node] + go.s)
            {
                dis[go.f] = dis[node] + go.s;
                par[go.f] = node;
                que.push({-dis[go.f], go.f});
            }
    }
    
    return dis;
}

vi path;
vi par(n+1, -1);
int t;
if(dis[t] == MOD){
    do {
        path.pb(t);
        t = par[t];
    } while(t != -1);
}

