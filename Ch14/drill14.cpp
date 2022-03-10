#include "std_lib_facilities.h"

class B1 
{
public:
    virtual void vf() { cout << "B1::vf " << "\n"; }  // Virtual  mivel szeretném felülirni. Ehhez ugyan olyan típusunak kell lennie a felülirandónak is
                                                        // tehát ha const akkor a felüliro  függvény is const ha nem akkor nem 
    void f() { cout << "B1::f" << "\n"; }                   // nem írjuk felül
    virtual void pvf() = 0;                                 // felülirhato a pvf értéke 0 lesz
};

class D1 : public B1                                      // Ő egy D1 ami örökli a B1 függvényeit és ha Referencia értékként hivatkozunk rá akkor a 
                                                            // B1 vf fügvényét és a pvf füvvgényét felülirjhatjuk 
{
public:
    void vf() override { cout << "D1::vf" << "\n"; }            //felül irjuk a b1 VF függvényét
    void f() { cout << "D1::f" << "\n"; }                   // Ha nem referencia értéként hivatkozunk akkor ezt írja ki
    void pvf() override { cout << "D1::pvf" << "\n"; }          // felülirjuk
};

class D2 : public D1
{
public:
    void pvf() override { cout << "D2::pvf" << "\n"; }
};

class B2
{
public:
    virtual void pvf() = 0;
};

class D21 : public B2
{
public:
    string s;    
    void pvf() override { cout << s << "\n"; }
};

class D22 : public B2
{
public:
    int i;    
    void pvf() override { cout << i << "\n"; }
    void f(B2& b2r) { b2r.pvf(); } //  D21-es REFERENCIA ami felül írja a b2r.pvf függvényt mivel virtual így a
    // D21ből ki irja a stringet
};

int main()
{

    /* Ez azt az eredményt adja, amíg nincs a D1-ben f() 1-3
    B1::vf()
    B1::f()
    D1::vf()
    B1::f()//Öröklés miatt B1::f()-et kapunk meg, mert nincs a D1-ben f()
    D1::vf()
    B1::f()
    4. feladat után:
    Ahol már a D1-ben megírt az f():
    B1::vf()
    B1::f()
    D1::vf()
    D1::f() //Megírtuk az f()-et
    D1::vf()
    D1::f()
    */


    /* 1
    B1 b1;
    b1.vf();
    b1.f();
    */

    
    //2.
    D1 d1;
    d1.vf();
    d1.f();
    d1.pvf();
    // Ezeket mindegyiket a saját osztályánál ki irja mivel nem referenciaként hivunk

    //3.
    B1& b1r = d1;       //  a d1 örökli a b1 referencia tulajdonságait -- !!a B1 referencia nem latja D1 f()-et
    b1r.vf();        // A D1 vf()-et hívja mivel a B1 vf() virtual tehát overridolhato
    b1r.f();        // -->B1 f()-et hivja mivel nem virtual tehát nem felülírható



    //6.Feladat
    //Példányosítás
    D2 d2;
    d2.vf();  // D1 vf() mivel kiterjeszti a D1-et
    d2.f(); // D1 F() mivel kiterejeszti a D1-et
    d2.pvf(); // D2 PVF() mivel ezt statikusan hívjuk ki
    
    /* 
    6.Feladat után
    D1::vf()
    D1::f()
    D2::pvf()
    */

    //7

    D21 d21; 
    d21.s = "String data.";

    D22 d22;
    d22.i = 15;

    d22.f(d21);
    d22.f(d22);

    return 0;
}