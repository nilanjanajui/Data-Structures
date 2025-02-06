/* • accumulate 
– Sums up elements in a
range (based on a starting sum value)
• inner_product 
– Computes the inner (also known as “dot”) product of two matrixes: sum of the products of their respective elements */

#include<iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{
    vector<int> v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);
    
    cout<< "v contains ";
    for(size_t s=0; s<v.size(); s++)
    {
        cout<< v[s] << " ";
    }
    cout<< endl;
    cout << "the sum of the elements in v is " << accumulate (v.begin(), v.end(), 0) << endl;
    cout << "the inner product of v and itself is " << inner_product (v.begin(), v.end(), v.begin(), 0) << endl;

    return 0;

}