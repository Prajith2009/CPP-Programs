#include <iostream>
#include <string>
using namespace std;
class Student{
    private :
    int rollNo;
    
    string name;

    public:
    //constructor
    Student(int r,string n){
        rollNo = r;
        name = n;
        cout<<"Student object created"<<endl;
    }
    //member function
    void display()
    {
        cout<<"Roll Number: "<<rollNo<<endl;
        cout<<"Name:"<<name<<endl;


    }
    // Destructor
    ~Student()
    {
        cout<<"Student object destroyed" <<endl;

    }
};

int main()
{
    int roll;
    string studname;
    cout<<"Enter roll number: ";
    cin>>roll;
    cout<<"Enter name: ";
    cin>>studname;
    Student s1(roll,studname);
    s1.display();
    return 0;
}