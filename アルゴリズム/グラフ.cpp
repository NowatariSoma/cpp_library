#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define fi first
#define se second
#define all(c) begin(c), end(c)
#define drop(s) cout << #s << endl, exit(0)
#define endl '\n'
using Graph = vector<vector<int>>;
const int inf = 1001001011;
const ll ll_inf = 1e18;
const int mod = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }

vector<bool> seen;
vector<int> iki;
vector<int> kaeri;

int tmp = 0;

void dfs(const Graph &G, int i){
  tmp++;
  seen[i] = true;
  iki[i] = tmp;

  for(auto x : G[i]) {
    if(seen[x]) continue;
    dfs(G, x);
  }
  tmp++;
  kaeri[i] = tmp;
}

int main() {
  int n;
  cin >> n;
  vector<vector<int>> G(n+1);
  rep(i,n) {
    int m, k;
    cin >> m >> k;
    rep(j,k){
      int a;
      cin >> a;
      G[m].pb(a);
    }
  }

  for(int i = 1; i <= n; i++){
    cout<<"G["<<i<<"] = {";
    for(auto x : G[i]){
      cout<<x<<", ";
    }
    cout<<"}"<<endl;
  }




  seen.assign(n+1, false);
  iki.resize(n+1);
  kaeri.resize(n+1);
  dfs(G, 1);

  for(int i = 1; i <= n; i++){
    cout<<i<<" "<<iki[i]<<" "<<kaeri[i]<<endl;
  }

  return 0;
}
