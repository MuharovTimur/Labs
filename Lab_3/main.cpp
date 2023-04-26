#include <iostream>
#include <cmath>
using namespace std;

double rec(int n,double x)
{
    double S;
    if(n>0)
    {
       S=pow(-1,n)*(pow(1+x,2*n)/n);// находим  слагаемое
       S+=rec(n-1,x);//вызываем предыдущее слагаемое
    }
    else S=0; 
    return S;
}

int main()
{
    setlocale(0,"");
    
    double S,x;
    int n;
    
    cout << "Введите x и n." << endl;
    cin >> x >> n;
    while (n<1)
    {
        cout << "n должен быть положительным.Введите заново n." << endl;
        cin >> n;
    }
    cout << "Рассчитываем сумму ряда." ;
    S=rec(n,x);
    cout << "S=" << S << endl;
    return 0;
}
