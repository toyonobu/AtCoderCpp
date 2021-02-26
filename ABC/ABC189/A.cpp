#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl;
typedef long long ll;

int main()
{
    string S;
    cin >> S;
    if (S[0]!=S[1]) {
        cout<<"Lost"<<endl;
    } else if (S[1]!=S[2]) {
        cout<<"Lost"<<endl;
    } else {
        cout<<"Won"<<endl;
    }

    return 0;
}
