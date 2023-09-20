/// 10001st prime
/// general nth prime number
#include<iostream>
using namespace std;
int isprime(int n)
{
    // wrong
    //if(a==2||a==3) return 1;
    //if(a%6==1||a%6==5) return 1;
    //return 0;



    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (int i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}
int main()
{
    int n;
    cin>>n;
    if(n==1){
        cout<<2<<endl;
    }

    int i=3,count_prime=1;
    while(1){
        if(isprime(i)){
            count_prime++;
            if(count_prime==n){
                break;
            }
        }
        i+=2;
    }
    cout<<i<<endl;
}
