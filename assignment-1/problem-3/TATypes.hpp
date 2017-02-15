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
#include <string>

using namespace std;


class TASuper
{
public:
    
    TASuper()
    {
    }
    
};


class TAPair : public TASuper
{
protected:
    TASuper *first;
    TASuper *next;
    
    
    
public:
    TAPair( TASuper &x, TASuper &y)
    {
        first = &x;
        next = &y;
    }
    
    
    
    
};


template <class T>
class TAArray : public TASuper
{
   public:
    string name;
    int size;
    T* array;
    

    TAArray ( string x, int s)
    {
        array = new T[s];
        size = s;
        name = x;
    }
    
    
    
    
};



//Types


class TABool : public TASuper
{
protected:
    //Attributes
    bool value;
    string name;
    
public:

    //Constructors
    TABool()
    {
        name = "bool";
    }
    TABool(string x){
        name = x;
        value = true;
        
    };
    
    void set ( bool x )
    {
        value = x;
    }
    
    virtual bool evaluate()
    {
        return value;
    }
    
    void printState()
    {
        cout << value << endl;
    }
    
    virtual void list()
    {
        cout << " " << name << " ";
        
    }
    
    
};


class TAInt : public TASuper
{
protected:
    //Attributes
    int value;
    string name;
public:
    
    //Contructors
    TAInt(){
        name = "int";
    };
    TAInt( string x )
    {
        name = x;
    }
    
    
    void set ( int x )
    {
        value = x;
    }
    virtual int evaluate()
    {
        //cout << "f" << endl;
        return value;
    }
    
    void printState()
    {
        cout << value << endl;
    }
    
    virtual void list()
    {
        cout << " " << name << " ";
        
    }
    
};



class TADouble : public TASuper
{
protected:
    //Attributes
    double value;
    string name;
public:
    //Contructors
    TADouble(){
        name = "double";
    };
    TADouble( string x )
    {
        name = x;
    }
    void set ( double x )
    {
        value = x;
    }
    virtual double evaluate()
    {
        
        return value;
    }
    
    void printState()
    {
        cout << value << endl;
    }
    
    virtual void list()
    {
        cout << " " << name << " ";
        
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
        input = &x;
    }
    
    TANot( TANot &x )
    {
        input = &x;
    }
    
    virtual bool evaluate()
    {
        value = !(input->evaluate());
        return value;
    }
    
    virtual void list()
    {
        cout << " (NOT ";
        input->list();
        cout << " ) ";
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
        value = ceil(x.evaluate());
        input = &x;
    }
    virtual double evaluate()
    {
//        input->evaluate();  // Recursive process to re evaluate previous inputs
        value = ceil(input->evaluate());
        return value;
    }
    
    virtual void list()
    {
        cout << " (ceiling ";
        input->list();
        cout << " ) ";
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
        value = floor(x.evaluate());
        input = &x;
    }
    virtual double evaluate()
    {
//        input->evaluate();
        value = floor(input->evaluate());
        return value;
    }
    
