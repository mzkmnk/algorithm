#include <iostream>

using namespace std;
int top(int n, int cnt){
    if(n == cnt) return cnt;
    return (n * top(n-1,cnt) % 1000000007) % 1000000007;
}
int main(){
    int N,r;
    cin >> N >> r;
    r = N - r;
    cout << top(N,(N-r)+1)/top(r,1) << endl;
}