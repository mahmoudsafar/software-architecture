//
//  TATypes.cpp
//  EECE 437
//
//  Created by Mahmoud Safar on 2/5/17.
//  Copyright © 2017 Mahmoud Safar. All rights reserved.
//

#include "TATypes.hpp"
#include <iostream>
using namespace std;



int main() {
    
    

    
//    TABool a("b");
//    a.set(false);
//    TANot t1 (a);
//    TANot t2(t1);
//    
//    TAAnd a1(t1,t1);
//
//    a1.evaluate();
//    
//    a1.printState();
//    a.set(true);
//
//    a1.evaluate();
//
//    cout << "-------------------" << endl;
//  //  cout << t1.value << endl;
//    a1.printState();
//    
//    a1.list();
//    cout << endl;
    
    
//    TADouble a("a");
//    TADouble b("b");
//    
//    TACeiling c1(a);
//   // TAPlusDouble s1 (a, b);
//    //TAPlusDouble s2 (s1, b);
//    
//    
//    a.set(4.5);
//    b.set(3);
//    
//    
//  //  s2.evaluate();
//    
//    
//    TAMinusDouble m1(c1);
//    TAMinusDouble m2(m1, b);
//    
//    m2.evaluate();
//    m2.printState();
//    m2.list();
////    cout << s1.value << endl;
//   // cout << s2.value << endl;
//    
    
    TAArray<TAInt> a( "a", 10);
    
    
    cout << a.size << endl;
    
    
    
    
    
    return 0;
}
