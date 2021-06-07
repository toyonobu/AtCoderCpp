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

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  __MAGIC__;
  int N;
  cin >> N;
  vl_t T(N);

  int sumA=0;
  bitset<100001> v;
  v[0] = 1;
  for(auto& x : T) {
    cin >> x;
    sumA += x;
    v |= (v<<x);
//    cout << "T="<< x << ", sumA="<< sumA << endl;
//    cout << "\t";
//    REP(i, sumA+1) {
//      if(v[i]) cout << i << " ";
//    }
//    cout << endl;
  }

  ll result = LONG_LONG_MAX;
  REP(i, sumA+1) {
    if(v[i]) {
      ll tmp = max(i, sumA-i);
      if( tmp<result ) {
        result = tmp;
      }
    }
  }
  cout << result << endl;

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