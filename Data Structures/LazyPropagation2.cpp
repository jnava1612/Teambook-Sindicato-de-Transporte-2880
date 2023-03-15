//replace the values and add in the range sum query
struct segtree {
    int size;
    vi operations;
    vi values;

    int NEUTRAL_ELEMENT = 0;
    int NO_OPERATION = LLONG_MAX - 1;

    int modify_op(int a, int b, int len) {
        if(b == NO_OPERATION) return a;
        return b * len;
    }
    int calc_op(int a, int b) {
        return a + b;
    }

    void apply_op(int &a, int b, int len) {
        a = modify_op(a, b, len);
    }

    // void build(int x, int lx, int rx) {
    //     if (rx - lx == 1) {
    //         values[x] = 1;
    //         return;
    //     }
    //     int m = (lx + rx) / 2;
    //     build(2 * x + 1, lx, m);
    //     build(2 * x + 2, m, rx);
    //     values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
    // }

    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        operations.assign(2 * size, 0LL);
        values.assign(2 * size, 0LL);
        // build(0, 0, size);
    }

    void propagate(int x, int lx, int rx){
        if(rx - lx == 1) return;
        int m = (lx + rx) / 2;
        apply_op(operations[2 * x + 1], operations[x], 1);
        apply_op(operations[2 * x + 2], operations[x], 1);
        apply_op(values[2 * x + 1], operations[x], m-lx);
        apply_op(values[2 * x + 2], operations[x], rx-m);
        operations[x] = NO_OPERATION;
    }

    //From here the code is the same

    void modify(int l, int r, int v, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(lx >= r || l >= rx) return;
        if(lx >= l && rx <= r) {
            apply_op(operations[x], v, 1);
            apply_op(values[x], v, rx - lx);
            return;
        }
        int m = (lx + rx) / 2;
        modify(l, r, v, 2 * x + 1, lx, m);
        modify(l, r, v, 2 * x + 2, m, rx);
        values[x] = calc_op(values[2 * x + 1], values[2 * x + 2]);
    }

    int calc(int l, int r, int x, int lx, int rx){
        propagate(x, lx, rx);
        if(lx >= r || l >= rx) return NEUTRAL_ELEMENT;
        if(lx >= l && rx <= r) return values[x];
        int m = (lx + rx) / 2;
        auto s1 = calc(l, r, 2 * x + 1, lx, m);
        auto s2 = calc(l, r, 2 * x + 2, m, rx);
        return calc_op(s1, s2);
    }

    int calc(int l, int r){
        return calc(l, r, 0, 0, size);
    }

    void modify(int l, int r, int v) {
        modify(l, r, v, 0, 0, size);
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
            st.modify(l,r,v);
            continue;
        }

        int l,r;
        cin >> l >> r;
        cout << st.calc(l,r) << '\n';
    }
    

    return 0;
}