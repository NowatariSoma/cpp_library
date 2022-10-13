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

int main() {
  int n = 3;
  // {0, 1, ..., n-1} の部分集合の全探索
  for(int bit = 0; bit < (1<<n); bit++) {
    vector<int> s(n);
    for(int i = 0; i < n; ++i) {
      if(bit & (1<<i)) { // 列挙に i が含まれるか
        s[i] = 1;
      }
    }

    for(int i = 0; i < (int)s.size(); ++i) {
      cout<<s[i]<<" ";
    }
    cout<<endl;
  }
}
