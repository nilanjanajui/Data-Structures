#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

int main() 
{
    ifstream oldmastfile("oldmast.txt");
    ifstream transfile("trans.txt");
    ofstream newmastfile("newmast.txt");
    ofstream logfile("log.txt");

    if (!oldmastfile || !transfile || !newmastfile || !logfile) 
    {
        cout << "Error opening files." << endl;
        return 1;
    }
    
    map<int, double> Account_balances;

    // Read oldmast.txt
    string line;
    while (getline(oldmastfile, line)) 
    {
        stringstream ss(line);
        int Account_No;
        double Balance;
        if (ss >> Account_No >> Balance) {
            Account_balances[Account_No] = Balance;
        }
    }

    // Read and Process trans.txt
    while (getline(transfile, line)) 
    {
        stringstream ss(line);
        int Account_No;
        double Amount;
        if (ss >> Account_No >> Amount) 
        {
            if (Account_balances.find(Account_No) != Account_balances.end()) 
            {
                Account_balances[Account_No] += Amount;
            } 
            else 
            {
                logfile << "Unmatched transaction for A/C No. " << Account_No << endl;
            }
        }
    }

    // Write updated balances to newmast.txt
    for (const auto & entry : Account_balances) 
    {
        newmastfile << entry.first << " " << entry.second << endl;
    }

    oldmastfile.close();
    transfile.close();
    newmastfile.close();
    logfile.close();

    cout << "Processing completed." << endl;

    return 0;
}
