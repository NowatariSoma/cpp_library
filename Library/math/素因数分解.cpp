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

vector<pair<long long, long long> > prime_factorize(long long N) {
  vector<pair<long long, long long> > res;
  for (long long a = 2; a * a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0; // 指数
    // 割れる限り割り続ける
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    // その結果を push
    res.push_back({a, ex});
  }
  // 最後に残った数について
  if (N != 1) res.push_back({N, 1});
  return res;
}

int main() {
  long long N;
  cin >> N;
  const auto &res = prime_factorize(N);
  cout << N << ":";
  for (auto p : res) {
    for (int i = 0; i < p.second; ++i) cout << " " << p.first;
  }
  cout << endl;
}
