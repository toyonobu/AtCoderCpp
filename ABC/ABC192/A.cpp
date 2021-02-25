#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;

int main()
{
    int X;
    cin >> X;
    cout << (X%100 ? 100 - (X%100) :100) <<endl;

    return 0;
}
