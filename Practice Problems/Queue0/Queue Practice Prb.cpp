//Given a line of text, reverse the text without reversing the individual words.

#include <iostream>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;

int main() 
{
    string sentence = "Technical Interview Preparation";
    queue<string> qu;
    stack<string> s;

    stringstream ss(sentence);
    string word;

    while (ss >> word) 
    {
        qu.push(word);
    }

    while (!qu.empty()) 
    {
        s.push(qu.front());
        qu.pop();
    }

    string reversedSentence = " ";

    while (!s.empty()) 
    {
        reversedSentence += s.top() + " ";
        s.pop();
    }

    if (!reversedSentence.empty()) 
    {
        reversedSentence.pop_back();
    }

    cout << reversedSentence << endl;

    return 0;
}


