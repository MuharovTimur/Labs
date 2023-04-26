#include <iostream>
#include <stdlib.h>
using namespace std;

int sizearr=10;

int* inputmassiv(int *M, int size)//заполнение массива
{
    for(int i=0; i<size; i++)
    {
       M[i]=rand()%101-50;
    }
    return M;
}

void outputmassiv(int *M,int size,int k)//вывод массива с k элемента до k-1 элемента
{
   if (k>size)
   k%=size;
    for(int i=k; i<size; i++)
    {
       cout << M[i] << " ";
    }
    for(int i=0; i<=k-1; i++)
    {
       cout << M[i] << " ";
    }
}

int* sorting(int *M, int size)//сортировка пузырьком
{
    int temp;
    for(int i=0;i<size-1;i++)
    {
        for(int j=size-2;j>=i;j--)
        {
            if (M[j]>M[j+1])
            {
                temp=M[j];
                M[j]=M[j+1];
                M[j+1]=temp;
            }
        }
    }
    return M;
}

int* removeelementofmassiv(int *M, int size)//удаление четных элементов
{
    int newsize=0;
    for(int i=0; i<sizearr; i++)
    {
       if ((M[i] % 2==1)||(M[i]% 2==-1))
       {
           M[newsize++]=M[i];
       }
    }
    sizearr=newsize;
    return M;
}

int main()
{
   int* M=new int[sizearr];
   setlocale(0,"");
    srand(time(NULL));
    
    int k;
    
    cin >> k;
    
    inputmassiv(M, sizearr);
    outputmassiv(M, sizearr, k);
    sorting(M, sizearr);
    cout << endl;
    outputmassiv(M, sizearr, k);
    removeelementofmassiv(M, sizearr);
    cout << endl;
    outputmassiv(M,sizearr , k);
    
    delete[] M;
    
    return 0;
}


