#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
int p[MAXN], n, r[MAXN];

struct graph{
    int a, b, c;

};

void init(){
    for(int i = 0; i < n; i++){
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

int main(){
    int f, r; cin >> n >> f >> r;
    vector<graph> g1, g2;
    for(int i = 0; i < f; i++){
        graph gx; cin >> gx.a >> gx.b >> gx.c;
        g1.push_back(gx);
    }
    sort(g1.begin(), g1.end(), [&](graph a, graph b){return a.c < b.c;});
    for(int i = 0; i < r; i++){
        graph gx; cin >> gx.a >> gx.b >> gx.c;
        g2.push_back(gx);
    }
    sort(g2.begin(), g2.end(), [&](graph a, graph b){return a.c < b.c;});

    init();
    int ans = 0;
    for(auto u : g1){
        if(unite(u.a, u.b)){
            ans += u.c;
        }
    }
    for(auto u : g2){
        if(unite(u.a, u.b)){
            ans += u.c;
        } 
    }

    cout << ans << endl;
}