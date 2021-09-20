#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool comparator(int x,int y)
{
    return x>y;
}

int main()
{
   vector<int> arr = {1,2,3,4,5};

   cout << "arr[1]: " << arr[1] << endl ;

    //sort
   sort(arr.begin(),arr.end()); // O(NlogN)

    // binary search
    bool present = binary_search(arr.begin(),arr.end(),3);
    cout << "present: " <<present << endl ;

    //print array
    for(int i : arr)
    cout << i << " ";


    //push 
    cout << "\n" ;

    arr.push_back(20);
    arr.push_back(20);
    arr.push_back(20);
    arr.push_back(22);

    for(int i : arr)
    cout << i << " ";

    cout << "\n" ;

    //get element at index i
    cout << "element at index 2: " << arr.at(2) << endl;

    // vector<int> arr(n,0); declare vector of n elements with 0
    //front -> arr.front()
    //back -> arr.back()
    //pop -> arr.pop_back()
    //size -> arr.size()
    //clear -> arr.clear()


    // lower and upper bound

    auto it1 = lower_bound(arr.begin(),arr.end(),20);
    vector<int>::iterator it2 = upper_bound(arr.begin(),arr.end(),20);

    cout << "it1: " << *it1 << endl;
    cout << "it2: " << *it2 << endl;
    cout << "count of 20 : " << it2 - it1 << endl;


    //reverse sort
    sort(arr.begin(),arr.end(),comparator);

    cout << "\n";
    cout << "reverse sort : " ;
    for(int i : arr)
    cout << i << " ";

}
