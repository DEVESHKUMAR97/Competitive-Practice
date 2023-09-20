/// Largest palindrome product
#include<iostream>
#include<math.h>
using namespace std;
bool ispalindrome(long long n){
    long long temp=n,rev=0;
    while(temp){
        rev=rev*10+temp%10;
        temp/=10;
    }
    return rev==n;
}
int main()
{
    long long num;
    cout<<"Enter a number representing the number of digits of the two number taken :";
    cin>>num;
    long long pmax=0,a,b,p;
    long long maxy=(pow(10,num))-1;
    long long minny=(pow(10,(num-1)));
    cout<<"****"<<maxy<<" "<<minny<<endl;

    for(long long i=maxy;i>=minny;i--){
        for(long long j=maxy;j>=minny;){
            p=i*j;
            //if(p<pmax) break;
            if(ispalindrome(p)){
                pmax=p;
                a=i;
                b=j;
            }
            /*if(i%11==0) j-=11;
            else*/ j--;
        }
    }
    if(pmax>0) cout<<"Largest Palindrome product = "<<a<<" * "<<b<<" = "<<pmax<<endl;
    else cout<<"Not Found\n";
    return 0;
}
