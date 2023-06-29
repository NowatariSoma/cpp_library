#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int inf = 100100101;
const int mod = 1000000007;
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }

//next_permutation
int main(){
  // vector<int> v={1,2,3,4};//変える
  int tmp = 1;
  vector<string> v={"a","a","a","a","a","a","b", "b","b"};
  do{
    for(int i = 0; i < v.size(); i++){
      cout<<v[i];
      cout<<" ";
    }
    cout<<tmp;
    cout<<endl;
    tmp++;
  } while (next_permutation(v.begin(),v.end()));
  return 0;
}
