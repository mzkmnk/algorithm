// #include <bits/stdc++.h>
#include <iostream>
#include <cmath>
using namespace std;

int judge(long long a, long long b, long long mod){
    if(b == 0) return 1;
    if(b == 1) return a%mod;
    // if(b%2 == 1) return judge(a*judge(a,b-1,mod)) % mod;
}

int main(){
    long long a,b,ans = 1,mod = pow(10,9)+7;
    cin >> a >> b;

    return 0;
}