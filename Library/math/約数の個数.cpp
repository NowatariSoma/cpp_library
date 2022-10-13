#include <bits/stdc++.h>
using namespace std;

int prime_factorize(long long N) {
  vector<pair<long long,long long>> res;
  for (long long a = 2; a <= N; ++a) {
    if (N % a != 0) continue;
    long long ex = 0;
    while (N % a == 0) {
      ++ex;
      N /= a;
    }
    res.push_back({a, ex});
  }
  if (N != 1) res.push_back({N, 1});
  long long re = 1;
  for (auto p : res) re *= p.second + 1;
  return re;
}

int main() {
  long long N;
  cin >> N;
  long long res = prime_factorize(N);
  cout << res << endl;
}
