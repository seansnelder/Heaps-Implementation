#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>



template <typename T, typename PComparator = std::less<T> >

class Heap: private std::vector<T>
{
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator()); //default constructor constructs a binary heap for m = 2; 
  
  
  
  //Heap(int m, PComparator c = PComparator()); 


  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  

private:
  /// Add whatever helper functions and data members you need below
int size_; 
typename std::vector<T>::vector data;
PComparator c;  




};

// Add implementation of member functions here




template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
{

}

template <typename T, typename PComparator> //look at later
Heap<T, PComparator>::~Heap(){

}





// We will start top() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
   /*@return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  if(data.size() == 0){
    throw std::underflow_error("The heap is empty"); 
  }
  else{

  return data[0]; 
  }
  

}

template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const{
 /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
   if(data.size() == 0){
     return true; 
   }
   else{
     return false; 
   }


}

  /**
   * @brief Returns size of the heap
   * 
   */

template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const{

  return data.size(); 

}


template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item){

if (data.empty()) { //building a max 
        data.push_back(item); 
        return; 
    }

data.push_back(item); 

int current = data.size() - 1; //index tracker for push back item
int parent = 0; 
//case where data empty

while(current != 0){
parent = (current - 1)/size_; //note

if(c(data[current], data[parent])){
    std::swap(data[current], data[parent]); 
    current = parent;   
}
else{
  break; 
}


}





}


// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if (data.empty()) {
        throw std::out_of_range("heap is empty");
    }

    std::swap(data[0], data[data.size() - 1]); 
    data.pop_back(); 

    int p = 0; 
    int prioritychild = 0;
    int first = 0; 
    T priorityelement = data[0]; 
    while(size_*p + 1 < data.size()){
      first = size_*p + 1; 
      prioritychild = first; 

        for(int i = first; i < size_*p + size_; ++i){
          if (i < data.size()){
              if (c(data[i], priorityelement)){
                priorityelement = data[i]; 
                prioritychild = i; 
              }
          }
          else{
            break; 
          }
        } 
       
    if(c(data[p], data[prioritychild])){
      break;
    }
    else{
      std::swap(data[p], data[prioritychild]); 
    }
    //update p, stored in max child
    p = prioritychild; 
}
}

/*trickle down(); */




#endif

