#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
typedef long long ll;


int main()
{
    string A, B;
    cin >> A >> B;
    ll a = (int)A[0] + (int)A[1] + (int)A[2] - 3*48;
    ll b = (int)B[0] + (int)B[1] + (int)B[2] - 3*48;

    cout << (b > a ? b : a) <<endl;

    return 0;
}
