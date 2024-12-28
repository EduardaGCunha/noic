#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int p[MAXN], n, m, r[MAXN], low[MAXN];
vector<pair<int, int>> grafo[MAXN];

struct graph{
    int a, b, c;

};

void init(){
    for(int i = 0; i <= n; i++){
        p[i] = i;
        grafo[i].clear();
        r[i] = 0;
        low[i] = INT_MAX;
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

void dfs(int v, int pre){
    for(auto u : grafo[v]){
        if(u.first != pre){
            low[u.first] = min(u.second, low[v]);
            dfs(u.first, v);
        }
    }

    //cout << v << " " << low[v] << endl;
}

int main(){
    int T = 0;
    while(cin >> n >> m && n!= 0 && m != 0){
        vector<graph> g1, g2;
        init();
        for(int i = 0; i < m; i++){
            graph gx; cin >> gx.a >> gx.b >> gx.c;
            gx.c--;
            g1.push_back(gx);
        }
        sort(g1.begin(), g1.end(), [&](graph a, graph b){return a.c > b.c;});
        int ans = 0;
        for(auto u : g1){
            if(unite(u.a, u.b)){
                grafo[u.a].push_back({u.b, u.c});
                grafo[u.b].push_back({u.a, u.c});
            }
        }
        
        int st, ed, t; cin >> st >> ed >> t;
        low[st] = t;
        dfs(st, 0);
        cout << low[ed] << endl;
        cout << "Scenario #" << ++T << endl;
        cout << "Minimum Number of Trips = " << ((t+low[ed]-1)/low[ed])<< endl;
    }

}