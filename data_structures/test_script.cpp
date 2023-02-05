#include <iostream>
#include <vector>
#include <string>

using namespace std;

float foo(float x)
{
    return x*x;
}
int main()
{
    string s = "Hello world, it's Masha";
    cout << s << '\n' << endl;
    float x = foo(5.0f);
    cout << x << endl;
}

