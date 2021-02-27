#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
#define __MAGIC__ ios::sync_with_stdio(false);cin.tie(nullptr)
#define SET_PRECISION(x) cout<< fixed << setprecision((x))

typedef long long ll;
string dec2Naray(ll x, int n);

//=====================//
//  メ  イ  ン  関  数  //　
//=====================//
int main()
{
    __MAGIC__;
    int N;
    cin >> N;
    vector<int> v(N);
    for(auto& x : v) cin >> x;

    int n_gcd=0;
    int max_gcd=0;
    int result=0;
    int max_itr = *max_element(v.begin(), v.end());
    for(int k=2; k<=max_itr; ++k) {
        n_gcd=0;
        for (auto& x :v) {
            if( x%k == 0) {
                ++n_gcd;
            }
        }
        if(n_gcd > max_gcd) {
            max_gcd = n_gcd;
            result=k;
        }
    }
    cout<<result<<endl;

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