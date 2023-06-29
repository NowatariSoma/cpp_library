#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1001001;

// a^n mod を計算する
long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long combination(int n, int r){
  if (n == r || r == 0) return 1;
  else return combination(n, r - 1) * (n - r + 1) / r;
}

int main(void) {
  //3^45 mod 1000000007 を計算
  int n;
  cin >> n;
  
  ll ans = 1;
  for(ll i = 1; i <= n; i++) ans *= i%mod;
  ans = ans * modpow(10, n-2, 1000000007)%mod;
  return 0;
}
