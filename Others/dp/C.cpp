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

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  __MAGIC__;
  SET_PRECISION(15);
  int N;
  cin >> N;
  vi_t a(N);
  vi_t b(N);
  vi_t c(N);
  REP(i, N) {
    cin >> a[i] >> b[i] >> c[i];
  }

  vvl_t dp(N, vl_t(3,0));
  dp[0][0] = a[0];
  dp[0][1] = b[0];
  dp[0][2] = c[0];

  for(int i=1; i<N; ++i) {
    dp[i][0] = max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
    dp[i][1] = max(dp[i-1][0]+b[i], dp[i-1][2]+b[i]);
    dp[i][2] = max(dp[i-1][0]+c[i], dp[i-1][1]+c[i]);
  }
  cout << max(dp[N-1][0], max(dp[N-1][1], dp[N-1][2])) << endl;

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
