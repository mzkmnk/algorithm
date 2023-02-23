#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,W;
    cin >> N >> W;
    vector<vector<int> > WV(N+1,vector<int>(2,0));
    vector<vector<long long> > dp(N+1,vector<long long>(W+1,0));
    for(int i = 1; i < N + 1; i++) cin >> WV.at(i).at(0) >> WV.at(i).at(1);
    
    for(int n = 1; n < N+1; n++){
        for(int w = 0; w < W+1; w++){
            // cout << " n = " << n << ", w = " << w << endl;;
            if(w < WV.at(n).at(0)) dp.at(n).at(w) = dp.at(n-1).at(w);
            else dp.at(n).at(w) = max(dp.at(n-1).at(w),dp.at(n-1).at(w-WV.at(n).at(0)) + WV.at(n).at(1));
        }
    }
    cout << dp.at(N).at(W) << endl;
    return 0;
}