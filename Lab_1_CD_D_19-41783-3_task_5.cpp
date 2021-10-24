#include <iostream>
using namespace std;

int main()
{
    int i, s;
    double sum=0, average=0;

        cout << "\n\nEnter the number integers you want in an array: ";
        cin >> s;
    int arr[s];
        cout << "\n\n Enter " << s << " integers into an array :\n\n";

    for (i = 0; i < s; i++)
    {
        cout << " Enter arr [ " << i << " ] : ";
        cin >> arr[i];
    }

        cout << "\n\n The Elements of the Array are : \n\n";

    for (i = 0; i < s; i++)
    {
        cout << " arr [ " << i << " ] = " << arr[i] << endl;
        sum += arr[i];
    }
    average = sum/s;
        cout << "\n\n The Average of the Elements of the Array is : " << average << "\n\n";
        cout << "\n\n";
return 0;
}
