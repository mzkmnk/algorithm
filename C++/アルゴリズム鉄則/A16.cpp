#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1),B(N+1),dp(N+1,0);
    for(int i = 2; i < N+1; i++) cin >> A.at(i);
    for(int i = 3; i < N+1; i++) cin >> B.at(i);
    dp.at(2) = A.at(2);

    for(int i = 3; i < N+1; i++){
        dp.at(i) = min(A.at(i) + dp.at(i-1),B.at(i) + dp.at(i-2));   
    }
    // for(int i = 0; i < N+1; i++) cout << dp.at(i) << " ";
    cout << dp.at(N) << endl;
    return 0;
}