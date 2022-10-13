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

//https://marycore.jp/prog/cpp/print-binary-octal-decimal-hex/

int main() {
  cout<<showbase;           //数字の先頭に基数を表す記号（0x, 0）が付与されます。
  cout<<hex<<16<<endl;      //10(16進数)
  cout<<dec<<9<<endl;       //9(10進数)
  cout<<oct<<9<<endl;       //11(8進数)
  cout<<bitset<8>(9)<<endl; //00001001(2進数)
  cout<<noshowbase;         //解除
  return 0;
}
