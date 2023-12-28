#include <iostream>
#include <exception>
using namespace std;

class Custom_Exception:public exception{
public:
    virtual const char* what() const noexcept{ //noexcept means this function will not throw an exception
        return "Custom";
    }
};
//function that throws an exception
void throw_exception(){
    throw 20;
}
//trying throw list (specifying the types of exceptions that can be thrown)
void no_throw_list()throw(){
//    throw "hello";
}
//doesnt work in c++17, and above maybe
void throw_list() /*throw(int,char)*/{
    throw "hello";
}
int main(){
    try{
//      throw 20;
//      you can create a function that throws an exception
//        throw "Hello";
//        throw_exception();
        no_throw_list(); //error because the function isn't supposed to throw anything
        throw Custom_Exception();
    }
    catch(int num){
        cout<<"caught int\n"; //since we didnt use the int num while handling the exception, we can just : catch(int)
    }
    catch(Custom_Exception& c){
        cout<<c.what();
    }
    catch(...){
        cout<<"Default catch\n";
    }
    return 0;
}