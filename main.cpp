/*
#include "data.hpp"

int main(){
    arc* a1;
    arc* a2; 
    arc* a3; 

    a1->CreateArc(1,2);
    a2->CreateArc(2,1);
    a3->CreateArc(1,3); 

    a1->ChangeCover(4);
    a2->ChangeCover(4);
    a3->ChangeCover(4); 

    std::vector <arc*> p1 = {a1, a2, a3}; 
    trail t1, t2, t3, t4, t5; 
    t1.CreateTrail(p1);
    a1->PrintArc(a1);

    t1.PrintTrail();

   

    arc b1, b2, b3, b4, b5, b6; 

    b1.CreateArc(44,42);
    b2.CreateArc(44,43);
    b3.CreateArc(43,44);
    b4.CreateArc(42,45);
    b5.CreateArc(45,43);
    b6.CreateArc(43,42);

    b1.AddTrail();
    b3.AddTrail();
    b4.AddTrail();
    b5.AddTrail();

    b1.AddTrail();
    b3.AddTrail();
    b4.AddTrail();
    b5.AddTrail();

    b4.AddTrail();
    b3.AddTrail();
    b2.AddTrail();
    b6.AddTrail();

    b1.ChangeCover(5);
    b2.ChangeCover(5);
    b3.ChangeCover(6);
    b4.ChangeCover(6);
    b5.ChangeCover(6);
    b6.ChangeCover(7);

    std::vector <arc> p2 = {b5,b3,b1,b4}; 
    std::vector <arc> p3 = {b3,b1,b4,b5}; 
    std::vector <arc> p4 = {b3,b2}; 
    std::vector <arc> p5 = {b6,b4}; 

    t2.CreateTrail(p2);
    t3.CreateTrail(p3);
    t4.CreateTrail(p4);
    t5.CreateTrail(p5);

    set s1; 
    s1.AddTrail(t1);
    s1.AddTrail(t2);
    s1.AddTrail(t3);
    s1.AddTrail(t4);
    s1.AddTrail(t5);
    s1.PrintSet(); 
}*/
#include "data.hpp"

int main(){
    arc a, b, c; 
    a.create(make_pair(1,2)); 
    b.create(make_pair(2,3)); 
    c.create(make_pair(3,4));  
    trail t1;
    vector <arc> v1 = {a, b, c}; 
    t1 = t1.create(v1); 
    t1.print();


    arc d, e, f;
    d.create(make_pair(1,4));
    e.create(make_pair(4,2));
    f.create(make_pair(2,1));
    trail t2; 
    vector <arc> v2 = { d , e , f};
    t2 = t2.create(v2); 

    arc g, h; 
    g.create(make_pair(4,3));
    h.create(make_pair(3,1));
    trail t3; 
    vector <arc> v3 = {g, h}; 
    t3 = t3.create(v3);

    trail t4;
    vector <arc> v4 = {f, d, g, h};
    t4 = t4.create(v4); 

    set s1; 
    vector <trail> vs1 = {t1, t2, t3, t4};
    s1 = s1.create(vs1);  
    s1.print();
}