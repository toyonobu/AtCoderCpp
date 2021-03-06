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

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
    __MAGIC__;
    int N;
    cin >> N;
    ll minA = 1000000;
    ll minB = 1000000;
    int iA=0;
    int iB=0;
    ll min2A = 2000000;
    ll min2B = 2000000;
    ll A, B;

    for(int i=0; i<N; ++i) {
        cin >> A >> B;
        if( A <= minA ) {
            min2A = minA;
            minA = A;
            iA = i+1;
        }
        if( B <= minB ) {
            min2B = minB;
            minB = B;
            iB = i+1;
        }
    }
    if( iA!=iB ) {
        cout << max(minA, minB) << endl;
    } else {
        if( ((minA+minB) < max(minA, min2B)) && ((minA+minB) < max(min2A, minB)) ) {
            cout << minA+minB <<endl;
        } else {
            cout << min(max(minA, min2B), max(min2A, minB)) <<endl;
        }
    }


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