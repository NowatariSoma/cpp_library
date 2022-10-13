#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define frep(i, a, b) for(ll i = a; i < b; ++i)
#define drep(i, a, b) for(ll i = a; i >= b; --i)
#define all(c) begin(c), end(c)
#define drop(s) cout << #s << endl, exit(0)
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
using Graph = vector<vector<int>>;
const int inf = 1001000110;
const ll ll_inf = 1e18;
const int mod = 1000000007;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }

vector<vector<int>> to;

vector<int> ans;
void dfs(int v, int p = -1){
  ans.pb(v);
  for(auto nv : to[v]){
    if(nv == p) continue;
    dfs(nv,v);
    ans.pb(v);
  }
}

int main(){
  int n;
  cin >> n;
  to.resize(n);
  rep(i,n-1) {
    int a, b; cin >> a >> b;
    a--, b--;
    to[a].pb(b);
    to[b].pb(a);
  }

  rep(i,n) sort(all(to[i]));

  dfs(0);

  for(int v : ans) cout<<v+1<<" "; cout<<endl;
  return 0;
}
