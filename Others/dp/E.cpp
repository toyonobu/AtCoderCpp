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


ll knapsack(const vector<pii_t>& v, int w){
  int n = v.size();
  int max_value = n * 1000;
  vvl_t dp(n+1, vl_t(max_value+1, INT_MAX));
  dp[0][0] = 0;
  REP(i, n) {
    REP(j, max_value+1) {
      chmin(dp[i+1][j], dp[i][j]);//i番目の商品を追加しない場合
      chmin(dp[i+1][j+v[i].second], dp[i][j]+v[i].first);//i番目の商品を追加したら得か？
    }
  }

  int res=0;
  REP(val, max_value+1) {
    if(dp[n][val] <= w) chmax(res, val);
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
  int N, W;
  cin >> N >> W;
  vector<pii_t> v(N);
  for(auto& [a, b] : v) cin >> a >> b;
  
  cout << knapsack(v, W) << endl;

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
