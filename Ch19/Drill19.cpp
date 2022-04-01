#include "std_lib_facilities.h"

template<typename T>
struct S
{
    
    S() {}
    S(T t): val(t){}

    S& operator=(T tt) {val = tt; return *this;}
    
    void set(T t) { val = t;}
    const T& get() const {return val;}

    T& get_non_const() {return val;}

    private:
        T val;
};

template<typename T>
const T& get(S<T>& s)
{
    return s.get();
}

template<typename T>
void read_val(T& v)
{
    cin >> v;
}


int main()
{
    S<int> si;
    cout << "Int: "; read_val(si.get_non_const());
    cout << get(si) << "\n";

    S<char> sc;
    cout << "Char: "; read_val(sc.get_non_const());
    cout << get(sc) << "\n";
    
    S<double> sd;
    cout << "Double: "; read_val(sd.get_non_const());
    cout << sd.get() << "\n";

    S<string> ss;
    cout << "String: "; read_val(ss.get_non_const());
    cout << ss.get() << "\n";

    S<vector<int>> svi(vector<int>(5,15));
    for(int i: get(svi))
        cout << i << ";";
    cout << "\n";

    return 0;
}