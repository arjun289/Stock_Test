#include "Stock.h"
#include <conio.h>

int main(int argc, char* argv[])
{
    Stock test1;
    test1.stockLoad("G:\\gocontento\\Essayshark\\stocklist\\stock_test\\stockdata.txt");
    test1.stockprint();
    cout<<endl;
    cout << "middle of the list"<<endl;
    test1.returnMiddleofList();
    cout<<endl;
    test1.splitList();
    _getch();
    return 0;
}

