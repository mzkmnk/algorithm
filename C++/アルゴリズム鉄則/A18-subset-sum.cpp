#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,S;
    cin >> N >> S;
    vector<int> A(N+1);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);
    vector<vector<bool> > dp(N+1,vector<bool>(S+1,false));
    dp.at(0).at(0) = true;
    for(int h = 1; h < N+1; h++){
        for(int s = 0; s < S+1; s++){
            if(s < A.at(h)) dp.at(h).at(s) = dp.at(h-1).at(s);
            else{
                if(dp.at(h-1).at(s - A.at(h)) || dp.at(h-1).at(s)) dp.at(h).at(s) = true;
            }
        }
    }
    if(dp.at(N).at(S)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}