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

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  __MAGIC__;
  ll A, B, C, D;
  cin >> A >> B >> C >> D;

  ll res = -1;

  for(int i=1; i<10000000; ++i) {
    if( A + B*i <= D * C * i) {
        res = i;
        break;
    }
  }
  cout << res << endl;

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