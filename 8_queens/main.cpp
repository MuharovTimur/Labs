#include <iostream>
using namespace std;

const int n=8;
int board [n][n];

void setQueen(int i,int j)//Установка королевы и битых клеток
{
    for(int k=0;k<n;k++)
    {
        ++board[k][j];//битые по горизонтали
        ++board[i][k];//битые по вертикали
        int d2=j+i-k;//для побочной диагональ
        int d1=j-i+k;//для главной диагональ
        if((d1>=0)&&(d1<=n-1))
        ++board[k][d1];
        if((d2>=0)&&(d2<=n-1))
        ++board[k][d2];
        
    }
    board[i][j]=-1;//Установка самой королевы
}

void resetQueen(int i,int j)//снятие королевы и ее битые клетки
{
    for(int k=0;k<n;k++)
    {
        --board[k][j];//битые по горизонтали
        --board[i][k];//битые по вертикали
        int d2=j+i-k;//для побочной диагональ
        int d1=j-i+k;//для главной диагональ
        if((d1>=0)&&(d1<=n-1))
        --board[k][d1];
        if((d2>=0)&&(d2<=n-1))
        --board[k][d2];
        
    }
    board[i][j]=0;//снятие королевы
}

bool tryQueen(int i)
{
    bool result=false;
    for(int j=0;j<n;j++)
    {
        if (board[i][j]==0)
        {
            setQueen(i,j);
            if (i==(n-1))
            result=true;
            else
            {
                result=tryQueen(i+1);
                if (!result)
                resetQueen(i,j);
            }
        }
    }
    return result;
}

int main()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            board[i][j]=0;
        }
    }
    tryQueen(0);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if (board[i][j]==-1)
            cout << "Q"  ;
            else cout << "." ;
        }
        cout << endl;
    }

    return 0;
}


