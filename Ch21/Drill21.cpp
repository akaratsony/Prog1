#include "std_lib_facilities.h"

struct Item
{
    Item() : name(), id(), value() {}
    Item(string nname, int iid, double vvalue) : name(nname), id(iid), value(vvalue) {}
    
    string name;
    int id;
    double value;
};

istream& operator>>(istream& is, Item& it)
{
    string nn;
    int ii;
    double vv;
    
    is>>nn>>ii>>vv;
    Item readed {nn, ii, vv};
    it = readed;
    return is;
}

ostream& operator<<(ostream&os, Item& it)
{
    return os << it.name << " " << it.id << " " << it.value << "\n";
}

template<typename T>
void print(T& t)
{
    for (auto p = t.begin(); p!= t.end(); ++p)
        cout << *p;
    cout << "\n";
}

int main()
{
    vector<Item> vi;
    ifstream ist {"data.txt"};

    for (Item temp; ist >> temp;) vi.push_back(temp);

    cout << "Data: " << "\n";
    print(vi);

    string a, b;
    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b){return a.name < b.name;});
    cout << "Sorted by name: " << "\n";
    print(vi);

    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b){return a.id < b.id;});
    cout << "Sorted by id: " << "\n";
    print(vi);

    sort(vi.begin(), vi.end(), [](const Item& a, const Item& b){return a.value > b.value;});
    cout << "Sorted by decreasing value: " << "\n";
    print(vi);

    Item horse_shoe {"horse shoe",99,12.34};
    Item canon_s400 {"Canon S400",9988,499.95};
    vi.insert(vi.begin(), horse_shoe);
    vi.insert(vi.begin(), canon_s400);
    cout << "Items inserted: " << "\n";
    print(vi);

    string name = "six";
    vi.erase(find_if(vi.begin(),vi.end(), [name](const Item& a){return a.name == name;}));
    cout << "Name removed: " << "\n";
    print(vi);

    int id = 4;
    vi.erase(find_if(vi.begin(), vi.end(), [id](const Item& a){return a.id == id;}));
    cout << "ID removed: " << "\n";
    print(vi);

    return 0;
}