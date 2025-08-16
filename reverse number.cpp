#include<iostream>
using namespace std;
int main()

{
	int x,rev=0,digit;
 cout<<"enter the number";
 cin>>x;
	while(x!=0)
		{
			digit=x%10;
			x=x/10;
			rev=(rev*10)+digit;
		}	
		cout<<"the reverse number is"<<rev;
	
}
