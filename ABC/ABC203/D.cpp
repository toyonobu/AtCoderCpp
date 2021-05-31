#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)
#define SET_PRECISION(x) cout<< fixed << setprecision((x))
#define REP(i, n) for (int i = 0; i < (int)(n); i++)

typedef long long ll;
typedef vector<int> vi_t;
typedef vector<vector<int> > vvi_t;
typedef vector<ll> vl_t;
typedef vector<vector<ll> > vvl_t;

vi_t str2numvec(const std::string& str);
vector<string> split(const string &str, char delim);

ll median(const vl_t& window, int K) {
  auto v = window;
  sort( v.rbegin(), v.rend() );
  int index = K*K/2;
  return v[index];
}

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
  __MAGIC__;
  ll N, K;
  cin >> N >> K;
  vvl_t A(N);
  for(auto& v : A) {
    v.resize(N);
    for(auto& x : v) cin >> x;
  }

  //for(auto v : A) {
  //  for(auto x : v) cout << x << " ";
  //  cout << endl;
  //}

  vl_t center;
  vl_t window;
  window.reserve(K*K);


  for(int i=0; i<K; ++i) {
    for(int j=0; j<K; ++j) {
      window.push_back(A[i][j]);
    }
  }

  for(auto x : window) cout << x << " ";
  cout << endl;

  //}  //for(int di=0; di<=N-K; ++di) {
  //  for(int dj=0; dj<=N-K; ++dj) {
  //    window.clear();
  //    for(int i=di; i<K+di; ++i) {
  //      for(int j=dj; j<K+dj; ++j) {
  //        window.push_back(A[i][j]);
  //      }
  //    }
  //    center.push_back( median(window, K) );
  //  }
  //}
  //std::sort(center.begin(), center.end());
  //cout << center[0] << endl;

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

vector<string> split(const string &str, char delim){
  vector<string> res;
  size_t current = 0, found;
  while((found = str.find_first_of(delim, current)) != string::npos){
    res.push_back(string(str, current, found - current));
    current = found + 1;
  }
  res.push_back(string(str, current, str.size() - current));
  return res;
}