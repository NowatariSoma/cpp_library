#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(ll i = 0; i < n; ++i)
#define pb push_back
#define all(c) begin(c), end(c)

int N;
deque<double> a, b;

//相関係数：correlation coefficient
double CC(){
  int n = a.size();

  double xav = 0;
  rep(i,n) xav += a[i];
  xav /= n;

  double yav = 0;
  rep(i,n) yav += b[i];
  yav /= n;

  double xy = 0;
  rep(i,n) xy += (a[i]-xav)*(b[i]-yav);

  double x = 0;
  rep(i,n) x += (a[i]-xav)*(a[i]-xav);
  x = sqrt(x);

  double y = 0;
  rep(i,n) y += (b[i]-yav)*(b[i]-yav);
  y = sqrt(y);

  return xy/(x*y);
}

//相関係数の最大値を求める
int main() {
  cin >> N;
  rep(i,N) {
    double val;
    cin >> val;
    a.pb(val);
  }

  b = a;
  reverse(all(b));

  double max_r = -1;
  int idx = 0;

  rep(i,N/2){
    double c = CC();
    if(c > max_r) {
      max_r = c;
      idx = i;
    }
    cout<<c<<endl;
    a.pop_front();
    b.pop_back();
  }

  cout<<"idx : "<<idx<<endl;
  cout<<"max_r : "<<max_r<<endl;

  return 0;
}
