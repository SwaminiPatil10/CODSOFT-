#include <iostream>
#include <cstdlib>  
#include <ctime>    
#include <limits>

using namespace std;

void print_instructions()
{
    cout<<"Welcome to the Number Guesing Game!"<<endl;
    cout<<"You have a choice to select a number between 1 to 20."<<endl;
    cout<<"Try to guess the number."<<endl;
}

int get_user_guess()
{
    int guess;
    while(true)
    {
        cout<<"Enter the number: ";
        cin>>guess;

        if(cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); 
            cout<<"Invalid input. Please enter a number."<<endl;
        }
        else
        {
            return guess;
        }
    }
}

int main()
{
    srand(static_cast<unsigned>(time(0)));
    int number_to_guess=rand() % 20+1;
    int user_guess=0;
    int attempts=0;

    print_instructions();

    while(true)
    {
        user_guess=get_user_guess();
        attempts++;

        if(user_guess<number_to_guess)
        {
            cout<<"Your guess is too low. Try again!"<<endl;
        }
        else if(user_guess>number_to_guess)
        {
            cout<<"Your guess is too high. Try again!"<<endl;
        }
        else
        {
            cout<<"Congratulations!! You guessed the correct number " 
                <<number_to_guess<<" correctly in " 
                <<attempts<<" attempts."<<endl;
            break;    
        }
    }

    return 0;
}
