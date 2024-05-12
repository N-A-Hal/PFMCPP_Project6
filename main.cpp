/*
 Project 6: Part 1 / 2
 Video: Chapter 3 Part 2

Create a branch named Part1

Purpose:  This project will show you the difference between member functions and static class functions, as well as the difference between pointers and references and the code semantics that accompany pointers and references.

 Pointers

 Please look at the screenshot in the files to see what happens if you paste this assignment into an existing cpp file in an xcode project
 
 Task: replace all of the <#place holder#> placeholders with proper names and types that will make this program compile and run.
 
 press the Compile, link and run... button and work your way through all of the error messages.
 

 steps:
 
 1) finish implementing the constructor for T. the constructor parameters need to initialize 2) and 3)
 
 2) provide a member variable in T of a type of your choosing that works with the compare function below T
         note the name of the variable used in the compare function
 
 3) provide a member variable of type std::string in T that works with the *first* cout statement in main().
         note the name of the variable used in the *first* cout statement in main()
 
 4) finish defining the struct with the compare function
 5) provide proper types for the arguments to compare, and a proper return value
         be sure to make it work with the pointer semantics being used in the if statements.
         see 8) for a hint about what type to use.
 
 6) finish instantiating the two T instances being declared in main(), based on the constructor you finished implementing in T
     Their names (line 105,106) are different than the member variables names (line 77), even tho the placeholders share the same name.
     Don't let this confuse you.
 
 7) Declare 'f' with the proper type so the call to f.compare works
 
 8) call f.compare() with the correct arguments, based on 2) and 5)
 
 9) correct the cout that uses smaller's member variable with some safe pointer usage.
    the possible return values of the compare() function should give you a hint.
    Also: if smaller == nullptr, make the cout statement explain the reasons that `f.compare()` might return nullptr.  
    hint: There are multiple reasons
 
 10) complete the implementation for the static function in <structName2>
 
 11) call the <structName2> static function correctly in main()
 
 12) replicate the functionality of <structName2>'s static function by implementing a member function in U that does the same thing.
 
 13) remember the rules for using pointers!  What is the one thing we always do before we use a pointer?
 
 After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

#include <iostream>
#include <string>
struct T
{
    int value;
    std::string name;
    T(int v, const char* n)   //1
    {
        this->value = v;         //2
        this->name = n;           //3
    }
};

struct L                                //4
{
    T* compare(T* a, T* b) //5
    {
        if (a == nullptr) return nullptr;
        if (b == nullptr) return nullptr;
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr;
    }
};


struct U
{
    float m { 0 }, n { 0 };
    float memberFunction(float* newValue)      //12
    {
        if(newValue == nullptr)
        {
            std::cout << "newValue is nullptr, 0 is returned" << std::endl;
            return 0.0f;
        }
        std::cout << "U's m value: " << this->m << std::endl;
        this->m = *newValue;
        std::cout << "U's m updated value: " << this->m << std::endl;
        while( std::abs(this->n - this->m) > 0.001f )
        {
            this->n += 0.0001f * this->m;
        }
        std::cout << "U's n updated value: " << this->n << std::endl;
        return this->n * this->m;
    }
};

struct Q
{
    static float staticFunction(U* that, float* newValue )        //10
    {
        if(that == nullptr)
        {
            std::cout << "that is nullptr, 0 is returned" << std::endl;
            return 0.0f;
        }
        if(newValue == nullptr)
        {
            std::cout << "newValue is nullptr, 0 is returned" << std::endl;
            return 0.0f;
        }
        
        std::cout << "U's m value: " << that->m << std::endl;
        that->m = *newValue;
        std::cout << "U's m updated value: " << that->m << std::endl;
        while( std::abs(that->n - that->m) > 0.001f )
        {
            that->n += 0.0001f * that->m;
        }
        std::cout << "U's n updated value: " << that->n << std::endl;
        return that->n * that->m;
    }
};


/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T a(35, "John");                                           //6
    T b(35, "Rob");                                           //6
    
    T* ptrTo_a = &a;  
    T* ptrTo_b = &b; 
    
    L f;                                        //7

   
    auto* smaller = f.compare(ptrTo_a, ptrTo_b);                              //8
    if(smaller != nullptr)
    {
        std::cout << "the smaller one is << " << smaller->name << std::endl; //9
    }
    else if (ptrTo_a == nullptr)
    {
        std::cout << "ptrTo_a is nullptr" << std::endl;
    }
    else if (ptrTo_b == nullptr)
    {
        std::cout << "ptrTo_b is nullptr" << std::endl;
    }
    else
    {
        std::cout << "smaller is nullptr because compared values are equal" << std::endl; 
    }
    
    
    U x;
    float updatedValue = 5.f;
    std::cout << "[static func] x's multiplied values: " << Q::staticFunction(&x, &updatedValue) << std::endl;                  //11
    
    U y;
    std::cout << "[member func] y's multiplied values: " << y.memberFunction(&updatedValue) << std::endl;
    
}
