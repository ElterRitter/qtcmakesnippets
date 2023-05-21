#include <QString>

#include <iostream>
using std::cout;

int main(int argc, char* argv[])
{
    QString strHello{"Hello world!"};
    cout << strHello.toStdString();
    return 0;
}
