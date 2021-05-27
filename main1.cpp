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
    cout << "vector push_back testas su " << size << " elementais truko: " << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - start).count() << " ms" << endl;
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
void atTest()
{
    cout << "          At test: " << endl;
    vector <int> v; 
    int sizes = 10;

    for(int i=0; i<sizes; i++)
    {
        v.push_back(i);
    }
    cout << "Vektoriaus v duomenys:";
    for (unsigned i=0; i<v.size(); i++)
        cout << ' ' << v.at(i);
    cout << endl;
    cout << "Turetu buti: 0 1 2 3 4 5 6 7 8 9" << endl;
}
int main()
{
    assignTest();
    popbackTest();
    pushbackTest();
    reserveTest();
    atTest();
    return 0;
}
