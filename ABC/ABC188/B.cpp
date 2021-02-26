#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
typedef long long ll;

int main()
{
    int N;
    cin >> N;
    vector<int> A(N);
    vector<int> B(N);
    int tmp;
    for(int i=0; i<N; ++i) {
        cin >> tmp;
        A[i] = tmp;
    }
    for(int i=0; i<N; ++i) {
        cin >> tmp;
        B[i] = tmp;
    }
    int sum = 0;
    for(int i=0; i<N; ++i) {
        sum += A[i] * B[i];
    }

    PRINT_YesNo( sum==0 );

    return 0;
}
