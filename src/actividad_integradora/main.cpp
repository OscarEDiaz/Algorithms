#include <iostream>

#include "randomFile.cpp"

using namespace std;

int main()
{
    randomFile x = randomFile("abcdef1234567890", "abc");
    x.generate("./data/transmission1.txt");
    return 0;
}