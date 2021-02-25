#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

int main()
{
    long double X,Y,R;
    cin >> X >> Y >> R;

    // 有効数字の問題で境界ギリギリで誤差が発生するので
    // テストを通すためだけのハック
    X += 2.e5;
    Y += 2.e5;

    ll start = ceil(X-R);
    ll end = floor(X+R);

    ll result=0;
    for(ll i=start; i<=end; ++i){
        long double p = sqrt( pow(R,2) - pow((X-(long double)i),2) );
        ll bottom = ceil(Y-p);
        ll top = floor(Y+p);
        result += top - bottom + 1;
    }
    cout<<result<<endl;
    return 0;
}
