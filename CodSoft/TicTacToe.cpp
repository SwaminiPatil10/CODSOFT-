#include <iostream>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE]={{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
int winsX=0, winsO=0, draws=0;

void printBoard()
{
    cout<<"\n   A   B   C\n";
    cout<<"1  "<<board[0][0]<<" | "<<board[0][1]<<" | "<<board[0][2]<<"\n";
    cout<<"  ---|---|---\n";
    cout<<"2  "<<board[1][0]<<" | "<<board[1][1]<<" | "<<board[1][2]<<"\n";
    cout<<"  ---|---|---\n";
    cout<<"3  "<<board[2][0]<<" | "<<board[2][1]<<" | "<<board[2][2]<<"\n";
}

int letterToIndex(char letter)
{
    return(letter-'A');
}

int numberToIndex(int number)
{
    return(number-1);
}

bool checkWin(char player)
{
    for(int i=0;i<SIZE;++i)
    {
        if((board[i][0]==player&&board[i][1]==player&&board[i][2]==player)||
            (board[0][i] == player && board[1][i] == player && board[2][i]==player))
            {
            return true;
            }
    }
    if((board[0][0]==player&&board[1][1]==player&&board[2][2]==player)||
       (board[0][2]==player&&board[1][1]==player&&board[2][0]==player))
       {
        return true;
       }
    return false;
}

bool checkDraw()
{
    for(int i=0;i<SIZE;++i)
    {
        for(int j=0;j<SIZE;++j)
        {
            if(board[i][j] !='X'&&board[i][j] !='O')
            {
                return false;
            }
        }
    }
    return true;
}
bool makeMove(char col, int row, char player)
{
    int rowIndex=numberToIndex(row);
    int colIndex=letterToIndex(col);

    if(rowIndex<0 || rowIndex>=SIZE || colIndex<0 || colIndex>=SIZE ||
        board[rowIndex][colIndex]=='X' || board[rowIndex][colIndex]=='O')
        {
        return false;
        }

    board[rowIndex][colIndex]=player;
    return true;
}

void resetBoard()
{
    char initBoard[SIZE][SIZE]={{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    for(int i=0;i<SIZE;++i)
    {
        for(int j=0;j<SIZE;++j)
        {
            board[i][j]=initBoard[i][j];
        }
    }
}

void displayStats()
{
    cout<<"Player Statistics: "<<endl;
    cout<<"Player X Wins: "<<winsX<<endl;
    cout<<"Player O Wins: "<<winsO<<endl;
    cout<<"Draws: "<<draws<<endl;
}

// Function to play the game
void playGame()
{
    char currentPlayer='X';
    char col;
    int row;
    bool validMove;

    while (true)
    {
        printBoard();
        cout<<"Player "<<currentPlayer<<"'s turn. Enter a column (A-C) and row (1-3): ";
        cin>>col>>row;

        validMove=makeMove(col, row, currentPlayer);
        if(!validMove)
        {
            cout<<"Invalid move. Please try again."<<endl;
            continue;
        }
        
        if(checkWin(currentPlayer))
        {
            printBoard();
            cout<<"Player "<<currentPlayer<<" wins!"<<endl;
            (currentPlayer=='X')?++winsX:++winsO;
            break;
        }
        
        if(checkDraw())
        {
            printBoard();
            cout<<"It's a draw!"<<endl;
            ++draws;
            break;
        }
        
        currentPlayer=(currentPlayer=='X')?'O':'X';
    }
}

int main()
{
    char playAgain;

    cout<<"Welcome to Tic-Tac-Toe!"<<endl;
    cout<<"You can start to play!"<<endl;

    do
    {
        resetBoard();
        playGame();
        displayStats();
        cout<<"Do you want to play again?(y/n): ";
        cin>>playAgain;
    } 
    while(playAgain=='y'||playAgain=='Y');
    cout<<"Thanks for playing!"<<endl;
    cout<<"Visit again!"<<endl;
    return 0;
}
