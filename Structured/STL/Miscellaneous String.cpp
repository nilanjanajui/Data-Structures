#include<iostream>
#include<list>
#include<bits/stdc++.h>

using namespace std;
int main()
{
    //create a list
    list<string>numbers={"dd"};
    list<string>numbers2={"cc"};
    list<string>numbers3={};
    string s="Dept of CSE CU";
    //display the original list
    cout<<"Initial List: ";
    for (string number: numbers){
        cout<<number<<"\n";
    }
    //add element at the beginning 
    numbers.push_front("aa");

    //add element at the end
    numbers.push_back("bb");

    cout<<endl<<"Final List: ";
    for(string number:numbers){
        cout<<number<<"\n";
    }
    numbers.sort();
    for(string number:numbers) {
        cout<<number<<",";
    }

    numbers.reverse();
    for(string number:numbers){
        cout<<number<<"\n";
    }

    numbers.unique();
    for(string number:numbers){
        cout<<number<<"\n";
    }

    numbers.merge(numbers2);
    for(string number:numbers){
        cout<<number<<"\n";
    }

stringstream ss(s);
string eachword;
while(ss>>eachword) {
    numbers3.push_back(eachword);

}
for(string number: numbers3){
    cout<<number<<",";
}   
    return 0;
}