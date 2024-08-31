#include<iostream>
#include<limits>
using namespace std;

void printMenu() 
{
    cout<<"Operations you can perform:"<<endl;
    cout<<"1)Addition"<<endl;
    cout<<"2)Subtraction"<<endl;
    cout<<"3)Multiplication"<<endl;
    cout<<"4)Division"<<endl;
}

double add(double x,double y)
{
    return x+y;
}
double subtract(double x,double y) 
{
    return x-y;
}
double multiply(double x,double y) 
{
    return x*y;
}
double divide(double x,double y) 
{
    return x/y;
}

int main() 
{
    double num1,num2;
    int choice;

    cout<<"Greetings all!"<<endl;
    cout<<"Simple calculator is ready to work for you !"<<endl;

    while(true) 
    {
        cout<<"Enter the first number: ";
        cin>>num1;
        if(cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //discard invalid input
            cout<<"Invalid input. Please enter a valid number."<<endl;
        } 
        else 
        {
            break;
        }
    }

    while(true) 
    {
        cout<<"Enter the second number: ";
        cin>>num2;
        if(cin.fail()) 
        {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard invalid input
            cout<<"Invalid input. Please enter a valid number."<<endl;
        } 
        else 
        {
            break;
        }
    }

    
    printMenu();
    {
        cout<<"select an operation"<<endl;
        cout<<"1,2,3,4:"<<endl;
        cin>>choice;
        
    }

    double result;
    switch(choice)
    {
        case 1:
            result=add(num1,num2);
            cout<<num1<<"+"<<num2<<"="<<result<<endl;
            break;
        case 2:
            result=subtract(num1,num2);
            cout<<num1<<"-"<<num2<<"="<<result<<endl;
            break;
        case 3:
            result=multiply(num1,num2);
            cout<<num1<<"*"<<num2<<"="<<result<<endl;
            break;
        case 4:
            result=divide(num1,num2);
            cout<<num1<<"/"<<num2<<"="<<result<<endl;
            break;
    }

    cout<<"Thank you...visit again!"<<endl;

return 0;
}
