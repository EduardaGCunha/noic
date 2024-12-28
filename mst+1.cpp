#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n";

const int MAXN = 2*(1e5);
int p[MAXN], n, r[MAXN];

struct edge{
    int a, b, c, id, d;
    bool operator < (const edge &x) const {
        return c < x.c;
    }
};

void init(){
    for(int i = 0; i <= n; i++){
        p[i] = i;
    }
}

int find(int a){
    return (p[a] == a? a : p[a] = (find(p[a])));
}

void unite(int a, int b){
    int x = find(a), y = find(b);
    if(x == y) return;
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]){
        p[y] = x;
        r[x]++;
    }else{
        p[x] = y;
        r[y]++;
    }
}

signed main(){
    int m, q; cin >> n >> m >> q;

    map<edge, int> mp;
    vector<edge> e;
    for(int i = 0; i < m; i++){
        edge x;
        cin >> x.a >> x.b >> x.c;
        x.d = 0;
        x.id = -1;
        e.push_back(x);
    }

    for(int i = 0; i < q; i++){
        edge x;
        cin >> x.a >> x.b >> x.c;
        x.d = 1;
        x.id = i;
        e.push_back(x);
    }

    sort(e.begin(), e.end());

    init();
    vector<int> ans(q);
    for(auto u : e){
        if(u.d == 0) unite(u.a, u.b);
        else ans[u.id] = (find(u.a) != find(u.b));
    }

    for(auto u : ans){
        cout << (u == 1? "Yes" : "No") << endl;
    }
}