#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main()
{
    // find/delete in O(NlogN) time
    // build maps in O(N) time
    
    // ordered map implemented using red-black trees and AVL trees 
    map<char,int> m1; //ordered map access/insert/delete in O(NlogN)

    // un_ordered map implemented using hash table 
    unordered_map<char,int> m2; //un_ordered map has O(1) access time

    string str = "ashikmp";

    for (char i : str)
    m1[i]++;

    for (char i : str)
    m2[i]++;

    cout << "ordered map : " << endl;
    for (auto it : m1)
    cout << "key : " << it.first << " value: " << it.second << " ";

    cout << "\n" ;

    cout << "un_ordered map : " << endl;
    for (auto it : m2)
    cout << "key : " << it.first << " value: " << it.second << " ";

    cout << "\n" ;
}