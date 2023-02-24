#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

using namespace std; 

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack();


    ~Stack();
    bool empty() const;
    size_t size() const;
    void push(const T& item);
    void pop();  // throws std::underflow_error if empty
    const T& top() const; // throws std::underflow_error if empty
    // Add other members only if necessary
private: 
    std::vector<T> v; 

};
//this->member_func() since both classes have that function and it will default to the derived version and lead to an infinite recursion. 
//Instead, scope the call (e.g. LList<T>::size()).

template <typename T>
Stack<T>::Stack(){


}

template <typename T>
Stack<T>::~Stack(){

}



template <typename T>
bool Stack<T>::empty() const{ //checks if it empty or not; 

    return v.empty(); 

}
template <typename T>
size_t Stack<T>::size() const{
    return v.size(); //this is how you call the base class functions from inheritance
    //vector<int>:: (scope), method name

    }

template <typename T>
void Stack<T>::push(const T& item){

    v.push_back(item); 

    }

template <typename T>
void Stack<T>::pop(){
        if(empty()){
            throw std::underflow_error("Stack is empty"); 
        }
        else{
            v.pop_back(); 
 
        }


    }  // throws std::underflow_error if empty
template <typename T>
const T& Stack<T>::top() const{
        if(empty()){
            throw std::underflow_error("Stack is empty"); 
        }
        else{
        return v.back(); 
        
        

        }

    } // throws std::underflow_error if empty

#endif

/*Element access:
operator[]	Access element (public member function)
at	Access element (public member function)
front	Access first element (public member function)
back	Access last element (public member function)
data*/

