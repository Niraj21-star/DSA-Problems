# include <iostream>
using namespace std;

  int sum(int n)
   {
   	 int  sum (int n);
   	 cout<<"enter the number whose sum is to be printed";
   	 cin>>n;
   	int s=0;
   	for (int i=1;i<=n;i++)
   	{
   		s=s+i;
	   }
	   return (s);
	
   }
    int main()
    {
        int s;
    	cout<<"the sum of number is "<<sum(s);
    	return 0;
    	
    
	}
