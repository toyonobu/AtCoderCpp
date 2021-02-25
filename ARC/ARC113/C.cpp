#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define PRINT_YesNo(condition) cout<<((condition)?"Yes":"No")<<endl;


int find_all(const std::string str, const std::string subStr) {
    std::vector<int> result;
 
    int subStrSize = subStr.size();
    int pos = str.find(subStr);
 
    while (pos != std::string::npos) {
        result.push_back(pos);
        pos = str.find(subStr, pos + subStrSize);
    }
 
    return (int)result.size();
}

int main()
{
    string S;
    cin >> S;

    int res= 0;
    for(int i=S.size()-2; i>=0; --i) {
        if( S[i]==S[i+1] && S[i]!=S[i+2] ) {
           string tmp = {S[i]};
            int x=  S.size() - i -2 - find_all(S.substr(i+2), tmp);
            res +=x;
            for(int j=i+2; j<S.size(); ++j) {
                S[j] = S[i];
            }
        }
    }

    cout<<res<<endl;

    return 0;
}
