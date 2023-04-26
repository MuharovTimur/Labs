#include <iostream>
#include <math.h>
#include <stdarg.h>
#include <stdlib.h>
using namespace std;

void outputmassiv(int *M,int size)//вывод массива
{
    for(int i=0; i<size; i++)
    {
       cout << M[i] << " ";
    }
    cout << endl;
}

double coordinates(int n, ...)
{
    int* x=new int[n/2];
    int* y=new int[n/2];
    int j=0;
    int k=0;
    double s=0;
    va_list factor ;
    va_start(factor,n);
    for(int i=0;i<n;i++)
    {
        if (i % 2==0)
        {
            x[j]=va_arg(factor,int);
            j++;
        }
        else
        {
            y[k]=va_arg(factor,int);
            k++;
        }
    }
    outputmassiv(x, n/2);
    outputmassiv(y, n/2);
    if (n>6)
    {//площадь выпуклого многоугольника
        for(int i=1;i<n/2;i++)
        {
        s=s+(x[i-1]*y[i]-x[i]*y[i-1]);
        }
        s=s+(x[(n/2)-1]*x[1]-x[1]*y[(n/2)-1]);
        s=(1.0/2.0)*abs(s);
    }
    else
    {
        if (n==6)
        {//площадь треугольника
            s=(1.0/2.0)*abs((x[1]-x[0])*(y[2]-y[0])-(x[2]-x[0])*(y[1]-y[0]));
        }
        else
        {//длина стороны
            s=sqrt(pow((x[1]-x[0]),2)+pow((y[1]-y[0]),2));
        }
    }
    delete[] x;
    delete[] y;
    va_end(factor);
    return s;
}

int main()
{
    setlocale(LC_ALL,"RUS");
    srand(time(NULL));
    int n;
    double s;
    //bool rez=true;
    cout<<"Введите количество координат."<< endl;
    cin >> n;
    while((n%2!=0)||(n<=2))
    {
        cout<<"Координат должно быть четное количество и больше 2.Введите заново."<< endl;
        cin >> n;
    }
    cout << "Введите координаты(x1,y1,x2,y2,...)" << endl;
    switch (n)
    {
        case (4):
        {
            int a1,a2,a3,a4;
            cin >> a1>> a2>> a3>>a4;
            s=coordinates(n,a1,a2,a3,a4);
            break;
        }
        case (6):
        {
            int a1,a2,a3,a4,a5,a6;
            cin >>a1 >>a2 >>a3 >>a4 >>a5 >>a6;
            s=coordinates(n,a1,a2,a3,a4,a5,a6);
            break;
        }
        case (8):
        {
            int a1,a2,a3,a4,a5,a6,a7,a8;
            cin >>a1 >>a2 >>a3 >>a4 >>a5 >>a6 >>a7 >>a8 ;
            s=coordinates(n,a1,a2,a3,a4,a5,a6,a7,a8);
            break;
        }
        case (10):
        {
            int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
            cin >>a1 >>a2 >>a3 >>a4 >>a5 >>a6 >>a7 >>a8 >>a9 >>a10;
            s=coordinates(n,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10);
            break;
        }
        case (12):
        {
            int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12;
            cin >>a1 >>a2 >>a3 >>a4 >>a5 >>a6 >>a7 >>a8 >>a9 >>a10 >>a11 >>a12;
            s=coordinates(n,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12);
            break;
        }
        case (14):
        {
            int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14;
            cin >>a1 >>a2 >>a3 >>a4 >>a5 >>a6 >>a7 >>a8 >>a9 >>a10 >>a11 >>a12 >>a13 >>a14;
            s=coordinates(n,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14);
            break;
        }
        case (16):
        {
            int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16;
            cin >>a1 >>a2 >>a3 >>a4 >>a5 >>a6 >>a7 >>a8 >>a9 >>a10 >>a11 >>a12 >>a13 >>a14 >>a15 >>a16;
            s=coordinates(n,a1,a2,a3,a4,a5,a6,a7,a8,a9,a10,a11,a12,a13,a14,a15,a16);
            break;
        }
        default:
        {
            break;
        }
    }
    cout << "Результат=" << s;
    return 0;
}









