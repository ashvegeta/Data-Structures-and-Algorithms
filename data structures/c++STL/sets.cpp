#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main()
{
    // find/delete in O(NlogN) time
    // build sets in O(N) time

    set<int> s;

    s.insert(1);
    s.insert(2);
    s.insert(-1);
    s.insert(-10);

    // for(int i: s)
    // cout << i << endl;


    //search in sets
    auto it = s.find(10);

    cout << *it << " " <<*s.end() << endl; // if it==s.end() element not present
    
    auto it2 = s.lower_bound(-1);

    cout << *it2 << endl;

    it2 = s.upper_bound(-1);

    cout << *it2 << endl;
}