/// Largest prime factor
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    long long maxprime=-1;
    long long n;
    cin>>n;
    while(n%2==0){
        maxprime=2;
        n/=2;
    }

    for(long long i=3;i<=sqrt(n);i+=2){
        while(n%i==0){
            maxprime=i;
            n/=i;
        }
    }

    if(n>2){
        maxprime=n;
    }
    cout<<maxprime<<endl;
    return 0;
}

