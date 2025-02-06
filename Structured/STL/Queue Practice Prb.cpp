//Given a line of text, reverse the text without reversing the individual words.

#include <iostream>
#include <queue>
#include <stack>
#include <sstream>

using namespace std;



int main() 
{
    string sentence = "Technical Interview Problem";
    queue<string> qu;
    stack<string> s;
    
    stringstream ss(sentence);
    string word;
    
    // Enqueue each word into the queue
    while (ss >> word) 
    {
        qu.push(word);
    }
    
    // Dequeue words from the queue and push them onto the stack
    while (!qu.empty()) 
    {
        s.push(qu.front());
        qu.pop();
    }
    
    string reversedSentence = " ";
    
    // Pop words from the stack and append them to the result string
    while (!s.empty()) 
    {
        reversedSentence += s.top() + " ";
        s.pop();
    }
    
    // Remove the extra space at the end
    if (!reversedSentence.empty()) 
    {
        reversedSentence.pop_back();
    }
    
    
    cout << reversedSentence << endl;
    
    return 0;
}