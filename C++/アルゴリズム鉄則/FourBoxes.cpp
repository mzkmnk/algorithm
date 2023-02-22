#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    int N,K;
    cin >> N >> K;
    vector<int> A(N+1),B(N+1),C(N+1),D(N+1);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);
    for(int i = 1; i < N+1; i++) cin >> B.at(i);
    for(int i = 1; i < N+1; i++) cin >> C.at(i);
    for(int i = 1; i < N+1; i++) cin >> D.at(i);

    vector<int> AB(N*N + 1),CD(N*N + 1);
    int cnt = 1;
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < N + 1; j++){
            AB.at(cnt) = A.at(i) + B.at(j);
            cnt++;
        }
    }
    cnt = 1;
    for(int i = 1; i < N + 1; i++){
        for(int j = 1; j < N+1; j++){
            CD.at(cnt) = C.at(i) + D.at(j);
            cnt++;
        }
    }
    // for(int i = 0; i < N*N+1; i++) cout << AB.at(i) << " ";
    // cout << endl;
    // for(int i = 0; i < N*N+1; i++) cout << CD.at(i) << " ";
    // cout << endl;
    
    sort(AB.begin(),AB.end());
    sort(CD.begin(),CD.end());

    for(int i = 1; i < AB.size(); i++){
        int num = K - AB.at(i);
        int left = 1, right = N*N,mid = (right + left) / 2;

        // cout << "num = " << num << endl;

        while(right > left){
            if(num == CD.at(mid)){
                left = mid;
                break;
            }
            if(num > CD.at(mid)) left = mid + 1;
            else right = mid - 1;
            mid = (right + left) / 2;

            // cout << "left = " << left << ", right = " << right << endl;
            // cout << "left = " << CD.at(left) << "right = " << CD.at(right) << endl;

        }
        if(num == CD.at(mid)){
            cout << "Yes" << endl;
            exit(0);
        }
    }
    cout << "No" << endl;
}