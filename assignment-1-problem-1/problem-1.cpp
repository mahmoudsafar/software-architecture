//
//  HW1-1.cpp
//  EECE 437
//
//  Created by Mahmoud Safar on 2/5/17.
//  Copyright © 2017 Mahmoud Safar. All rights reserved.
//

#include "HW1-1.hpp"
#include <iostream>
using namespace std;



int main() {
    
    
    TADouble x(2);
    TAInt y(3);
    TAEquals z (x, y);
    
    cout << z.output.value << endl;
    
    
    
    
    
    
    return 0;
}
