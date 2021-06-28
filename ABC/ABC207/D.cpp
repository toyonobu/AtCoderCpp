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
const ll INF = (1LL << 61)-1;

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
  int N;
  cin >> N;
  // 複素数平面を利用して解く
  vector<complex<double>> S(N);
  vector<complex<double>> T(N);
  ll real, image;
  REP(i, N) {
    cin >> real >> image;
    S[i] = complex<double>(real, image);
  }
  REP(i, N) {
    cin >> real >> image;
    T[i] = complex<double>(real, image);
  }

  if(N==1) {
    cout << "Yes" << endl;
    return 0;
  }

  // Sの座標を全てS_0からの相対位置に直しておく(=S'とする)
  const auto S0 = S[0];
  for(auto& x : S) x -= S0;

  REP(i, N) {
    REP(j, N) {
      bool found=true;
      if(i==j) continue;
      // S_0, S_1 に対応する T_i, T_jを探す
      if( abs(abs(S[1]) - abs((T[j]-T[i]))) > 1e-5) continue;
      // S → T の回転のための係数
      complex<double> Z = (T[j]-T[i]) / S[1];

      // 全ての S'=S-S0に対して、Tの空間に回転したときに対応する点が存在するか探索
      REP(ii, N) {
        complex<double> rotatedS = Z * S[ii];
        bool localFound=false;
        REP(jj, N) {
          if( abs(rotatedS - (T[jj]-T[i])) < 1e-5 ) {
            localFound = true;
            break;
          }
        }
        if(!localFound) {
          found=false;
          break;
        }
      }// Loop over all "rotated S"
      // 全てのS' = S-S0に対して対応する
      if(found) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;

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
