#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl;
typedef long long ll;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    A += C;
    cout << (A > B ? "Takahashi" : "Aoki")<<endl;
    return 0;
}
