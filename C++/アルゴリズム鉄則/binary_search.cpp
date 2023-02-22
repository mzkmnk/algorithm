#include <iostream>
#include <vector>
using namespace std;

//まだWAあるから注意　訂正する

int main(){
    int N,K,cnt = 0;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A.at(i);
    
    for(int i = 0; i < N; i++){
        long long At = A.at(i) + K;
        long long left = i+1,right = N;
        bool flag = false;
        while(right > left){
            long long mid = (left + right)/2;
            if(At == A.at(mid)){
                right = mid;
                flag = true;
                break;
            }
            if(At <= A.at(mid)) right = mid;
            else left = mid+1;
        }
        if(flag){
            cnt += (right - i);
        }else{
            cnt += (right - 1 - i);
        }
    }
    cout << cnt << endl;
    return 0;
}