#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, N) for (int i = 0; i < (N); ++i)
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

vector<int> isPassed(101010, false);
vector<vector<int>> graph(101010);

// dfs(今いるノード, 一つ前にいたノード)
bool dfs(const int current, const int before) {
  isPassed[current] = true;
  for(int i = 0; i < graph[current].size(); i++) {
    if(graph[current][i] == before) {
      // 前のノードに戻る場合
      continue;
    }
    if(isPassed[ graph[current][i] ]) {
      // 次に行くノードがかこに通ったことがある場合
      return true;
    }
    dfs(graph[current][i], current);
  }
  return false;
}

int main() {

  int n, m;
  cin >> n >> m;

  rep(i, m){
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  bool hasLoop = dfs(0, -1);
  if(hasLoop) {
    cout << "Yes" << endl; //閉路あり
  } else {
    cout << "No" << endl; //閉路なし
  }
}
