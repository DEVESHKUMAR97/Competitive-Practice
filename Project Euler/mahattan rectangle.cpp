#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;


int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--){
	    ll maxy=10,m,n,o,p,a,b,c,d;
	    cout<<"Q "<<0<<" "<<0<<endl;
	    cin>>m;
	    cout<<"Q "<<maxy<<" "<<0<<endl;
	    cin>>n;
	    cout<<"Q "<<maxy<<" "<<maxy<<endl;
	    cin>>o;
	    cout<<"Q "<<0<<" "<<maxy<< endl;
	    cin>>p;

	    ll height,width;
	    height=(maxy-((m+n)-maxy)/2+((o+p)-maxy)/2)/2;
	    width=(maxy-((m+o)-maxy)/2+((n+p)-maxy)/2)/2;
	    b=(m-maxy+width+n)/2;
	    a=m-b;
	    c=b+maxy-n;
	    d=2*maxy-c-o;
	    cout<<"A "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	    ll res;
	    cin>>res;
	    if(res<0) exit(0);
	}

	return 0;
}
