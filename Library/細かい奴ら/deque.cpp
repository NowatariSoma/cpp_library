#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define rep2(i, a, b) for(ll i = a; i <= b; ++i)
#define rep3(i, a, b) for(ll i = a; i >= b; --i)
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
#define SUM(v) accumulate(all(v), 0LL)
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define drop(s) cout << #s << endl, exit(0)
#define endl '\n'
using Graph = vector<vector<int>>;
const int inf = 100100101;
const ll ll_inf = 1e18;
const int mod = 1000000007;
template <class T> using vc = vector<T>;
template <class T> using vvc = vector<vc<T>>;
template <class T> using vvvc = vector<vvc<T>>;
template <class T> using vvvvc = vector<vvvc<T>>;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }

int main() {
  deque<int> deq;

  deq.push_front(1);
  for(auto x : deq) cout<<x<<", ";cout<<endl;

  deq.push_back(2);
  for(auto x : deq) cout<<x<<", ";cout<<endl;

  deq.push_back(3);
  for(auto x : deq) cout<<x<<", ";cout<<endl;

  deq.pop_front();
  for(auto x : deq) cout<<x<<", ";cout<<endl;

  deq.pop_back();
  for(auto x : deq) cout<<x<<", ";cout<<endl;

  deque<int> que;
  for(auto x : que) cout<<x<<endl;
  return 0;
}
