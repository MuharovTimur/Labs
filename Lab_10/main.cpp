#include <iostream>
#include <string>
//#include <windows.h>
using namespace std;

int n;

string* vvodmassiva(string *s,int size)
{
    cout << "Введите строки:";
    for(int i=0;i<size;i++)
    {
        getline(cin,s[i]);
    }
    return s;
}

void vivodmassiva(string *s,int size)
{
    for(int i=0;i<size;i++)
    {
        cout << s[i] << endl;
    }
}

string* udaleniemassiva(string *s,int size)
{
    int k;
    cout << "Введите количество первых строк,которве вы хотите удалить:";
    cin >> k;
    while(k>size)
    {
        cout << "Вы хотите удалить строк больше чем есть.Заново введите количество первых строк,которве вы хотите удалить:";
        cin >> k;
    }
    for(int i=0;i<(size-k);i++)
    {
        s[i]=s[i+k];
    }
    n=size-k;
    return s;
}

int main()
{
    //SetConsoleCP ( 1251 ) ;
    //SetConsoleOutputCP ( 1251 ) ;
    setlocale(LC_ALL,"RUS");
    cout<<"Введите размер массива:";
    cin >> n;
    string* s=new string[n];
    getline(cin,s[0]);
    vvodmassiva(s,n);
    udaleniemassiva(s,n);
    vivodmassiva(s,n);
    delete [] s;
    return 0;
}




