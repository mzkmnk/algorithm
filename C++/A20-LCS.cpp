#include<iostream>
#include <vector>
using namespace std;

int main(){
    string S,T;
    cin >> S >> T;
    int S_length = S.length(),T_length = T.length();
    vector<vector<int> > dp(S_length + 1,vector<int>(T_length+1, 0));
    for(int s = 1; s < S_length + 1; s++){
        for(int t = 1; t < T_length + 1; t++){
            if(S.at(s-1) == T.at(t-1)){
                dp.at(s).at(t) = max(dp.at(s-1).at(t-1)+1,max(dp.at(s-1).at(t),dp.at(s).at(t-1)));
            }else{
                dp.at(s).at(t) = max(dp.at(s-1).at(t),dp.at(s).at(t-1));
            }
        }
    }
    
    // for(int i = 0; i < S_length+1; i++){
    //     for(int j = 0; j < T_length+1; j++){
    //         cout << dp.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp.at(S_length).at(T_length) << endl;
    return 0;
}