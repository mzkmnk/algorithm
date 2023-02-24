#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N+1);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);
    long long left = 1, right = pow(10,9),mid = (left+right)/2;
    while(right > left){
        long long sum = 0;
        for(int i=1; i < N+1; i++) sum += mid/A.at(i);
        if(sum < K) left = mid + 1;
        else right = mid;
        mid = (left+right)/2;
        // cout << "left = " << left << ", right = " << right << endl;
    }
    cout << right << endl;
    return 0;
}