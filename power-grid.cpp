#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n";

const int MAXN = 2*(1e3)+7;
int p[MAXN], n, r[MAXN];

struct edge{
    int a, b, c;
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
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
    }
    int p[n], k[n]; 
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    for(int i = 0; i < n; i++){
        cin >> k[i];
    }

    vector<edge> e;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            edge x; 
            if(i == j){
                x.a = 0;
                x.b = i+1;
                x.c = p[i];
            }else{
                x.a = i+1;
                x.b = j+1;
                x.c = (k[i]+k[j])*(abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second));
            }
            e.push_back(x);
        }
    }

    init();
    sort(e.begin(), e.end());
    int ans = 0;
    vector<int> st;
    vector<pair<int, int>> graph;
    for(auto u : e){
        //cout << u.c << endl;
        if(unite(u.a, u.b)){
            ans += u.c;
            if(u.a == 0) st.push_back(u.b);
            else graph.push_back({u.a, u.b});
        }
    }

    cout << ans << endl;
    cout << st.size() << endl;
    for(auto u : st){
        cout << u << " ";
    }
    cout << endl; 
    cout << graph.size() << endl;
    for(auto u : graph){
        cout << u.first << " " << u.second << endl;
    }

}