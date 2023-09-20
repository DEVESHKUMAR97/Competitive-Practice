/// Sum square difference
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long sum_of_n_nat_nos=n*(n+1)/2;
    long long square=sum_of_n_nat_nos*sum_of_n_nat_nos;
    long long sum_of_sq_n_nat_nos=n*(n+1)*(2*n+1)/6;
    long long ans=square-sum_of_sq_n_nat_nos;
    cout<<ans<<endl;
    return 0;
}
