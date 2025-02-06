#include<iostream>
#include<list>

using namespace std;

int main()
{
    //create a list
    list<int>numbers={5,6,2};
    list<int>numbers2={3,2,1};

    //display the original list
    cout<<"Initial List: ";
    for (int number: numbers)
    {
        cout<<number<<",";
    }

    //add element at the beginning 
    numbers.push_front(0);

    //add element at the end
    numbers.push_back(4);

    cout<<endl<<"Final List: ";
    for(int number:numbers)
    {
        cout<<number<<",";
    }

    numbers.sort();
    for(int number:numbers)
    {
        cout<<number<<",";
    }

    numbers.reverse();
    for(int number:numbers)
    {
        cout<<number<<"\n";
    }

    numbers.unique();
    for(int number:numbers)
    {
        cout<<number<<"\n";
    }

    numbers.merge(numbers2);
    for(int number:numbers)
    {
        cout<<number<<"\n";
    }
    
    numbers.size();
    for(int number:numbers)
    {
        cout<<number<<"\n";
    }

    return 0;
}