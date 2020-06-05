#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

vector<ll> adj[500500];
ll vis[500500], a[500500];

void solve(){
    ll n,  m;
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pair<ll, ll> p[n];
    for(ll i = 0; i < n; i++) cin >> p[i].first, p[i].second = i+1, a[i] = p[i].first;
    sort(p, p+n);
    ll cnt[n];
    for(ll i = 0; i < n; i++) {
        cnt[i] = p[i].second;
        vis[cnt[i]] = 10;
        set<ll> s;
        for(auto &x: adj[cnt[i]]) if(vis[x]) s.insert(a[x-1]);
        if(s.size() + 1 != p[i].first){
            cout << -1 << endl;
            return;
        }
    }
    for(ll i = 0; i < n; i++) cout << cnt[i] << " ";
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  //int t;cin>>t;while(t--)
  solve();
  return 0;
}
