#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i=0;i<N;i++){
        cin >> A.at(i);
    }
    int left = 1,right = 1000000000;
    while(right - left > 0){
        long long mid = (left+right)/2,sum = 0;
        for(int i = 0; i < N; i++) sum += mid / A.at(i);
        if(K <= sum) right = mid;
        else left = mid + 1;
        // cout << "left = " << left << " right = " << right << endl;
    }
    cout << left << endl;
}