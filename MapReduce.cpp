#include "MapReduce.hpp"

template<typename T>
const vector<Core<T> *> MapReduce<T>::cores = {
   new Core<T>(),
   new Core<T>(),
   new Core<T>(),
   new Core<T>()
};

template<typename T>
MapReduce<T>::MapReduce(vector<T> * values){
   this->values = values;
}

template<typename T>
void MapReduce<T>::afficherCores(){
   cout << "****Coeurs disponibles****" << endl;
   for(Core<T> * core : cores){
      cout << "id : " << core->getId() << " |  degradation  " << core->getDegradation() << endl;
   }
}

template<typename T>
vector<T> * MapReduce<T>::getValues(){
   return values;
}

template<typename T>
Core<T> * MapReduce<T>::getCore(){
   return core;
}

template<typename T>
Core<T> * MapReduce<T>::chooseCore(){
   if(cores.empty()) return nullptr;
   this->core = cores.at(0);
   for(Core<T> * coreIt : cores){
      if(this->core->getDegradation() > coreIt->getDegradation())this->core = coreIt;
   }
   this->core->set(values);
   return this->core;
}

template<typename T>
MapReduce<T> * MapReduce<T>::map(bool(*func)(T&)){
   chooseCore();
   core->map(func);
   return this;
}
