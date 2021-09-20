#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> v = {2,3,6,7};

    // 1. binary search
    cout << "present: " <<binary_search(v.begin(),v.end(),3) << endl;

    // 2. lower and upper bounds
    cout << "lower bound: " << *lower_bound(v.begin(),v.end(),6) << endl;
    cout << "upper bound: " << *upper_bound(v.begin(),v.end(),6) << endl;

    // 3. min and max
    int a=1,b=2;

    cout << "max: " << max(a,b) << endl;
    cout << "min: " << min(a,b) << endl;

    // 4. swap
    cout << "before swap: " << "a: " << a << " b: " << b << endl;
    swap(a,b);
    cout << "after swap: " << "a: " << a << " b: " << b << endl;


    // 5. reverse
    string str = "abcde" ; 

    cout << "before reverse : " << str << endl;
    reverse(str.begin(),str.end());
    cout << "after reverse : " << str << endl;

    // 6. rotate -> rotate(begin,middle,end) ; {being,end} -> range of elements to be rotated ; middle -> the new first element after rotation
    rotate(v.begin(),v.begin()+2,v.end());

    for(int i: v)
    cout << i << " ";

    cout << "\n";


    // 7. sort -> O(NlogN)

    vector<int> v2 = {6,4,1,9};

    sort(v.begin(),v.end());

    for(int i:v)
    cout << i << " " ;

    cout << "\n";
}