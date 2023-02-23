#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,X;
    cin>>N>>X;
    vector<int> A(N+1);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);

    int left = 1, right = N;
    
    while(right > left){
        int mid = (left+right)/2;
        if(X == A.at(mid)){
            right = mid;
            break;
        }
        if(X > A.at(mid)) left = mid + 1;
        else right = mid;
    }
    cout << right << endl;
}