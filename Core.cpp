#include "Core.hpp"

template<typename T>
int Core<T>::lastId = -1;

template<typename T>
int Core<T>::nbInstance = 0;

template<typename T>
Core<T>::Core():id(++lastId){
    nbInstance++;
    degradation = 0;
    values = new vector<T>();
}

template<typename T>
int Core<T>::getId() const{
    return id;
}

template<typename T>
int Core<T>::getDegradation() const{
    return degradation;
}

template<typename T>
vector<T>* Core<T>::getValues() const{
    return values;
}

template<typename T>
int Core<T>::getCount(){
    return nbInstance;
}

template<typename T>
void Core<T>::set(vector<T> * values){
    this->values = values;
}

template<typename T>
Core<T> & Core<T>::map(bool(*func)(T&)){
    for(auto it = values->begin(); it != values->end(); ++it){
        if(!func(*it)) {
            values->erase(it);
            it--;
        }
    }
    degradation++;
    return *this;
}

template<typename T>
template<typename U>
U Core<T>::reduce(U(*func)(U,T), U z){
    for(auto it = values->begin(); it != values->end(); ++it){
       z=func(z,*it);
    }
    degradation++;
    return z;
}

template<typename T>
ostream& operator<<(ostream& out, const Core<T> * obj) {
    out << "----Core----" << endl;
    out << "id " << obj->getId() << ", degradation " << obj->getDegradation() << endl;
    if(!obj->getValues()->empty()){
        out << "values : [ ";
        for(T value : *(obj->getValues())){
            out << value << " ";
        }
        out << "]" << endl << "-------";
    }
    return out;
}