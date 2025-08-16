#include<iostream>
using namespace std;

void print(int i,int n)
{
	if(i>n)
		return;
	print(i+1,n);	
	cout<<i<<endl;	

		

}
int main()
{
	int n;
	cout<<"enter no :";
	cin>>n;
	if(n>0)
		print(1,n);
	else	
		return 0;
	

}
