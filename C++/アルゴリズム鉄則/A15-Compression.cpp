#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N+1),result(N+1);
    for(int i = 1; i < N+1; i++) cin >> A.at(i);
    set<int> A_set(A.begin(),A.end());
    vector<int> A_sorted(A_set.begin(),A_set.end());
    // for(int i = 0; i < A_sorted.size(); i++) cout << A_sorted.at(i) << " ";
    // cout << endl;
    for(int i = 1; i < N+1; i++){
        int left = 1, right = A_sorted.size(),mid = (left+right)/2;
        while(right > left){
            if(A.at(i) > A_sorted.at(mid)) left = mid + 1;
            else right = mid;
            mid = (left+right)/2;
            // cout << "left: " << left << "right: " << right << endl;
        }
        // cout << "----------" << endl;
        result.at(i) = right;
    }
    for(int i = 1; i < N+1; i++) cout << result.at(i) << " ";
    return 0;
}