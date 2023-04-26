#include <iostream>
#include <string>
//#include <windows.h>
using namespace std;

int main()
{
    //SetConsoleCP ( 1251 ) ;
    //SetConsoleOutputCP ( 1251 ) ;
    setlocale(LC_ALL,"RUS");
    int z,h=0,q,e=0;//длина строки и счетчики
    int l,k;//индекс пробела и количество повторений
    char a,b;
    string s;
    cout << "Введите два слова,разделенные пробелом:" ;
    getline(cin,s) ;
    z=s.length();
    for(int i=0;i<z;i++)//нахождение пробела
    {
        a=s.at(i);
        if (a==' ')
        {
            l=i;
        }
    }
    q=l+1;
    for(int i=0;i<l;i++)//сколько совпадений
    {
        a=s.at(i);
        for(int j=l+1;j<z;j++)
        {
            b=s.at(j);
            if (a==b)
            {
                k++;
            }
        }
    }
    if (k==0)
    {
        cout << "кроссворд составить невозможно";
    }
    else
    {
        int* M=new int[2*k];//массив запоминать позиции четные для первого слова нечетные для второго
        for(int i=0;i<l;i++)//запоминание позиций
        {
            a=s.at(i);
            for(int j=l+1;j<z;j++)
            {
                b=s.at(j);
                if (a==b)
                {
                    M[h]=i;
                    M[h+1]=j;
                }
            }
            h+=2;
        }
        h=0;
        for(int g=1;g<=k;g++)//кроссворды
        {
            cout << "Кроссворд № " << g << ":" << endl;
            for(int i=l+1;i<z;i++)
            {
                for(int j=0;j<l;j++)
                {
                    if(j==M[h])
                    {
                        a=s.at(q);
                        cout << a ;
                        q++;
                    }
                    if ((j==M[h])&&(i==M[h+1]))
                    {
                        e++;
                    }
                    if((i==M[h+1])&&(j!=M[h]))
                    {
                        b=s.at(e);
                        cout << b ;
                        e++;
                    }
                    if ((i!=M[h+1])&&(j!=M[h]))
                    {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            h+=2;
            q=l+1;e=0;
            cout << endl;
        }
        delete[] M;
    }
    return 0;
}














