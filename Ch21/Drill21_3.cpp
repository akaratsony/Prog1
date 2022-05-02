#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include <stdexcept>
#include <algorithm>
#include<iterator>
#include<numeric>

using namespace std;

void fill_vec(istream& is, vector<double>& vec_d)
{
    for (double d; is >> d; ) vec_d.push_back(d);
}

int main()
try{
    //1.
    vector<double> vd;
    string iname {"szoveg.txt"};
    ifstream ist {iname};
    if (!ist) runtime_error("can't open input file "+ iname);
    fill_vec(ist,vd);

    //2.
    cout<<"Vector elements:\n";
    for(auto& x : vd)
        cout<<x<<"\n";

    //3.
    vector<int> vi (vd.size());
    copy(vd.begin(),vd.end(),vi.begin());
    
    //4.
    cout<<"Vector elements (vd[i],vi[i]):\n";
    for (int i = 0; i <  vd.size(); ++i)
        cout<<"("<<vd[i]<<","<<vi[i]<<") \n";

    //5.    
    double vd_sum = accumulate(vd.begin(),vd.end(),0.0);
    cout<<"vd elements sum: "<<vd_sum<<"\n";

    //6.
    double vi_sum = accumulate(vi.begin(),vi.end(),0);
    cout<<"vd-vi difference: "<<vd_sum-vi_sum<<"\n";

    //7.
    reverse(vd.begin(),vd.end());
    cout<<"Reverse:\n";
    for(auto& x : vd)
        cout<<x<<"\n";

    //8. 
    double mean = vd_sum/vd.size();
    cout<<"Mean value of vd: "<<mean<<"\n";

    //9.
    vector<double> vd2;
    copy_if(vd.begin(),vd.end(),back_inserter(vd2),
        [mean](auto& vd_entry){ return vd_entry<mean;});

    cout<<"vd2 elements:\n";
    for(auto& x : vd2)
        cout<<x<<"\n";

    //10.
    sort(vd.begin(),vd.end());
    cout<<"vd sort:\n";
    for(auto& x : vd)
        cout<<x<<"\n";

    return 0;
}
catch(std::exception& e) {
    std::cerr << "Exception: " << e.what() << '\n';
    return 1;
}
catch(...) {
    std::cerr << "Something went wrong! \n";
    return 2;
}