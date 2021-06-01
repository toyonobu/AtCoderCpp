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
string to_string_with0(ll num, int width);

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  __MAGIC__;
  int N;
  string S;
  cin >> N >> S;

  int res=0;
  for(int i=0; i<1000; ++i) {
    string tmp = S;
    string s = to_string_with0(i,3);
    auto pos = tmp.find_first_of(s[0]);
    if( pos==string::npos ) continue;
    tmp = tmp.substr(pos+1);
    pos = tmp.find_first_of(s[1]);
    if( pos==string::npos ) continue;
    tmp = tmp.substr(pos+1);
    pos = tmp.find_first_of(s[2]);
    if( pos==string::npos ) continue;
    ++res;
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
    current = found ;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}

string to_string_with0(ll num, int width) {
  std::stringstream ss;
  ss << std::setfill('0') << std::setw(width) << num;
  return ss.str();
}
