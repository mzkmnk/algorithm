#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);

    set<int> A_set(A.begin(), A.end());
    vector<int> A_vec(A_set.begin(), A_set.end());
    sort(A_vec.begin(), A_vec.end());

    vector<int> result(N);
    for(int i = 1; i < N+1; i++){
        int left = 1, right = A_vec.size(),mid = (left + right) / 2;
        while(right > left){
            // if(A_vec.at(mid) == A.at(i)){
            //     left = mid;
            //     break;
            // }
            if(A.at(i) > A_vec.at(mid)) left = mid+1;
            else right = mid;
            mid = (left + right) / 2;

            // cout << "left = " << left << ", mid = " << mid << ", right = " << right << endl;
            // cout << "A = " << A.at(i) << ", A_vec = " << A_vec.at(mid) << endl;
            // exit(0);
        }
        result.at(i-1) = left;
    }


    for(int i = 0; i < N; i++) cout << result.at(i) << " ";
    return 0;
}