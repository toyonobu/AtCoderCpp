#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)
#define SET_PRECISION(x) cout<< fixed << setprecision((x))

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
    vi_t need;
    vi_t deny;


    std::string s;
    cin >> s;

    for(int i=0; i<10; ++ i) {
        if( s[i] == 'o') need.push_back(i);
        if( s[i] == 'x') deny.push_back(i);
    }

    int result = 0;

    for(int i=0; i<10000; ++i) {
        s = "";
        if(i<10) s+="0";
        if(i<100) s+="0";
        if(i<1000) s+="0";
        s += std::to_string(i);
        auto v = str2numvec(s);

        if( std::find(deny.begin(), deny.end(), v[0]) != deny.end()) continue;
        if( std::find(deny.begin(), deny.end(), v[1]) != deny.end()) continue;
        if( std::find(deny.begin(), deny.end(), v[2]) != deny.end()) continue;
        if( std::find(deny.begin(), deny.end(), v[3]) != deny.end()) continue;

        bool found=false;
        for(auto x : need) {
            if( std::find(v.begin(), v.end(), x) == v.end()) found=true;
        }
        if(found) continue;

        ++result;
    }

    cout<< result << endl;

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