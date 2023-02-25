#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int> > PA(N+1, vector<int>(2,0)),dp(N+1,vector<int>(N+1,0));
    for(int i = 1; i < N+1; i++) cin >> PA.at(i).at(0) >> PA.at(i).at(1);
    dp.at(1).at(N) = 0;
    for(int LEN = N - 2; LEN +1 > 0; LEN--){
        for(int l = 1; l < N+1 - LEN; l++){
            int r = l + LEN - 1;
            
            int score1 = 0;
        }
    }
    return 0;
}