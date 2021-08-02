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
//using mint = modint998244353;
using mint = modint1000000007;
//const ll INF = 1LL << 60;
const ll INF = LLONG_MAX;

template<class T> void print(T x) { cout << x << endl; }
template<class T> void print(const vector<T>& v);

// トポロジカルソート
// DAGから入力次数が0の頂点を1つ取り除いたグラフは
// 必ずDAGであるという性質を利用する
// 計算量：O(|E|+|V|)
vi_t topological_sort(const vvi_t& G) {
  vi_t res;
  const int N = G.size();
  stack<int> S;
  vi_t degree(N, 0);

  // 拡頂点の入力次数を計算 O(|E|)
  for(const auto& edges : G) {
    for(const auto& edge : edges) {
      ++degree[edge];
    }
  }

  // 入力次数 == 0 の頂点を計算 O(|V|)
  REP(i, N) {
    if(degree[i]==0) S.push(i);
  }

  while ( S.size()>0)
  {
    int u = S.top(); S.pop();
    res.emplace_back(u);
    for(const auto& v : G[u]) {
      --degree[v];
      if( degree[v]==0 ) S.push(v);
    }
  }
  return res;
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
  vvi_t G(N);
  REP(i, M) {
    int x, y;
    cin >> x >> y; --x; --y;
    G[x].push_back(y);
  }
  auto ts = topological_sort(G);

  vi_t dp(N, 0);
  for(const auto& from : ts) {
    for(const auto& to : G[from]) {
      chmax(dp[to], dp[from]+1);
    }
  }

  int res=0;
  REP(i, N) chmax(res, dp[i]);
  cout << res << endl;

  return 0;
}

//-----------------------------
// ヘルパー関数群
//-----------------------------
template<class T> void print(const vector<T>& v) {
  for(const auto& x : v) {
    cout << x << " ";
  }
  cout << endl;
}
