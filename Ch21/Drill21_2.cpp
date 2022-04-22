#include "std_lib_facilities.h"


template <typename m1, typename m2>
void print(const map<m1,m2>& map)
{
    for(const auto& p : map)
        cout<<p.first<<" "<<p.second <<'\n';
}

void read(map<string,int>& map)
{
    string text;
    int number;
    cin>>text>>number;
    map.insert(pair<string,int>(text,number));
}

int main()
{
    map<string, int> msi;

    msi["lecture"]=21;
    msi["simple"]=43;
    msi["region"]=46;
    msi["message"]=69;
    msi["income"]=63;
    msi["impression"]=23;
    msi["lady"]=37;
    msi["temperature"]=13;
    msi["description"]=31;
    msi["control"]=21;

    print(msi);

    msi.erase(msi.begin(),msi.end());
    cout<<"Erease done. \n";
    print(msi);

    cout<<"Enter 5 pairs:\n";
    while(msi.size()!=5)
    {
        read(msi);
    }

    print(msi);

    int sum = accumulate(msi.begin(),msi.end(),0, [](auto prev_sum, auto &msi_entry){return prev_sum+msi_entry.second;});
    cout<<"Map ints sum: "<<sum<<"\n";

    map<int,string> mis;

    for(auto& mapentry: msi)
        mis[mapentry.second] = mapentry.first;
    
    print(mis);

    return 0;
}