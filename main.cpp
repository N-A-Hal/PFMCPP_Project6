/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
    Not every pointer can be converted.
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.

    You have to ask yourself if each pointer can be converted to a (const) reference.
    Think carefully when making your changes.

 2) revise the 'else' statement in main() that handles when `smaller` is a nullptr. 
 there is only one reason for `compare` to return nullptr. 
 Update this std::cout expression to specify why nullptr was returned.
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
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
        if( a != nullptr && b != nullptr )
        {
            if( a->value < b->value ) return a;	
            if( a->value > b->value ) return b;
        }

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
