#include <iostream>

using namespace std;

int main(){
    long long N,cnt = 0;
    cin >> N;
    cnt = N/3 + N/5 - N/15;
    cout << cnt << endl;
    return 0;
}