#include <bits/stdc++.h>
using namespace std;

#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl
#define PRINT_YESNO(condition) cout<<((condition)?"YES":"NO")<<endl
typedef long long ll;

int main()
{
    int N, x, y;
    cin >> N;
    vector<pair<int, int> > positions;
    for (int i=0; i<N; ++i) {
        cin >> x >> y;
        positions.push_back( make_pair(x, y) );
    }

    int count = 0;
    for(int i=0; i<N-1; ++i) {
        for(int j=i+1; j<N; ++j) {
            const auto& pos_i = positions[i];
            const auto& pos_j = positions[j];

            if( abs(pos_j.second - pos_i.second) <= abs(pos_j.first - pos_i.first) ) {
                ++count;
            }
        }
    }

    cout << count << endl;

    return 0;
}
