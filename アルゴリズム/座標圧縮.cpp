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
const int mod = 998244353;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, -1, 0, 1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
template<typename T>ostream &operator<<(ostream &os,const vector<T>&v){os<<"{";for(int i=0;i<v.size();i++){os<<v[i]<<(i+1==v.size()?"":", ");}os<<"}";return os;}
template<typename T,typename U>ostream &operator<<(ostream &os,pair<T,U>&p){os<<"("<<p.first<<", "<<p.second<<")";return os;}
template<typename T,typename U>ostream &operator<<(ostream &os,map<T,U>&m){os<<"{";for(auto itr = m; itr != m.end(); itr++) {os << *itr;itr++;if (itr != m.end()) os << ", ";itr--;}os << "}";return os;}
template<typename T>ostream &operator<<(ostream &os, set<T> &set_var){os<<"{";for(auto itr = set_var; itr != set_var.end(); itr++) {os << *itr;itr++;if (itr != set_var.end()) os << ", ";itr--;}os << "}";return os;}
void dump_func(){cout<<" }"<<endl;}
template <class Head, class... Tail>void dump_func(Head &&head,Tail &&... tail){cout<<head;if(sizeof...(Tail)>0){cout << ",";}dump_func(std::move(tail)...);}
#define dump(...) cout<<string(#__VA_ARGS__)<<": "<<"["<<to_string(__LINE__)<<":"<<__FUNCTION__<<"] = { ",dump_func(__VA_ARGS__)

int main() {
  // 入力
  int H, W, N;
  cin >> H >> W >> N;
  vector<int> X(N), Y(N);
  for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

  // 座標圧縮の準備
  auto nX = X, nY = Y;
  sort(nX.begin(), nX.end());
  nX.erase(unique(nX.begin(), nX.end()), nX.end());
  sort(nY.begin(), nY.end());
  nY.erase(unique(nY.begin(), nY.end()), nY.end());

  // 座標圧縮
  for (int i = 0; i < N; ++i) {
    int xres = lower_bound(nX.begin(), nX.end(), X[i]) - nX.begin();
    int yres = lower_bound(nY.begin(), nY.end(), Y[i]) - nY.begin();
    cout << xres+1 << " " << yres+1 << endl;
  }
}
