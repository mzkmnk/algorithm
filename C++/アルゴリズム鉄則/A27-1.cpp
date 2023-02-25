#include <iostream>

using namespace std;

int main(){
    long long N,sum = 0,mod = 10000;
    cin >> N;
    for(int i = 0; i < N; i++){
        char T;
        cin >> T;
        long long A;
        cin >> A;
        if('+' == T) sum += A;
        else if('-' == T) sum -= A;
        else if('*' == T) sum *= A;
        if(sum < 0) sum += 10000;
        sum %= mod;
        cout << sum << endl;
    }
    return 0;
}