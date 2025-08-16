#include<iostream>
using namespace std;

void print(string name,int n)
{ if(n<=0)
{
	return;
}
cout<<name<<endl;
print(name,n-1);
	
}
int main()
{
	string name;
	int n;
	cout<<"enter the name:";
	cin>>name;
	cout<<"enter no of times:";
	cin>>n;
	print(name,n);
	return 0;
	

}







