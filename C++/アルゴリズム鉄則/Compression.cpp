#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N),X(N),result(N);
    for(int i = 0; i < N; i++) cin >> A.at(i);
    for(int i = 0; i < N; i++) X.at(i) = A.at(i);
    sort(X.begin(), X.end());
    set<int> X_set(X.begin(), X.end());
    vector<int> X_vec(X_set.begin(), X_set.end());


    for(int i = 0; i < N; i++){
        int L = 0,R = X_vec.size()-1,mid = (L+R) / 2;
        while(R>L){
            if(X_vec.at(mid) == A.at(i)){
                R = mid;
                break;
            }
            if(X_vec.at(mid) < A.at(i)) L = mid+1;
            else R = mid-1;
            // cout << "left = " << L << ", right = " << R << endl;
            mid = (R+L) / 2;
        }
        result.at(i) = R;
    }
    for(int i = 0; i < N; i++) cout << result.at(i)+1 << " ";
    return 0;
}