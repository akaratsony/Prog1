/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double) { return 1; }

double square(double x) { return x*x; }

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;
 

    Simple_window win {Point{100,100}, xmax, ymax, "Canvas"};
//Ablak Beállításai 

//grid beállítása
    int x_grid = 100;
    int y_grid = 100;

 Lines grid;
    for (int x = x_grid; x < xmax; x+=x_grid)
        grid.add(Point(x,0),Point(x,800));
    for (int y = y_grid; y < ymax; y+=y_grid)
        grid.add(Point(0,y),Point(800,y));

    //Grid szinezeése Vectorral

    Vector_ref<Rectangle> diagonal;

    for (int i = 0; i<8; i++)
    {
        diagonal.push_back(new Rectangle{Point{i*100,i*100},100,100});
        diagonal[i].set_fill_color(Color::red);
        win.attach(diagonal[i]);
    }

    //Képek feltöltése
Image bmw1 {Point{400,200},"bmw.jpg"};
Image bmw2 {Point{200,600},"bmw.jpg"};
Image bmw3 {Point{0,200},"bmw.jpg"};
Image figura {Point{0,0},"figura.jpg"};
   win.attach(grid);
win.attach(bmw1);
win.attach(bmw2);
win.attach(bmw3);
win.attach(figura);

 //kép mozgatása
    int figura_x = 100;
    int figura_y = 0;
    int counter = 0;
    int big_counter = 0;
    while(win.wait_for_button())
    {
        figura.move(figura_x,figura_y);
        counter += 1;
        big_counter +=1;
        if (counter == 8)
        {
           figura_x = -800;
            figura_y = 100; 
           figura.move(figura_x,figura_y);
           figura_x = 100;
            figura_y = 0;
            counter = 0;
        }
        if (big_counter == 64)
        {
            return 0;
        }
    }
    win.wait_for_button();


    
}
