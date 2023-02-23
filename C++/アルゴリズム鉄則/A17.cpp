// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1,0),B(N+1,0),dp(N+1,0),root;
    for(int i = 2; i < N+1; i++) cin >> A.at(i);
    for(int i = 3; i < N+1; i++) cin >> B.at(i);

    dp.at(2) = A.at(2);
    for(int i = 3; i < N+1; i++){
        int dp_1 = A.at(i) + dp.at(i-1);
        int dp_2 = B.at(i) + dp.at(i-2);
        if(dp_1 > dp_2){
            dp.at(i) = dp_2;
            root.push_back(i-2);
        }else{
            dp.at(i) = dp_1;
            root.push_back(i-1);
        }
    }
    root.push_back(N);
    cout << root.size() << endl;
    for(int i = 0; i < root.size(); i++) cout << root.at(i) << " ";
    return 0;
}
