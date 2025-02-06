//(Intersection between Two Lists) Compatible for vector as well


#include<iostream>
#include<list>
#include<algorithm>
#include<iterator>

using namespace std;
int main()
{
    list<string>doc1={"Data", "is", "the", "new", "oil", "of", "the", "digital", "economy"};
    list<string>doc2={"Data", "is", "a", "new", "oil"};
    list<string>common_list;
    

    doc1.sort();
    doc2.sort();
    doc1.merge(doc2);
    doc1.sort();
    doc1.unique();

    cout<<endl<<"Size:"<<doc1.size();
    
    list<string>doc3={"Data", "is", "the", "new", "oil", "of", "the", "digital", "economy"};
    list<string>doc4={"Data", "is", "a", "new", "oil"};

    /*for(string word1:doc3)
    {
        for(string word2:doc4){
            if(word1==word2)
            {
                count++;  
            }
        }
    }*/

    // method of set_intersection

    doc3.sort();
    doc4.sort();
    set_intersection 
    (
        doc3.begin(),doc3.end(),
        doc4.begin(),doc4.end(),
        back_inserter(common_list)
    );

    //cout<<"\nsize is: "<<count;

    for(string word:common_list){
        cout<<word<<",";
    }
    cout<<"\ndoc3,doc4:"<<(float)common_list.size()/(float)doc1.size();

    return 0;
}