#include <iostream>
#include <string>
#include <complex>
#include <numeric>
#include <stdexcept>
#include<iomanip>
#include "include/Matrix.h"
#include "include/MatrixIO.h"


using namespace Numeric_lib;
using namespace std;

void sqrt_operation()
{
    int val;
    cin >> val;
    if (val < 0)
        cout << "no square root.\n";
    else
        cout <<"sqrt: "<< sqrt(val) << '\n';
}

int main()
try{
	//1.
	cout<<"sizeof: "<<"\n";
	cout<<"char: "<<sizeof(char)<<"\n";
	cout<<"short: "<<sizeof(short)<<"\n";
	cout<<"int: "<<sizeof(int)<<"\n";
	cout<<"long: "<<sizeof(long)<<"\n";
	cout<<"float: "<<sizeof(float)<<"\n";
	cout<<"double: "<<sizeof(double)<<"\n";
	cout<<"int*: "<<sizeof(int*)<<"\n";
	cout<<"double*: "<<sizeof(double*)<<"\n\n";

	//2.
	Matrix<int> a(10);
    Matrix<int> b(100);
    Matrix<double> c(10);
    Matrix<int,2> d(10,10);
    Matrix<int,3> e(10,10,10);

	cout<<"sizeof: "<<"\n";
	cout<<"Matrix<int> a(10): "<<sizeof(a)<<"\n";
	cout<<"Matrix<int> b(100): "<<sizeof(b)<<"\n";
	cout<<"Matrix<double> c(10): "<<sizeof(c)<<"\n";
	cout<<"Matrix<int,2> d(10,10): "<<sizeof(d)<<"\n";
	cout<<"Matrix<int,3> e(10,10,10): "<<sizeof(e)<<"\n\n";

	//3.
	cout<<"number of elements: "<<"\n";
	cout<<"Matrix<int> a(10): "<<a.size()<<"\n";
	cout<<"Matrix<int> b(100): "<<b.size()<<"\n";
	cout<<"Matrix<double> c(10): "<<c.size()<<"\n";
	cout<<"Matrix<int,2> d(10,10): "<<d.size()<<"\n";
	cout<<"Matrix<int,3> e(10,10,10): "<<e.size()<<"\n\n";

	//4.
	cout << "Enter 5 int for square_root:\n";
    for (int i = 0; i < 5; ++i)
        sqrt_operation();

    //5.
    Matrix<double> md(10);
    cout << "Enter 10 floating-point values:\n";
    for (int i = 0; i < 10; ++i)
    	cin>>md[i];
    cout<<md<<"\n";

	//6.
	cout << "Multiplication table: ";
	cout<<"Enter n: ";
    int n;
    cin >> n;
    cout << "Enter m: ";
    int m;
    cin >> m;

    Matrix<int,2> multi_table(n,m);

   for(int i = 0; i < multi_table.dim1(); ++i)
   {
		for(int j = 0; j < multi_table.dim2(); ++j)
		{
			multi_table(i,j) = (i+1)*(j+1);
			cout << setw(5) << multi_table(i,j);
		}
		cout<<"\n";
   }

   //7.
    Matrix<complex<double>> complex_matrix(10);
    cout << "Enter 10 complex numbers (Real,Imaginary):\n";
    for (int i = 0; i<complex_matrix.size(); ++i) 
    {
        cin>>complex_matrix[i];
    }

    complex<double> sum;
     for (int i = 0; i<complex_matrix.size(); ++i)
        sum += complex_matrix[i];
    cout << "Sum of the complex numbers:: " << sum << '\n';

    //8.
    Matrix<int,2> matr_eight (2,3);
    cout << "Enter 6 int for Matrix<int,2>m(2,3):\n";
    for (int i = 0; i<matr_eight.dim1(); ++i)
        for (int j = 0; j<matr_eight.dim2(); ++j) 
        {
            cin >> matr_eight(i,j);
        }
    cout<<matr_eight<<"\n";

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