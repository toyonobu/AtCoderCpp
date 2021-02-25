#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl;
typedef long long ll;

int main()
{
    array<int, 3> a;
    for (int i=0; i<3; ++i) {
        cin >> a[i];
    }
    if( count(a.begin(), a.end(), 5)!=2) {
        cout<<"NO"<<endl;
    } else if( count(a.begin(), a.end(), 7)!=1) {
        cout<<"NO"<<endl;
    } else {
        cout<<"YES"<<endl;
    }

    return 0;
}
