#include <iostream>
#include <stdlib.h>
using namespace std;

int n=5;

int** inputmassiv(int **M, int n)//заполнение массива
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            M[i][j]=rand()%101-50;
        }
    }
    return M;
}

void outputmassiv(int **M, int n)//вывод массива
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << M[i][j] << " ";
        }
        cout << endl;
    }
}

int Finding(int **M, int n, int ks)//нахождения сколько элементов больше любого элемента главной диагонали
{
    int k;
    bool f;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)//проверка с главной диагональю
        {
            f=true;
            k=0;
            while((k<n)&&(f==true))
            {
                if(M[i][j]<M[k][k])
                {f=false;}
                
                k++;
            }
            if (f==true)
            {ks++;}
        }
    }
    return ks;
}

int main()
{
    setlocale(0,"");
    int ks=0;
    int** M=new int * [n];
    for(int i=0;i<n;i++)
    {
        M[i]=new int[n];
    }
    srand(time(NULL));
    
    inputmassiv(M, n);
    outputmassiv(M,n);
    ks=Finding(M,n,ks);
    
    for(int i=0;i<n;i++)
    {
        delete[] M[i];
    }
    delete[] M;
    
    cout << "Количество элементов массива,котоpыe больше любого элемента на главной диагонали,равнo " << ks <<endl;

    return 0;
}





