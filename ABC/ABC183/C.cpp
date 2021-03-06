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
    ll N, K, tmp;
    cin >> N >> K;

    vector<vector<ll> > d(N);
    for (int i=0; i<N; ++i) {
        d[i] = std::vector<ll>(N);
        for (int j=0; j<N; ++j) {
            cin >> tmp;
            d[i][j] = tmp;
        }
    }

    vector<int> v(N-1);
    for(int i=1; i<N; ++i) {
        v[i-1]=i+1;
    }


    int result=0;
    do {
        ll sum=0;
        int now = 1;
        for(auto& x :v) {
            sum += d[now-1][x-1];
            now = x;
        }
        sum += d[now-1][0];

        if ( sum == K ) ++result;

    } while( next_permutation(v.begin(), v.end()) );

    cout << result << endl;

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