#include<iostream>
using namespace std;

void print(int n)
{	int sum=0;
	if(n==0)
		return;
	print(n-1);
	sum+=n;
	cout<<sum;		

}
int main()
{	int sum;
	int n;
	cout<<"enter no :";
	cin>>n;
	print(n);
	return 0;
	

}
