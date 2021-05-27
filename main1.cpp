#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

void pushbackTest()
{
    cout << "          Push_back test: " << endl;
    vector <int> v;
    int size = 10000; // 100000, 1000000, 10000000, 100000000;
    auto start = chrono::steady_clock::now();
    for(int i=0; i<size; i++)
    {
        v.push_back(i);
    }
    vector <int> v2;
    int size1 = 10000; // 100000, 1000000, 10000000, 100000000;
    auto start1 = chrono::steady_clock::now();
    for(int i=0; i<size1; i++)
    {
        v.push_back(i);
    }
    cout << "vector push_back testas su " << (size + size1)/2 << " elementais truko: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start1).count() << " ms" << endl;
}
void assignTest()
{
    vector <int> v1;
    vector <int> v2;
    vector <int> v3;
    v1.assign(7,100);
    cout << "v1 vektoriaus dydis: " << int(v1.size()) << endl;
    cout << "turetu buti 7 " << endl;
}
void popbackTest()
{
    int sum = 0;
    vector <int> v;
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
void reserveTest()
{
    vector <int> :: size_type sz;
    vector <int> v1;
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
    vector <int> v2;
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
    assignTest();
    popbackTest();
    pushbackTest();
    reserveTest();
    return 0;
}