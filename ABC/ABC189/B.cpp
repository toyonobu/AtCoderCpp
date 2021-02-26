#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl;
typedef long long ll;

int main()
{
    ll N, X;
    cin >> N >> X;

    ll sum=0;
    ll V, P;
    for (ll i=0; i<N; ++i) {
        cin >> V >> P;
        sum += V * P;
        if( sum > X*100 ) {
            cout << i+1 <<endl;
            return 0;
        }
    }
    cout << -1 <<endl;

    return 0;
}
