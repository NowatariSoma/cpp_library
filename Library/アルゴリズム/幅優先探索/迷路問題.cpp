#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for(ll i = 0; i < n; ++i)
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
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, 1, 0, -1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }

int h, w;
char field[1010][1010];
int dist[1010][1010];

int sy, sx;
int gy, gx;

int meiro() {
  //距離を格納する場所を初期化
  rep(i,h) rep(j,w) dist[i][j] = (1<<21);

  dist[sy][sx] = 0;

  queue<pair<int,int>> que;
  que.push(make_pair(sy, sx));

  while(!que.empty()){
    pair<int,int> v = que.front(); que.pop();
    int y = v.first;
    int x = v.second;

    //printf("%d %d\n", y, x);

    rep(i,4){
      int ny = y + dy4[i];
      int nx = x + dx4[i];

      if(ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
      if(field[ny][nx] == 'X') continue;

      if(dist[ny][nx] == (1<<21)){
        que.push(make_pair(ny, nx));
        dist[ny][nx] = dist[y][x] + 1;
      }
    }
  }
  //rep(i,h) {rep(j,w) printf("%8d ", dist[i][j]); cout<<endl;}

  if(dist[gy][gx] != (1<<21)) return dist[gy][gx];
  else return -1;
}

int main() {
  cin >> h >> w;
  cin >> sy >> sx; sy--, sx--;
  cin >> gy >> gx; gy--, gx--;
  // sy = 0; sx = 0;
  //gy = h-1; gx = w-1;
  rep(i,h) rep(j,w) cin >> field[i][j];

  int keiro = meiro();

  if(keiro == -1) {
    cout<<-1<<endl;
    return 0;
  }
  cout<<keiro<<endl;
  return 0;
}
