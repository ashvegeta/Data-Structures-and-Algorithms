#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main()
{
    // 1. using vectors
    vector<int> heap = {2,3,1,4,8};

    make_heap(heap.begin(),heap.end()); //makes max heap by default

    cout << "max: " << heap.front() << endl;

    // 2. using priority queue class
    cout << "\n";
    cout << "using STL pq" << endl;
    priority_queue<int> max_h; // max heap by default

    max_h.push(5);
    max_h.push(1);
    max_h.push(10);
    max_h.push(30);
    max_h.push(20);

    cout << "max: " << max_h.top() << endl;
    max_h.pop();
    cout << "max after removing top: " << max_h.top() << endl;
    cout << "\n";


    priority_queue<int,vector<int>,greater<int>>  min_h; // min heap

    min_h.push(5);
    min_h.push(1);
    min_h.push(10);
    min_h.push(30);
    min_h.push(20);

    cout << "min : " << min_h.top() << endl;
    min_h.pop();
    cout << "min after removing top: " << min_h.top() << endl;






}