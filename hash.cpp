//Shan Li and Lucas Manker
//hash



#include <iostream>
#include <functional>
#include <string>
using namespace std;
int main()
{
    string str = "80";
    hash<string> hasher;
    auto hashed = hasher(str);
    cout<<"Unique String value: " << hashed << '\n';

    int8_t num=80;
    hash<int8_t> hasher1;
    auto hashed1 = hasher1(num);
    cout<<"Integer Value: "<<hashed1<<'\n';
}
