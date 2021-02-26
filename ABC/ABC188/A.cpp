#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
typedef long long ll;

int main()
{
    int X, Y;
    cin >> X >> Y;
    int a = max(X, Y);
    int b = min(X, Y);
    PRINT_YesNo( (b+3)>a );

    return 0;
}
