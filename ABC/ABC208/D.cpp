#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;

#pragma GCC target("avx") // AtCoderはavx2に対応していないので注意
#pragma GCC optimize("O3") // 最適化オプション
#pragma GCC optimize("unroll-loops") // ループ展開
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)


#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define SET_PRECISION(x) cout<< fixed << setprecision((x))
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()
template<class T>bool chmax(T &a, const T &b) { if (b>a) { a=b; return true; } else return false;}
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } else return false;}

using ll = long long;
using vi_t  = vector<int>;
using vvi_t = vector<vector<int> >;
using vl_t  = vector<ll>;
using vvl_t = vector<vector<ll> >;
using pii_t = pair<int, int>;
using pll_t = pair<ll, ll>;
using mint = modint998244353;
//using mint = modint1000000007;
const ll INF = 1LL << 60;

vi_t str2numvec(const std::string& str);
vector<string> split(const string &str, char delim);
template<class T> void print(T x) { cout << x << endl; }
template<class T> void print(const vector<T>& v);


struct Edge {
    ll to;
    ll cost;
};
using P = pair<long, int>;
using Graph = vector<vector<Edge>>;

//void dijkstra(const Graph &G, int s, vector<long long> &dis, vector<int> &prev) {
ll dijkstra(const Graph &G, ll s, ll t, ll k) {
    int N = G.size();
    vl_t dis(N, INF);
    //prev.resize(N, -1); // 初期化
    priority_queue<P, vector<P>, greater<P>> pq;
    dis[s] = 0;
    pq.emplace(dis[s], s);
    while (!pq.empty()) {
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if (dis[v] < p.first) {
            continue;
        }
        if(v!=s && v!=t && !(v<k) ) continue;
        for (auto &e : G[v]) {
            if (dis[e.to] > dis[v] + e.cost) {
                dis[e.to] = dis[v] + e.cost;
                //prev[e.to] = v; // 頂点 v を通って e.to にたどり着いた
                pq.emplace(dis[e.to], e.to);
            }
        }
    }
    return dis[t] < 1152921504606846970 ? dis[t] : 0;
}

vector<int> get_path(const vector<int> &prev, int t) {
    vector<int> path;
    for (int cur = t; cur != -1; cur = prev[cur]) {
        path.push_back(cur);
    }
    reverse(path.begin(), path.end()); // 逆順なのでひっくり返す
    return path;
}

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  __MAGIC__;
  SET_PRECISION(15);
  int N, M;
  cin >> N >> M;
  Graph G(N, vector<Edge>());
  ll A, B, C;
  REP(i, M) {
    cin >> A >> B >> C;
    G[A-1].push_back(Edge{B-1,C});
  }

  ll res = 0;
  REP(s, N) {
    REP(t, N) {
      if(s==t) continue;
      REP(k, N) {
        res += dijkstra(G, s, t, k+1);
      }
    }
  }
  cout << res << endl;
  //cout << dijkstra(G, 0, 1, 1) << endl;
  //cout << dijkstra(G, 1, 2, 1) << endl;
  //cout << dijkstra(G, 0, 2, 1) << endl;
  //cout << dijkstra(G, 0, 1, 2) << endl;
  //cout << dijkstra(G, 1, 2, 2) << endl;
  //cout << dijkstra(G, 0, 2, 2) << endl;
  //cout << dijkstra(G, 0, 1, 3) << endl;
  //cout << dijkstra(G, 1, 2, 3) << endl;
  //cout << dijkstra(G, 0, 2, 3) << endl;

  return 0;
}

//-----------------------------
// ヘルパー関数群
//-----------------------------
vi_t str2numvec(const std::string& str)
{
  vi_t v(str.size());
  for(int i=0, n=str.size(); i<n; ++i) {
      v[i] = str[i] - '0';
  }
  return v;
}

vector<string> split(const string &str, char delim)
{
  vector<string> res;
  size_t current = 0, found;
  while((found = str.find_first_of(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}

template<class T> void print(const vector<T>& v) {
  for(const auto& x : v) {
    cout << x << " ";
  }
  cout << endl;
}
