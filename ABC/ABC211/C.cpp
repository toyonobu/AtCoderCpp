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
  string S;
  cin >> S;
  map<char, int> ci;
  ci['c']=0;
  ci['h']=1;
  ci['o']=2;
  ci['k']=3;
  ci['u']=4;
  ci['d']=5;
  ci['a']=6;
  ci['i']=7;
  vvi_t memo(8, vi_t(S.size()));
  vi_t  count(8, 0);

  REP(i, S.size()) {
    char ch = S[i];
    ++count[ci[ch]];
    REP(j, 8) {
      memo[j][i] = count[j];
    }
  }

  cout << "c:"; REP(i,S.size()) cout << memo[0][i] << " "; cout << endl;
  cout << "h:"; REP(i,S.size()) cout << memo[1][i] << " "; cout << endl;
  cout << "o:"; REP(i,S.size()) cout << memo[2][i] << " "; cout << endl;
  cout << "k:"; REP(i,S.size()) cout << memo[3][i] << " "; cout << endl;
  cout << "u:"; REP(i,S.size()) cout << memo[4][i] << " "; cout << endl;
  cout << "d:"; REP(i,S.size()) cout << memo[5][i] << " "; cout << endl;
  cout << "a:"; REP(i,S.size()) cout << memo[6][i] << " "; cout << endl;
  cout << "i:"; REP(i,S.size()) cout << memo[7][i] << " "; cout << endl;

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
