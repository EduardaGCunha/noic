#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 5*(1e4);
int p[MAXN], n, r[MAXN];

struct graph{
    int a, b, c, idx;
};

void init(){
    for(int i = 0; i <= n; i++){
        p[i] = i;
    }
}

int find(int a){
    return (p[a] == a? a : p[a] = (find(p[a])));
}

bool unite(int a, int b){
    int x = find(a), y = find(b);
    if(x == y) return false;
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]){
        p[y] = x;
        r[x]++;
    }else{
        p[x] = y;
        r[y]++;
    }
    return true;
}

signed main(){
    int m, k; cin >> n >> m >> k;
    vector<graph> g1;
    for(int i = 1; i <= m; i++){
        graph gx; cin >> gx.a >> gx.b >> gx.c;
        gx.idx = i;
        g1.push_back(gx);
    }
    sort(g1.begin(), g1.end(), [&](graph a, graph b){return a.c > b.c;});

    init();
    vector<int> res;
    int cnt = 0;
    //cout << "prints" << endl;
    for(auto &u : g1){
        if(unite(u.a, u.b)){
            u.idx = 0;
            //cout << u.a << " " << u.b << " " << u.c << " " << u.idx << endl;
            if(++cnt == n-1) break;
        }
    }

    for(int i = m-1; i >= 0; --i){
        //cout << g1[i].idx << endl;
        if(k < g1[i].c) break;
        if(!g1[i].idx) continue;
        k -= g1[i].c;
        res.push_back(g1[i].idx);
    }

    sort(res.begin(), res.end());
    cout << res.size() << endl;
    for(auto u : res){
        cout << u << " "; 
    }
    cout << endl;
}