    virtual void list()
    {
        cout << " (floor ";
        input->list();
        cout << " ) ";
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
        input1 = &x;
        input2 = &y;
    }
    virtual bool evaluate()
    {
        value = input1->evaluate() && input2->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (& ";
        input1->list();
        input2->list();
        cout << " ) ";
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
        input1 = &x;
        input2 = &y;
    }
    virtual bool evaluate()
    {
        value = input1->evaluate() || input2->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (OR ";
        input1->list();
        input2->list();
        cout << " ) ";
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
        input1 = &x;
        input2 = &y;
    }
    virtual bool evaluate()
    {
        value = input1->evaluate() != input2->evaluate();
        return value;
    }
    virtual void list()
    {
        cout << " (XOR ";
        input1->list();
        input2->list();
        cout << " ) ";
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
        input1 = &x;
        input2 = &y;
    }
    virtual bool evaluate()
    {
        value = !input1->evaluate() || input2->evaluate();
        return value;
    }
    virtual void list()
    {
        cout << " (Implies ";
        input1->list();
        input2->list();
        cout << " ) ";
    }
};





class TAPlusInt : public TAInt
{
public:
    //Attributes
    
    TAInt *input1 = NULL;
    TAInt *input2 = NULL;
    //Constructors
    
    TAPlusInt( TAInt &x, TAInt &y ) //Integers
    {
        //TAInt::value = x.value + y.value;
        input1 = &x;
        input2 = &y;
    }
    
    virtual int evaluate()
    {
        
        value = input1->evaluate() + input2->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (+ ";
        input1->list();
        input2->list();
        cout << " ) ";
    }
    
    
    
};

class TAPlusDouble : public TADouble
{
public:
    //Attributes
    
    TADouble *input1 = NULL;
    TADouble *input2 = NULL;
    //Constructors
    
    TAPlusDouble( TADouble &x, TADouble &y ) //Integers
    {
        //TAInt::value = x.value + y.value;
        input1 = &x;
        input2 = &y;
    }
    
    virtual double evaluate()
    {
        
        value = input1->evaluate() + input2->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (+ ";
        input1->list();
        input2->list();
        cout << " ) ";
    }
    
    
    
};








class TAMinusInt : public TAInt
{
public:
    //Attributes
    TAInt *input1 = NULL;
    TAInt *input2 = NULL;

    
    //Constructors
    TAMinusInt( TAInt &x, TAInt &y ) //Integers
    {
        //TAInt::value = x.value - y.value;
        input1 = &x;
        input2 = &y;
    }

    ///////////
    
    TAMinusInt (TAInt &x)
    {
        //TAInt::value = -x.value;
        input1 = &x;
    }
    
    TAMinusInt (TAMinusInt &x)
    {
        input1 = &x;
    }
    
    
    virtual int evaluate()
    {
        if (input2 != NULL)
            value = input1->evaluate() - input2->evaluate();
        else
            value = -input1->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (- ";
        input1->list();
        if(input2 != NULL)
            input2->list();
        cout << " ) ";
    }
    
    
    
};

class TAMinusDouble : public TADouble
{
public:
    //Attributes
    TADouble *input1 = NULL;
    TADouble *input2 = NULL;
    
    
    //Constructors
    TAMinusDouble( TADouble &x, TADouble &y ) //Integers
    {
        //TAInt::value = x.value - y.value;
        input1 = &x;
        input2 = &y;
    }

    ///////////
    
    TAMinusDouble (TADouble &x)
    {
        //TAInt::value = -x.value;
        input1 = &x;
    }
    
    TAMinusDouble (TAMinusDouble &x)
    {
        input1 = &x;
    }
    
    
    virtual double evaluate()
    {
        if (input2 != NULL)
            value = input1->evaluate() - input2->evaluate();
        else
            value = -input1->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (- ";
        input1->list();
        if(input2 != NULL)
            input2->list();
        cout << " ) ";
    }
    
    
    
};






class TAMultiplyInt : public TAInt
{
public:
    //Attributes
    
    TAInt *input1 = NULL;
    TAInt *input2 = NULL;
    //Constructors
    
    TAMultiplyInt( TAInt &x, TAInt &y ) //Integers
    {
        input1 = &x;
        input2 = &y;
    }
    
    virtual int evaluate()
    {
        
        value = input1->evaluate() * input2->evaluate();
        return value;
    }
};

class TAMultiplyDouble : public TADouble
{
public:
    //Attributes
    
    TADouble *input1 = NULL;
    TADouble *input2 = NULL;
    //Constructors
    
    TAMultiplyDouble( TADouble &x, TADouble &y ) //Integers
    {
        input1 = &x;
        input2 = &y;
    }
    
    virtual double evaluate()
    {
        
        value = input1->evaluate() * input2->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (* ";
        input1->list();
        input2->list();
        cout << " ) ";
    }
};


class TADivideInt : public TAInt
{
public:
    //Attributes
    
    TAInt *input1 = NULL;
    TAInt *input2 = NULL;
    //Constructors
    
    TADivideInt( TAInt &x, TAInt &y ) //Integers
    {
        input1 = &x;
        input2 = &y;
    }
    
    virtual int evaluate()
    {
        
        value = input1->evaluate() / input2->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (/ ";
        input1->list();
        input2->list();
        cout << " ) ";
    }
};

class TADivideDouble : public TADouble
{
public:
    //Attributes
    
    TADouble *input1 = NULL;
    TADouble *input2 = NULL;
    //Constructors
    
    TADivideDouble( TADouble &x, TADouble &y ) //Integers
    {
        input1 = &x;
        input2 = &y;
    }
    
    virtual double evaluate()
    {
        
        value = input1->evaluate() / input2->evaluate();
        return value;
    }
    
    virtual void list()
    {
        cout << " (/ ";
        input1->list();
        input2->list();
        cout << " ) ";
    }
};



class TALesser : public TABool
{
public:
    //Attributes
    
    TAInt *input1Int = NULL;
    TAInt *input2Int = NULL;
    TADouble *input1Double = NULL;
    TADouble *input2Double = NULL;
    //Constructors
    
    TALesser( TAInt &x, TAInt &y ) //Integers
    {
        input1Int = &x;
        input2Int = &y;
    }
    
    TALesser( TADouble &x, TADouble &y ) //Integers
    {
        input1Double = &x;
        input2Double = &y;
    }
    
    
    
    virtual bool evaluate()
    {
        if( input1Int == NULL && input2Int == NULL)
        {
            value = input1Double->evaluate() < input2Double->evaluate();
        return value;
        }
        else
        {
            value = input1Int->evaluate() < input2Int->evaluate();
            return value;
        }
    }
    
    virtual void list()
    {
        if( input1Int == NULL && input2Int == NULL)
        {
            cout << " (< ";
            input1Double->list();
            input2Double->list();
            cout << " ) ";
        }
        else
        {
        cout << " (< ";
        input1Int->list();
        input2Int->list();
        cout << " ) ";
        }
    }
};

class TAGreater : public TABool
{
public:
    //Attributes
    
    TAInt *input1Int = NULL;
    TAInt *input2Int = NULL;
    TADouble *input1Double = NULL;
    TADouble *input2Double = NULL;
    //Constructors
    
    TAGreater( TAInt &x, TAInt &y ) //Integers
    {
        input1Int = &x;
        input2Int = &y;
    }
    
    TAGreater( TADouble &x, TADouble &y ) //Integers
    {
        input1Double = &x;
        input2Double = &y;
    }
    
    
    
    virtual bool evaluate()
    {
        if( input1Int == NULL && input2Int == NULL)
        {
            value = input1Double->evaluate() > input2Double->evaluate();
            return value;
        }
        else
        {
            value = input1Int->evaluate() > input2Int->evaluate();
            return value;
        }
    }
    
    virtual void list()
    {
        if( input1Int == NULL && input2Int == NULL)
        {
            cout << " (> ";
            input1Double->list();
            input2Double->list();
            cout << " ) ";
        }
        else
        {
            cout << " (> ";
            input1Int->list();
            input2Int->list();
            cout << " ) ";
        }
    }
};

class TAEquals : public TABool
{
public:
    //Attributes
    
    TAInt *input1Int = NULL;
    TAInt *input2Int = NULL;
    TADouble *input1Double = NULL;
    TADouble *input2Double = NULL;
    //Constructors
    
    TAEquals( TAInt &x, TAInt &y ) //Integers
    {
        input1Int = &x;
        input2Int = &y;
    }
    
    TAEquals( TADouble &x, TADouble &y ) //Integers
    {
        input1Double = &x;
        input2Double = &y;
    }
    
    
    
    virtual bool evaluate()
    {
        if( input1Int == NULL && input2Int == NULL)
        {
            value = input1Double->evaluate() == input2Double->evaluate();
            return value;
        }
        else
        {
            value = input1Int->evaluate() == input2Int->evaluate();
            return value;
        }
    }
    
    virtual void list()
    {
        if( input1Int == NULL && input2Int == NULL)
        {
            cout << " (== ";
            input1Double->list();
            input2Double->list();
            cout << " ) ";
        }
        else
        {
            cout << " (== ";
            input1Int->list();
            input2Int->list();
            cout << " ) ";
        }
    }
};

//////////////////////




#endif /* TATypes_hpp */
