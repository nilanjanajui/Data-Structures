/* Write a C program that takes two binary string as input and 
 estimate their simple matching coefficient (SMC) score as follows:  */
 

#include <iostream>
#include <string>

using namespace std;

int main() 
{
    string x, y;
    int f01 = 0, f10 = 0, f00 = 0, f11 = 0;

    cout << "Enter binary string x: ";
    cin >> x;
    cout << "Enter binary string y: ";
    cin >> y;

    if (x.length() != y.length()) 
    {
        cout << "Error: Binary strings must be of equal length."<< endl;
        return 1;
    }

    for (size_t i = 0; i < x.length(); ++i) 
    {
        if (x[i] == '0' && y[i] == '1')
        {
            ++f01;
        }
        else if (x[i] == '1' && y[i] == '0')
        {
            ++f10;
        }
        else if (x[i] == '0' && y[i] == '0')
        {
            ++f00;
        }
        else if (x[i] == '1' && y[i] == '1')
        {
            ++f11;
        }
        
    }

    double SMC = (double)(f11 + f00) / (f01 + f10 + f11 + f00);

    cout << "f01 = " << f01 << endl;
    cout << "f10 = " << f10 << endl;
    cout << "f00 = " << f00 << endl;
    cout << "f11 = " << f11 << endl;
    
    cout << "Simple Matching Coefficient (SMC) = " << SMC << endl;

    return 0;
}
