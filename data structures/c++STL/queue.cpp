#include<iostream>
#include<deque>
#include<queue>

using namespace std;

int main()
{
    deque<int> d; // in deque elements can be removed and inserted from front and back
    queue<pair<int,int>> q; // in queue elements can be removed only from front and added to back

    d.push_back(1);
    d.push_front(2);
    
    q.push({1,1});
    q.push({1,3});

    cout << "deque : ";
    for(int i: d)
    cout << i << " " ;    

    cout << "\n";

    cout << "front of queue : " << "{" << q.front().first << "," << q.front().second << "}" << endl;
}