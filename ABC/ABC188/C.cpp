#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
typedef long long ll;

int main()
{
    int N;
    cin >> N;

    int result1=0, result2= 0;
    int max_rate1=0, max_rate2=0;

    int tmp;
    for(int i=0, n=pow(2,N-1); i<n; ++i) {
        cin >> tmp;
        if( tmp > max_rate1 ) {
            max_rate1 = tmp;
            result1 = i+1;
        }
    }
    for(int i=0, n=pow(2,N-1); i<n; ++i) {
        cin >> tmp;
        if( tmp > max_rate2 ) {
            max_rate2 = tmp;
            result2 = i+1 + n;
        }
    }

    cout << (max_rate1>max_rate2 ? result2 : result1) << endl;
    return 0;
}
