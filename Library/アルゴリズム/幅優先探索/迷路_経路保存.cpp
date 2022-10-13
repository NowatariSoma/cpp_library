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

//https://atcoder.jp/contests/abc051/tasks/abc051_c

int sy, sx, gy, gx;

int h = 2200, w = 2200;
//0 : 通行可能
//1 : 通行不可能
int f[2200][2200];

void search(int sy, int sx, int gy, int gx) {
  // 各セルの最短距離 (訪れていないところは -1 としておく)
  vector<vector<int> > dist(h, vector<int>(w, -1));
  dist[sy][sx] = 0;

  vector<vector<int>> px(h, vector<int>(w, -1));
  vector<vector<int>> py(h, vector<int>(w, -1));

  queue<pair<int,int>> que;
  que.push({sy,sx});

  /* キューが空になるまで */
  while (!que.empty()) {
    pair<int, int> now = que.front(); que.pop();
    int y = now.first;
    int x = now.second;
    if(y == gy && x == gx) break;

    // 隣接頂点を探索
    for (int i = 0; i < 4; ++i) {
      int ny = y + dy4[i];
      int nx = x + dx4[i];
      if (nx < 0 || nx >= 2200 || ny < 0 || ny >= 2200) continue;
      if (f[ny][nx] == 1) continue; // 壁はダメ

      // まだ見ていない頂点なら push
      if (dist[ny][nx] == -1) {
        que.push({ny,nx});
        dist[ny][nx] = dist[y][x] + 1;
        py[ny][nx] = y;
        px[ny][nx] = x;
      }
    }
  }
  /* ゴールに至るまでの最短経路を復元してみる */
  vector<char> ans;
  int y = gy, x = gx;
  while (x != -1 && y != -1) {
    f[y][x] = 1; // 通過したことを示す

    // 前の頂点へ行く
    int tmpx = px[y][x];
    int tmpy = py[y][x];

    char d[4] = {'R', 'U', 'L', 'D'};
    for(int i = 0; i < 4; i++){
      if(dx4[i] == x-tmpx && dy4[i] == y-tmpy) {
        ans.pb(d[i]);
      }
    }
    x = tmpx, y = tmpy;
  }
  for(int i = 0; i < ans.size(); i++){
    cout<<ans[i];
  }
  // cout<<endl;
  // for(int i = 1098; i < 1110; i++){
  //   for(int j = 1098; j < 1110; j++){
  //     cout<<f[i][j];
  //   }
  //   cout<<endl;
  // }
  f[sy][sx] = 0, f[gy][gx] = 0;
}

int main(){
  cin >> sx >> sy >> gx >> gy;
  sx += 1100, sy += 1100, gx += 1100, gy += 1100;

  search(sy, sx, gy, gx);
  f[sy][sx] = 0, f[gy][gx] = 0;
  return 0;
}
