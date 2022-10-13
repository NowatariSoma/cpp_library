#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int inf = 100100101;
const ll ll_inf = 1e9+7;
const int mod = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }

//https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a#4-%E7%B4%AF%E4%B9%97-an

// a^n mod を計算する
ll modpow(ll a, ll n, int mod) {
  ll res = 1;
  while (n > 0) {
    if (n & 1) res = res * a % mod;
    a = a * a % mod;
    //cout<<bitset<8>(n)<<" ";
    //桁全体を右にずらす
    n >>= 1;
    //cout<<bitset<8>(n)<<endl;
  }
  return res;
}

int main() {
  int a, b;
  cin >> a >> b;
  // a^b mod. 1000000007 を計算してみる
  cout << modpow(a, b, 1000000007) << endl;
}
