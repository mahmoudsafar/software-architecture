//
//  HW1-1.hpp
//  EECE 437
//
//  Created by Mahmoud Safar on 2/5/17.
//  Copyright © 2017 Mahmoud Safar. All rights reserved.
//

#ifndef HW1_1_hpp
#define HW1_1_hpp

#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

//Types

class TABool
{
public:
    //Attributes
    bool value;
    //Constructors
    TABool(){};
    TABool( bool x )
    {
        value = x;
    }
    
    
};

class TAInt
{
public:
    //Attributes
    int value;
    //Contructors
    TAInt(){};
    TAInt( int x )
    {
        value = x;
    }
    
};

class TADouble
{
public:
    //Attributes
    double value;
    //Contructors
    TADouble(){};
    TADouble( double x )
    {
        value = x;
    }
    
};


///////////////////////
//Operations

class TANot
{
public:
    //Attributes
    TABool output;
    //Constructors
    TANot( TABool x )
    {
        output.value = ~x.value;
    }
};

class TACeiling
{
public:
    //Attributes
    TADouble output;
    //Constructors
    TACeiling( TADouble x )
    {
        output.value = ceil(x.value);
    }
};

class TAFloor
{
public:
    //Attributes
    TADouble output;
    //Constructors
    TAFloor( TADouble x )
    {
        output.value = floor(x.value);
    }
};

class TAAnd
{
public:
    //Attributes
    TABool output;
    //Constructors
    TAAnd( TABool x, TABool y )
    {
        output.value = x.value && y.value;
    }
};

class TAOr
{
public:
    //Attributes
    TABool output;
    //Constructors
    TAOr( TABool x, TABool y )
    {
        output.value = x.value || y.value;
    }
};

class TAXor
{
public:
    //Attributes
    TABool output;
    //Constructors
    TAXor( TABool x, TABool y )
    {
        output.value = ~x.value || y.value;
    }
};

class TAPlus
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    TADouble outputDouble;
    TAInt outputInt;
    //Constructors
    TAPlus( TAInt x, TAInt y ) //Integers
    {
        outputInt.value = x.value + y.value;
        outputDouble.value = NULL;
    }
    
    TAPlus( TADouble x, TADouble y ) //Double
    {
        outputDouble.value = x.value + y.value;
        outputInt.value = NULL;
    }
};

class TAMinus
{
public:
    //Attributes
    TADouble outputDouble;
    TAInt outputInt;
    
    //Constructors
    TAMinus( TAInt x, TAInt y ) //Integers
    {
        outputInt.value = x.value - y.value;
        outputDouble.value = NULL;
    }
    TAMinus( TADouble x, TADouble y ) //Double
    {
        outputDouble.value = x.value - y.value;
        outputInt.value = NULL;
    }
    TAMinus (TAInt x)
    {
        outputInt.value = -x.value;
        outputDouble.value = NULL;
    }
    TAMinus (TADouble x)
    {
        outputDouble.value = -x.value;
        outputInt.value = NULL;
    }
    
};

class TAMultiply
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    TADouble outputDouble;
    TAInt outputInt;
    //Constructors
    TAMultiply( TAInt x, TAInt y ) //Integers
    {
        outputInt.value = x.value * y.value;
        outputDouble.value = NULL;
    }
    
    TAMultiply( TADouble x, TADouble y ) //Double
    {
        outputDouble.value = x.value * y.value;
        outputInt.value = NULL;
    }
};

class TADivide
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    TADouble outputDouble;
    TAInt outputInt;
    //Constructors
    TADivide( TAInt x, TAInt y ) //Integers
    {
        outputInt.value = x.value / y.value;
        outputDouble.value = NULL;
    }
    
    TADivide( TADouble x, TADouble y ) //Double
    {
        outputDouble.value = x.value / y.value;
        outputInt.value = NULL;
    }
};

class TALesser
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    TABool output;
    //Constructors
    TALesser( TAInt x, TAInt y ) //Integers
    {
        output.value = x.value < y.value;
    }
    
    TALesser( TADouble x, TADouble y ) //Double
    {
        output.value = x.value < y.value;
    }
};

class TAGreater
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    TABool output;
    //Constructors
    TAGreater( TAInt x, TAInt y ) //Integers
    {
        output.value = x.value > y.value;
    }
    
    TAGreater( TADouble x, TADouble y ) //Double
    {
        output.value = x.value > y.value;
    }
};

class TAEquals
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    TABool output;
    //Constructors
    TAEquals( TAInt x, TAInt y ) //Integers
    {
        output.value = x.value == y.value;
    }
    
    TAEquals( TADouble x, TADouble y ) //Double
    {
        output.value = x.value == y.value;
    }
};

//////////////////////




#endif /* HW1_1_hpp */
