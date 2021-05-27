#include <iostream>
#include <vector>
#include <iomanip>
#include "vector.hpp"
#include <chrono>

using namespace std;

void assignTest() 
{
    cout << "          Assign test: " << endl;
    Vector<int> v1;
    v1.assign(7, 100);
    cout << "v1 vektoriaus dydis: " << int(v1.size()) << endl;
    cout << "turetu buti 7 " << endl;
}
void popbackTest() 
{
    cout << "          Pop_back test: " << endl;
    int sum = 0;
    Vector<int> v;
    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    int valueAccumulator(0);
    while (!v.empty())
    {
        sum += v.back();
        v.pop_back();
    }
    cout << "vektoriaus v1 elementai susideda iki: " << sum << endl;
    cout << "turetu buti 600" << endl;
}
void pushbackTest()
{
    cout << "          Push_back test: " << endl;
    Vector <int> v;
    int size = 10000; // 100000, 1000000, 10000000, 100000000;
    auto start = chrono::steady_clock::now();
    for(int i=0; i<size; i++)
    {
        v.push_back(i);
    }
    cout << "vector push_back testas su " << size << " elementais truko: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
}

void reserveTest() 
{
    cout << "          Reserve test: " << endl;
    Vector <int> :: size_type sz;
    Vector <int> v1;
    sz = v1.capacity();
    for( int i=0; i<100; i++)
    {
        v1.push_back(i);
        if(sz != v1.capacity())
        {
            sz = v1.capacity();
            cout << "capacity pasikeite: " << sz << endl;
        }
    }
    Vector <int> v2;
    sz = v2.capacity();
    v2.reserve(100);
    for(int i=0; i<100; i++)
    {
        v1.push_back(i);
        if(sz != v2.capacity())
        {
            sz = v2.capacity();
            cout << "capacity pasikeite: " << sz << endl;
        }
    }
}
int main()
{
    cout << "Bus atliekami sie testai: 'assign', 'pop_back', 'push_ back' ir 'reserve': " << endl;
    cout << endl;
    assignTest();
    popbackTest();
    pushbackTest();
    reserveTest();
    return 0;
}