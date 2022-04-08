#include "std_lib_facilities.h"

 //templategen

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while (f1 != e1)
    {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}


int main()
{
     //létrehozás
    int array[10] = {0,1,2,3,4,5,6,7,8,9};

    vector<int> v{0,1,2,3,4,5,6,7,8,9};

    list<int> l{0,1,2,3,4,5,6,7,8,9};

    
    int array2[10];

    copy(begin(array), end(array), begin(array2));



    vector<int> v2 = v;

    list<int> l2 = l;

    for(int& i : array)
        i += 2;

    for(int& i : v)
        i += 3;
    
    for(int& i : l)
        i += 5;


    //Ki iratások
    cout << "=============" <<"\n";
    cout << "1) Array: " << "\n";
    cout <<"\n";

    for(int i = 0; i < 10; i++)
        cout << array[i];
    cout << "\n";

    my_copy(begin(array), end(array), begin(v2));

    cout << "=============" <<"\n";
    cout << "2) Vektor  copied: " << "\n";
    cout <<"\n";
    
    for(int& i : v2)
        cout << i;
    cout << "\n";

    cout << "=============" <<"\n";
    cout << "1) List: " << "\n";
        cout <<"\n";
    for(int& i : l)
        cout << i;
    cout << "\n";
    cout << "=============" <<"\n";

    my_copy(begin(l), end(l), begin(array2));
    cout << "2) Copied array: " << "\n";
    for(int i = 0; i < 10; i++)
        cout << array2[i];
    cout << "\n";

    auto found = find(begin(v), end(v), 3);

    if (found != end(v))
        cout << "3 is found at position:" << distance(begin(v), found) << "\n";
    else
        cout << "3 not found in vector." << "\n";
    
    auto found2 = find(begin(l), end(l), 27);

    if (found2 != end(l))
        cout << "27 is found at position:" << distance(begin(l), found2) << "\n";
    else
        cout << "27 not found in list." << "\n";

    return 0;
}