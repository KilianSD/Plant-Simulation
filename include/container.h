#include <vector>

/*
this class was written so that we can catch out_of_range errors instead of 
potentially taking a random out of bound value when subscripting from a vector,
which can lead to undefined behavior.
*/
template<typename T>
class Container : public std::vector<T> {
public: 
    // use the constructors from vector (under the name Vec)
    using std::vector<T>::vector;
    
    // the at function of vector class will throw an error if trying to subscript out of range
    T& operator[](int i){
        return std::vector<T>::at(i);
    }

    const T& operator[](int i) const {
        return std::vector<T>::at(i);
    }
};