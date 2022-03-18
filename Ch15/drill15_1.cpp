/*
    g++ drill15.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main.out `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return cos(x)+slope(x); }

int main()
{
    using namespace Graph_lib;

    constexpr int xmax = 600;
    constexpr int ymax = 600;
    constexpr int length = 400;
    constexpr int x_orig = xmax/2;
    constexpr int y_orig = ymax/2;
    constexpr int r_min = -10;
    constexpr int r_max = 11;
    constexpr int n_points = 400;
    constexpr int x_scale = 20;
    constexpr int y_scale = 20;
    Point orig {x_orig,y_orig};

    Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};

    Axis x {Axis::x,Point{100,y_orig},length,length/20,"1 == 20 pixels"};
    Axis y {Axis::y,Point{x_orig,length+100},length,length/20,"1 == 20 pixels"};

    x.set_color(Color::red);
    y.set_color(Color::red);

    Function s {one,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s2 {slope,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s3 {square,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s4 {cos,r_min,r_max,orig,n_points,x_scale,y_scale};
    Function s5 {sloping_cos,r_min,r_max,orig,n_points,x_scale,y_scale};

    Text ts2 {Point{100,y_orig+80},"x/2"};
    s4.set_color(Color::blue);

    win.attach(x);
    win.attach(y);
    win.attach(s);
    win.attach(s2);
    win.attach(s3);
    win.attach(s4);
    win.attach(s5);
    win.attach(ts2);

    win.wait_for_button();

 
}
