#include <iostream>
#include <vector>
using namespace std;

//dp
int main(){
    int N;
    cin >> N;
    vector<int> A(N+1,0),dp(N+1,0);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);
    for(int i = 1; i < N+1; i++){
        dp.at(i) = max(dp.at(i-1),dp.at(i-1) + A.at(i));
    }
    cout << dp.at(N) << endl;
}

//bit全探索
// int main(){
//     int N;  
//     cin >> N;
//     vector<int> A(N,0);
//     for(int i = 0; i < N; i++) cin >> A.at(i);
    
//     int result = 0;
//     for(int bit = 0; bit < (1<<N); bit++){
//         int tmp = 0;
//         for(int shift = 0; shift < N; shift++){
//             if(bit & (1<<shift)) tmp += A.at(shift);
//         }
//         result = max(result,tmp);
//     }
//     cout << result << endl;
// }