#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int sizearr;

int* inputmassiv(int *M, int size)//заполнение массива
{
    for(int i=0; i<size; i++)
    {
       M[i]=rand()%101-50;
    }
    return M;
}

void outputmassiv(int *M,int size)//вывод массива
{
    for(int i=0; i<size; i++)
    {
       cout << M[i] << " ";
    }
    cout << endl;
}

int* removeeven(int *M, int size)//удаление четных элементов
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

string removeeven (string s)
{
    string ss;//новая строка
    int l;
    l=s.length();//длина строки
    for(int i=0;i<=l;i++)
    {
        if (i % 2==0)
        ss.append(s,i,1);
        else ss.push_back('_');
    }
    return ss;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    srand(time(NULL));
    char a;
    cout << "Выберите с чем вы хотите работать s-строкой,i-с целочисленным массивом:";
    cin >> a ;
    if (a=='s')
    {
        string s;
        cout << "Введите строку:" ;
        getline(cin,s);
        getline(cin,s);
        s=removeeven(s);
        cout << s;
    }
    else 
    {
        cout << "Введите размер массива:" ;
        cin >> sizearr ;
        int* M=new int[sizearr];
        inputmassiv(M, sizearr);
        outputmassiv(M, sizearr);
        removeeven(M, sizearr);
        outputmassiv(M, sizearr);
        delete[] M;
    }

    return 0;
}


