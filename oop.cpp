# include<iostream>
using namespace std;
class person
{
	public:
		string name;
		int age;
	public:
		person(string n,int a)
		{
			name=n;
			age=a;
		}	
	void displayinfo(){
		cout<<"Name:"<<name<<"Age:"<<age<<endl;
	}
};
class student:public person
{
	public:
		string course;
	public:
	student(string n,int a,string c):person(n,a)
	{
		course=c;
		}	
	void displayStuInfo(){ 
		displayinfo();
		cout<<"course:"<<course<<endl;
	}
};
	class player : public student {
public:
    player(string n, int a, string c) : student(n, a, c) {}

    void display1() {
        cout << "This is player class" << endl;
    }
};


			


int main()
{
	student S1("Ram",20,"AI&DS");
	S1.displayStuInfo();  
	player p1("Ram",20,"AI&DS");
	p1.display1();

	return 0;
}
