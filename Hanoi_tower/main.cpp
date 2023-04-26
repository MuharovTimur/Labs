#include <iostream>
using namespace std;

int Han(int n,int start,int temp,int point)//start-стержень,с которого нужно переместить temp-стержень,на который нужно переместить point-вспомогательный стержень
{
    if(n>0)
    {
        Han(n-1,start,point,temp);
        cout << start << "=>" << temp << endl;
        Han(n-1,point,temp,start);
    }
    return 0;
}

int main()
{
    setlocale(0,"");
    int n;
    cout << "Input amout of hoops: ";
    cin >> n;
    Han(n,1,3,2);
    return 0;
}
