#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }

bool isOK(int idx, int key, vector<int> &D){
  if(D[idx] >= key) return true;
  else return false;
}

//めぐる式二分探索
int binary_search(int key, vector<int> &D){
  int left = -1; //leftは条件を満たさない
  int right = D.size(); //right以上は必ず条件を満たす

  while(right-left > 1){
    int mid = left+(right-left)/2;
    if(isOK(mid,key,D)) right = mid;
    else left = mid;
  }
  return right;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> D(n);
  rep(i,n) cin >> D[i];

  sort(all(D));

  //m : この値に近づけたい
  int idx = binary_search(m,D);
  return 0;
}
