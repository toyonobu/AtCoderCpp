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

string dec2Naray(ll x, int n);
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
    int Tpre=0;
    int Xpre=0;
    int Ypre=0;
    int T, X, Y;

    for(int i=0; i<N; ++i) {
        cin >> T >> X >> Y;
        int dt = T-Tpre; Tpre = T;
        int dx = std::abs(X-Xpre); Xpre = X;
        int dy = std::abs(Y-Ypre); Ypre = Y;
        if( dx + dy > dt ) {
            cout<<"No"<<endl;
            return 0;
        } else if ( (dt-dx-dy)%2 ) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}

//-----------------------------
// ヘルパー関数群
//-----------------------------
string dec2Naray(ll x, int n)
{
    // 10進数 → n進数 変換を行う
    // 9進数までにしか対応してないので注意
    // 16進数ぐらいまでは拡張した方が良さそう
    // n進数 → 10進数 変換も用意すべき
    string s;
    while( x ) {
        s = to_string(x%n) + s;
        x /= n;
    }
    return s;
}

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