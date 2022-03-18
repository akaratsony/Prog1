#include "std_lib_facilities.h"

struct Person
{
  private:
    string first_name;
    string last_name;
    int age;

  public:
    Person() {}
	  Person(string fn, string ln, int a)
    {
      if (a <= 0 || a > 150)
        error("Incorrect age! Range: [0:150)");
      if (fn == "" || ln == "")
        error("No first or second name was given.");
      if (fn.find_first_of(";:[]*&^%$#@!.") != string::npos 
      || ln.find_first_of(";:[]*&^%$#@!.") != string::npos)
        error("Incorrect name! Contains charater. (;:[]*&^%$#@!.)");
      init(fn, ln, a); 
    }

	  void init(string fn, string ln, int a)
	  {
		  first_name = fn;
      last_name = ln;
		  age = a;
	  }

    string get_first_name() const { return first_name; }
    string get_last_name() const { return last_name; }
	  int get_age() const { return age; } 
};

ostream& operator<<(ostream& os, const Person& p)
{
  os << p.get_first_name() << " " << p.get_last_name() << ":" << p.get_age() << "\n";
  return os;
}

istream& operator>>(istream& is, Person& pp)
{
  string f_n, l_n; int a;
  cout << "First name:";
  is >> f_n;
  cout << "Last name:";
  is >> l_n;  
  cout << "Age:";
  is >> a;
  pp = Person{f_n,l_n,a};
  return is;
}

int main()
{
  Person p1{ "Goofy", "Guys", 63 };
  cout << p1;

  Person p2;
  cin >> p2;
  cout << p2;
  cout << "Sequence of persons! To end input type: end." << "\n";

  vector<Person> vp;
  Person temp;
	for (int i = 0; i < 3; ++i)
	{
		cin >> temp;
		vp.push_back(temp);
	}
  
	for (Person p : vp)
		cout << p;

  return 0;
}
