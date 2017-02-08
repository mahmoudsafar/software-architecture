//
//  TATypes.hpp
//  EECE 437
//
//  Created by Mahmoud Safar on 2/5/17.
//  Copyright © 2017 Mahmoud Safar. All rights reserved.
//

#ifndef TATypes_hpp
#define TATypes_hpp

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
    TABool(){
        value = true;
    };
    TABool( bool x )
    {
        value = x;
    }
    
    void set ( bool x )
    {
        value = x;
    }
    
    void evaluate()
    {
        //Does nothing, ends recursive process
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
    void set ( int x )
    {
        value = x;
    }
    void evaluate()
    {
        //Does nothing, ends recursive process
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
    void set ( double x )
    {
        value = x;
    }
    void evaluate()
    {
        //Does nothing, ends recursive process
    }
};


///////////////////////
//Operations

class TANot : public TABool
{
public:
    //Attributes
    TABool *input;
    //Constructors
    TANot( TABool &x )
    {
        value = !x.value;
        input = &x;
    }
    TANot( TANot &x)
    {
        value = !x.value;
        input = &x;
    }
    
    void evaluate()
    {
        input->evaluate();  // Recursive process to re evaluate previous inputs
        value = !(input->value);
    }
};

class TACeiling : public TADouble
{
public:
    //Attributes
    TADouble *input;
    //Constructors
    TACeiling( TADouble &x )
    {
        value = ceil(x.value);
        input = &x;
    }
    void evaluate()
    {
        input->evaluate();  // Recursive process to re evaluate previous inputs
        value = ceil(input->value);
    }
};

class TAFloor : public TADouble
{
public:
    //Attributes
    TADouble *input;
    //Constructors
    TAFloor( TADouble &x )
    {
        value = floor(x.value);
        input = &x;
    }
    void evaluate()
    {
        input->evaluate();  // Recursive process to re evaluate previous inputs
        value = floor(input->value);
    }
};

class TAAnd : public TABool
{
public:
    //Attributes
    TABool *input1;
    TABool *input2;
    //Constructors
    TAAnd( TABool &x, TABool &y )
    {
        value = x.value && y.value;
        input1 = &x;
        input2 = &y;
    }
    void evaluate()
    {
        input1->evaluate();  // Recursive process to re evaluate previous inputs
        input2->evaluate();  // Recursive process to re evaluate previous inputs
        value = input1->value && input2->value;
    }
    
};

class TAOr : public TABool
{
public:
    //Attributes
    TABool *input1;
    TABool *input2;
    //Constructors
    TAOr( TABool &x, TABool &y )
    {
        value = x.value || y.value;
        input1 = &x;
        input2 = &y;
    }
    void evaluate()
    {
        input1->evaluate();  // Recursive process to re evaluate previous inputs
        input2->evaluate();  // Recursive process to re evaluate previous inputs
        value = input1->value || input2->value;
    }
};

class TAXor : public TABool
{
public:
    //Attributes
    TABool *input1;
    TABool *input2;
    //Constructors
    TAXor( TABool &x, TABool &y )
    {
        value = x.value != y.value;
        input1 = &x;
        input2 = &y;
    }
    void evaluate()
    {
        input1->evaluate();  // Recursive process to re evaluate previous inputs
        input2->evaluate();  // Recursive process to re evaluate previous inputs
        value = input1->value != input2->value;
    }
};

class TAImplies : public TABool
{
public:
    //Attributes
    TABool *input1;
    TABool *input2;
    //Constructors
    TAImplies( TABool &x, TABool &y )
    {
        value = !x.value || y.value;
        input1 = &x;
        input2 = &y;
    }
    void evaluate()
    {
        input1->evaluate();  // Recursive process to re evaluate previous inputs
        input2->evaluate();  // Recursive process to re evaluate previous inputs
        value = !input1->value || input2->value;
    }
};



class TAPlus : public TAInt, public TADouble
{
public:
    //Attributes
    TAInt *inputInt1 = NULL;
    TAInt *inputInt2 = NULL;
    TADouble *inputDouble1 = NULL;
    TADouble *inputDouble2 = NULL;
    //Constructors
    TAPlus( TAInt &x, TAInt &y ) //Integers
    {
        TAInt::value = x.value + y.value;
        inputInt1 = &x;
        inputInt2 = &y;
    }
    
    TAPlus( TADouble x, TADouble y ) //Double
    {
        TADouble::value = x.value + y.value;
        inputDouble1 = &x;
        inputDouble2 = &y;
    }
    
    TAPlus( TAPlus x, TAPlus y ) //No constraints yet??
    {
        if( x.inputInt1 == NULL && y.inputInt1 == NULL )  //To ensure that the previous operations were used with a certain type
        {
            TADouble::value = x.TADouble::value + y.TADouble::value;
        }
        else
        {
        TAInt::value = x.TAInt::value + y.TAInt::value;
        }
    }
    
    void evaluate()
    {
        if ( inputInt1 == NULL && inputInt1 == NULL )
        {
            inputDouble1->evaluate();  // Recursive process to re evaluate previous inputs
            inputDouble2->evaluate();  // Recursive process to re evaluate previous inputs
            TADouble::value = inputDouble1->value + inputDouble2->value;
        }
        else
        {
            inputInt1->evaluate();  // Recursive process to re evaluate previous inputs
            inputInt2->evaluate();  // Recursive process to re evaluate previous inputs
            TAInt::value = inputInt1->value + inputInt2->value;
        }
    }
    
    
};


class TAMinus : public TAInt, public TADouble
{
public:
    //Attributes
//    TADouble outputDouble;
//    TAInt outputInt;
    
    //Constructors
    TAMinus( TAInt x, TAInt y ) //Integers
    {
        TAInt::value = x.value - y.value;
    }
    
    TAMinus( TADouble x, TADouble y ) //Double
    {
        TADouble::value = x.value - y.value;
    }
    
    TAMinus( TAMinus x, TAMinus y ) //No constraints yet??
    {
        TADouble::value = x.TADouble::value - y.TADouble::value;
        TAInt::value = x.TAInt::value - y.TAInt::value;
    }
    
    TAMinus (TAInt x)
    {
        TAInt::value = -x.value;
    }
    TAMinus (TADouble x)
    {
        TADouble::value = -x.value;
    }
    TAMinus (TAMinus const &x)
    {
        TADouble::value = -x.TADouble::value;
        TAInt::value = -x.TAInt::value;
    }
    
};

class TAMultiply : public TAInt, public TADouble
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
//    TADouble outputDouble;
//    TAInt outputInt;
    //Constructors
    TAMultiply( TAInt x, TAInt y ) //Integers
    {
        TAInt::value = x.value * y.value;
    }
    
    TAMultiply( TADouble x, TADouble y ) //Double
    {
        TADouble::value = x.value * y.value;
    }
    
    TAMultiply( TAMultiply x, TAMultiply y ) //No constraints yet??
    {
        TADouble::value = x.TADouble::value * y.TADouble::value;
        TAInt::value = x.TAInt::value * y.TAInt::value;
    }
};

