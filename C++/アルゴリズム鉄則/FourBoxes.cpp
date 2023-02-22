#include <iostream>
#include <vector>
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

    sort(AB.begin(),AB.end());
    sort(CD.begin(),CD.end());

    
}