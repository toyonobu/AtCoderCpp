#include <bits/stdc++.h>
using namespace std;

#define PRINT_JesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_JESNO(condition) cout<<((condition)?"YES":"NO")<<endl
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

const bool LOCAL_TEST=true;

string getPath(int s_i, int s_j, int t_i, int t_j);

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
    __MAGIC__;

    if(LOCAL_TEST) {
        vvi_t H(30);
        vvi_t V(29);
        for(auto& v : H) {
            v.resize(29);
            for(auto& x : v) cin >> x;
        }
        for(auto& v : V) {
            v.resize(30);
            for(auto& x : v) cin >> x;
        }

//        cout << "holizonal distances" <<endl;
//        for(auto& v : H) {
//            for(auto& x : v) cout << x <<", ";
//            cout << endl;
//        }
//        cout << "vertical distances" <<endl;
//        for(auto& v : V) {
//            for(auto& x : v) cout << x <<", ";
//            cout << endl;
//        }
    }



    //cout << "\nStart Iteration"<<std::endl;
    int s_i, s_j, t_i, t_j, a;
    double e;
    int result;
    double score;
    for(int iTest=0; iTest<1000; ++iTest) {
        if( LOCAL_TEST ) {
            cin >> s_i >> s_j  >> t_i >> t_j >> a >> e;
            //cout << "(" << s_j << "," << s_i <<"), "
            //     << "(" << t_j << "," << t_i <<"), "
            //     << a << ", " << e << endl;
//
            //cout << "Path -> ";
        } else {
            cin >> s_i >> s_j  >> t_i >> t_j;
        }
        auto path = getPath(s_i, s_j, t_i, t_j);
        cout << path << endl;

        if( LOCAL_TEST ) {
            double b = a;
            score = score * 0.998 + a/b;
            result = round( b * e );
        } else {
            cin >> result;
        }
    }
    if( LOCAL_TEST ) {
        //cout << round( 2312311 * score ) << endl;
    }

    return 0;
}

string getPath(int s_i, int s_j, int t_i, int t_j) {
    string path;

    double dx = t_i - s_i;
    double dy = t_j - s_j;

    for(int i=0, n=std::abs(dy); i<n; ++i) path += ( dx < 0 ? "L" : "R");
    for(int i=0, n=std::abs(dx); i<n; ++i) path += ( dy < 0 ? "U" : "D");

    return path;
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