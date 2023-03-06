ll dsu[tam];

int getParent(int x){
    if(dsu[x]<0) return x;
    else return dsu[x] = getParent(dsu[x]);
}

void join(int x, int y){
    x = getParent(x);
    y = getParent(y);
    if(x==y) return;
    if(dsu[x]>dsu[y]) swap(x, y);
    dsu[x] = y;

}



//With structs
struct unionFind {
  vi p;
  unionFind(int n) : p(n, -1) {}
  int findParent(int v) {
    if (p[v] == -1) return v;
    return p[v] = findParent(p[v]);
  }
  bool join(int a, int b) {
    a = findParent(a);
    b = findParent(b);
    if (a == b) return false;
    p[a] = b;
    return true;
  }
};