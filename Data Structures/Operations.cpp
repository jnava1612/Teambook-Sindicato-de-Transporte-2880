struct segtree {
    int size;
    vi operations;
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        operations.assign(2 * size, 0LL);
    }

    void add(int l, int r, int v, int x, int lx, int rx){
        if(lx >= r || l >= rx) return;
        if(lx >= l && rx <= r) {
            operations[x]+=v;
            return;
        }
        int m = (lx + rx) / 2;
        add(l, r, v, 2 * x + 1, lx, m);
        add(l, r, v, 2 * x + 2, m, rx);
    }

    void add(int l, int r, int v) {
        add(l, r, v, 0, 0, size);
    }

    int get(int i, int x, int lx, int rx){
        if(rx - lx == 1) return operations[x];
        int m = (lx + rx) / 2;
        int res;
        if(i < m) res = get(i, 2 * x + 1, lx, m);
        else res = get(i, 2 * x + 2, m, rx);
        return res + operations[x];
    }

    int get(int i) {
        return get(i, 0, 0, size);
    }

};





signed main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen("asd.txt", "r", stdin);
    // freopen("qwe.txt", "w", stdout);

    int n;
    cin >> n;
    int q;
    cin >> q;

    segtree st;
    st.init(n);

    while(q--){
        int c;
        cin>>c;
        if(c==1){
            int l,r, v;
            cin>>l>>r>>v;
            st.add(l,r,v);
            continue;
        }

        int i;
        cin >> i;
        cout << st.get(i) << '\n';


    }
    

    return 0;
}