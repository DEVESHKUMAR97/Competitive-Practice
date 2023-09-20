/// Smallest multiple
#include<iostream>
using namespace std;
#define ll long long
ll LCM(ll a, ll b){
    ll maxy=a>b?a:b;
    for(ll l=maxy;l<=a*b;l+=maxy){
        if(l%a==0&&l%b==0) return l;
    }

}
int main()
{
    ll num;
    cout<<"Enter a Number : ";
    cin>>num;
    ll ans=1;
    for(int i=2;i<=num;i++){
        ans = LCM(ans,i);
    }
    cout<<ans<<endl;
    return 0;
}



/*
// method 2
This does not require programming at all. Compute the prime factorization of each number from 1 to 20, and multiply the greatest power of each prime together:

20 = 2^2 * 5
19 = 19
18 = 2 * 3^2
17 = 17
16 = 2^4
15 = 3 * 5
14 = 2 * 7
13 = 13
11 = 11

All others are included in the previous numbers.

ANSWER: 2^4 * 3^2 * 5 * 7 * 11 * 13 * 17 * 19 = 232 792 560*/
