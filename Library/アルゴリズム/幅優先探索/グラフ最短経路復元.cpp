#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define frep(i, a, b) for(ll i = a; i < b; ++i)
#define drep(i, a, b) for(ll i = a; i >= b; --i)
#define all(c) begin(c), end(c)
#define drop(s) cout << #s << endl, exit(0)
#define endl '\n'
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
const int inf = 1001000110;
const ll ll_inf = 1LL << 60;
const int mod = 998244353;
const int dx4[4] = {1, 0, -1, 0};
const int dy4[4] = {0, -1, 0, 1};
const int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy8[8] = {0, -1, -1, -1, 0, 1, 1, 1};
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a = b; return 1; } return 0; }
template<typename T>ostream &operator<<(ostream &os,const vector<T>&v){os<<"{";for(int i=0;i<v.size();i++){os<<v[i]<<(i+1==v.size()?"":", ");}os<<"}";return os;}
template<typename T,typename U>ostream &operator<<(ostream &os,pair<T,U>&p){os<<"("<<p.first<<", "<<p.second<<")";return os;}
template<typename T,typename U>ostream &operator<<(ostream &os,map<T,U>&m){os<<"{";for(auto itr = m; itr != m.end(); itr++) {os << *itr;itr++;if (itr != m.end()) os << ", ";itr--;}os << "}";return os;}
template<typename T>ostream &operator<<(ostream &os, set<T> &set_var){os<<"{";for(auto itr = set_var; itr != set_var.end(); itr++) {os << *itr;itr++;if (itr != set_var.end()) os << ", ";itr--;}os << "}";return os;}
void dump_func(){cout<<" }"<<endl;}
template <class Head, class... Tail>void dump_func(Head &&head,Tail &&... tail){cout<<head;if(sizeof...(Tail)>0){cout << ",";}dump_func(std::move(tail)...);}
#define dump(...) cout<<string(#__VA_ARGS__)<<": "<<"["<<to_string(__LINE__)<<":"<<__FUNCTION__<<"] = { ",dump_func(__VA_ARGS__)

int n;
vector<int> c;
vector<vector<int>> g;
vector<int> d;
vector<int> p;

void bfs(int s) {
	queue<int> que;
	rep(i,n) d[i] = inf;
	p = vector<int>(n, -1);

	que.push(s);
	d[s] = 0;

	while(!que.empty()) {
		int v = que.front(); que.pop();

		for(int j = 0; j < g[v].size(); j++) {
			int nv = g[v][j];
			if(d[nv] == inf) {
				que.push(nv);
				d[nv] = d[v] + 1;
				p[nv] = v;
			}
		}
	}
}

vector<int> get_path(int t) {
	vector<int> path;
	for(; t != -1; t = p[t]) path.push_back(t);
	reverse(path.begin(), path.end());
	return path;
}

int main(){
	cin >> n;
	g = vector<vector<int>>(n);
	d = vector<int>(n);
	p = vector<int>(n);
	c = vector<int>(n);
	rep(i,n) cin >> c[i];
	rep(i,n-1) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		g[a].pb(b);
		g[b].pb(a);
	}

	bfs(0);
	for(int i = 0; i < n; i++) {
		vector<int> tmp = get_path(i);
		int flag = 1;
		rep(j,tmp.size()) {
			if(i == tmp[j]) continue;
			int soma = c[tmp[j]];
			if(c[i] == soma) flag = 0;
		}
		if(flag) cout<<i+1<<endl;
	}
	return 0;
}
