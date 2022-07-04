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

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  __MAGIC__;
  SET_PRECISION(15);
  int A, B;
  cin >> A >> B;

  int res= (B-1 +(A-1)-1)/(A-1);
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
