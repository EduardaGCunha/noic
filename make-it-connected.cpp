#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n";

const int MAXN = 2*(1e5);
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
    int m; cin >> n >> m;
    int arr[n];
    int low = INT_MAX, idx = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(arr[i] < low){
            low = arr[i];
            idx = i;
        }
    }
    
    vector<edge> e;
    for(int i = 0; i < n; i++){
        if(i == idx) continue;
        edge x; 
        x.a = idx+1;
        x.b = i+1;
        x.c = arr[idx] + arr[i];
        e.push_back(x);
    }

    for(int i = 0; i < m; i++){
        edge x;
        cin >> x.a >> x.b >> x.c;
        e.push_back(x);
    }

    sort(e.begin(), e.end());

    init();
    int ans = 0;
    for(auto u : e){
        if(unite(u.a, u.b)){
            ans += u.c;
        }
    }

    cout << ans << endl;
}