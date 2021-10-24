#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char s1[50], s2[50];

    cout << "Enter first name: ";
    cin.getline(s1, 50);

    cout << "Enter last name: ";
    cin.getline(s2, 50);

    strcat(s1, s2);

    cout << "s1 = " << s1 << endl;


    return 0;
}