class TADivide : public TAInt, public TADouble
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
//    TADouble outputDouble;
//    TAInt outputInt;
    
    bool isDouble = false;
    bool isInt = false;
    
    //Constructors
    TADivide( TAInt x, TAInt y ) //Integers
    {
        TAInt::value = x.value / y.value;
    }
    
    TADivide( TADouble x, TADouble y ) //Double
    {
        TADouble::value = x.value / y.value;
    }
    
    TADivide( TADivide x, TADivide y ) //No constraints yet??
    {
        TADouble::value = x.TADouble::value / y.TADouble::value;
        TAInt::value = x.TAInt::value / y.TAInt::value;
    }
    
    
    
    
    
};

class TALesser : public TABool
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    //TABool output;
    //Constructors
    TALesser( TAInt x, TAInt y ) //Integers
    {
        value = x.value < y.value;
    }
    
    TALesser( TADouble x, TADouble y ) //Double
    {
        value = x.value < y.value;
    }
};

class TAGreater : public TABool
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    //TABool output;
    //Constructors
    TAGreater( TAInt x, TAInt y ) //Integers
    {
        value = x.value > y.value;
    }
    
    TAGreater( TADouble x, TADouble y ) //Double
    {
        value = x.value > y.value;
    }
};

class TAEquals : public TABool
{
public:
    //Attributes
    //To choose whether outputInt or outputDouble should be shown, state that in a function
    //TABool output;
    //Constructors
    TAEquals( TAInt x, TAInt y ) //Integers
    {
        value = x.value == y.value;
    }
    
    TAEquals( TADouble x, TADouble y ) //Double
    {
        value = x.value == y.value;
    }
};

//////////////////////




#endif /* TATypes_hpp */
