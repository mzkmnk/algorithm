#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M;
    cin >> N >> M;
    vector<int> A(N+1);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);
    vector<vector<int> > dp(N+1,vector<int>(M+1,100));
    dp.at(0).at(0) = 0;
    for(int n = 1; n < N+1; n++){
        for(int m = 0; m < M+1; m++){
            dp.at(n).at(m) = min(dp.at(n).at(m),dp.at(n-1).at(m));
            if(m >= A.at(n)) dp.at(n).at(m) = min(dp.at(n).at(m),dp.at(n-1).at(m-A.at(n))+1);
        }
    }
    for(int n = 1; n < N+1; n++){
        for(int m = 0; m < M+1; m++){
            cout << dp.at(n).at(m) << " ";
        }
        cout << endl;
    }
}