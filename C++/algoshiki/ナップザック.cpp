#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,W;
    cin >> N >> W;
    vector<vector<int> > wv(N+1,vector<int>(W+1,0));
    for(int i = 0; i < N; i++){
        cin >> wv.at(i).at(0) >> wv.at(i).at(1);
    }

    vector<vector<int> > dp(N+1,vector<int>(W+1,0));
    for(int n = 0; n < N+1; n++){
        for(int w = 0; w < W+1; w++){
            if(wv.at(n).at(0) > w) dp.at(n).at(w) = dp.at(n-1).at(w);
            else{
                dp.at(n).at(w) = max(dp.at(n-1).at(w),wv.at(n).at(1) + dp.at(n-1).at(w - wv.at(n).at(0)));
            }
        }
    }
    for(int i = 0; i < N+1; i++){
        for(int j = 0; j < W+1; j++){
            cout << dp.at(i).at(j) << " ";
        }
        cout << endl;
    }
}