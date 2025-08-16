#include<iostream>
using namespace std;
int main()

{
	int x,rev=0,digit,original;
 cout<<"enter the number";
 cin>>x;
original=x;
	while(x!=0)
		{	
			
			digit=x%10;
			x=x/10;
			rev=(rev*10)+digit;
		}	
		if(rev==original)
		{
			cout<<"the number is pallindrome";
		}
		else{
			cout<<"no is not pallindrome";
		}
	
}
