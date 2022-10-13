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

//https://qiita.com/drken/items/a14e9af0ca2d857dad23

bool is_prime(ll N) {
  if (N == 1) return false;
  for (ll i = 2; i * i <= N; ++i) {
    if (N % i == 0) return false;
  }
  return true;
}

int main() {
  ll n;
  cin >> n;
  if (is_prime(n)) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}
