#include <bits/stdc++.h>
using namespace std;

#pragma GCC target("avx") // AtCoderはavx2に対応していないので注意
#pragma GCC optimize("O3") // 最適化オプション
#pragma GCC optimize("unroll-loops") // ループ展開
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)


#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define SET_PRECISION(x) cout<< fixed << setprecision((x))
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(x) (x).begin(), (x).end()

using ll = long long;
using vi_t  = vector<int>;
using vvi_t = vector<vector<int> >;
using vl_t  = vector<ll>;
using vvl_t = vector<vector<ll> >;
using pii_t = pair<int, int>;
using pll_t = pair<ll, ll>;

vi_t str2numvec(const std::string& str);
vector<string> split(const string &str, char delim);

bool check(const pii_t& c, const pii_t& d, const vvi_t& P)
{
    if( c.first<0 || c.first>5000 || c.second<0 || c.second>5000) return false;
    if( d.first<0 || d.first>5000 || d.second<0 || d.second>5000) return false;
    if ( !P[c.first][c.second] || !P[d.first][d.second]) return false;

    return true;
}

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  //
  // 2021.06.11
  // 101 MB > 64 MB でなんとMLE, memory 使用率を抑える必要あり
  //
  __MAGIC__;
  int n;
  cin >> n;
  vector<pii_t> v(n);
  vvi_t P(5001, vector<int>(5001));

  for(auto& [x, y] : v) {
    cin >> x >> y;
    P[x][y]=1;
  }
  sort(ALL(v));

  int res=0;
  for(int i=0; i<n-1; ++i) {
    for(int j=i+1; j<n; ++j) {
      auto [ax, ay] = v[i];
      auto [bx, by] = v[j];
      int dx = bx - ax;
      int dy = by - ay;

      pii_t C = make_pair(ax+dy, ay-dx);
      pii_t D = make_pair(ax+dx+dy, ay+dy-dx);
      pii_t E = make_pair(ax-dy, ay+dx);
      pii_t F = make_pair(ax+dx-dy, ay+dy+dx);
      if( check(C, D, P) || check(E, F, P) ) {
        ++res;
      }
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