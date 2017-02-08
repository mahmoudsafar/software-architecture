//
//  HW1-1.cpp
//  EECE 437
//  THIS IS A TEST FILE
//  Created by Mahmoud Safar on 2/5/17.
//  Copyright © 2017 Mahmoud Safar. All rights reserved.
//

#include "HW1-1.hpp"
#include <iostream>
using namespace std;



int main() {
    
    
    //Test
    
//    TABool tt(true);
//    
//    TANot z(tt);
//    
//    cout << z.value << endl;
//    
//    tt.set(false);
//    z.evaluate();
//
//    TANot ss(z);
//    TANot v(ss);
//    cout << z.value << endl;
//    ss.set(true);
//    v.evaluate();
//    
//    cout << v.value << endl;
    
    
    
    
//    TABool a;
//   // cout << a.value << endl;
//    TANot t1 (a);
//  //  cout << t1.value << endl;
//    
//    TANot t2(t1);
//    
//    TAAnd a1(t2,a);
//    
//    cout << a1.value << endl;
//    
//    a.set(true);
//    //t1.evaluate();
//    //t2.evaluate();
////
//    cout << a1.value << endl;
//    a1.evaluate();
//    cout << a1.value << endl;
//    cout << "-------------------" << endl;
//    cout << t1.value << endl;
//    cout << t2.value << endl;
//    
//    
//    
//    cout << "-------------------" << endl;
//    cout << t1.value << endl;
//    cout << t2.value << endl;
    
    
//    TAXor xx(a,b);
//    
//    cout << xx.value << endl;
    
//    TAAnd d(a, b);
//    TAAnd e(d, c);
//
//    TAOr d(a, b);
//    TAOr e(b, c);
    
//    TAInt x1(4);
//    TAInt x2(5);
//    
//    TALesser b1(x1, x2);
//    TAAnd b2 (a, b1);

//    TADouble d1(5.5);
//    TACeiling c1(d1);
//    cout << c1.value << endl;
//    
//    d1.set(4.4);
//    cout << c1.value << endl;
//    c1.evaluate();
//    cout << c1.value << endl;
    
    
    //cout << b2.value << endl;

    
//    TAPlus s1(x1,x2);
//    TAPlus s2(s1,x1);
//    
//    s1.TAInt::set(5);
//    x1.set(1);
//    TAPlus s3(s1,x1);
    
//    cout << s1.TAInt::value << endl;
//    cout << s2.TAInt::value << endl;
//    cout << s3.TAInt::value << endl;
    
    
// Testing Evaluate
    
    TAInt x1(3);
    TAInt x2(4);
    TAInt x3(10);
    TAPlus s1(x1, x2);
    
    TAPlus s2(s1, x3);
    TAPlus s3( s2, s1);
    
    x1.set(1);
    
    cout << s3.TAInt::value << endl;
    
    s3.evaluate();
    
    cout << s3.TAInt::value << endl;
    
    
    
    return 0;
}
