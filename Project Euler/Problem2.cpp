/// Even Fibonacci numbers
#include<iostream>
using namespace std;
int main()
{
    long long sum=0;
    long long a,b,c;
    a=1;
    b=2;
    sum+=b;
    while(1){
        c=a+b;
        a=b;
        b=c;
        if(c>4000000) break;
        if(c%2==0){
            sum+=c;
        }
    }
    cout<<sum<<endl;
}

