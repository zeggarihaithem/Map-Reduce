#ifndef MAPREDUCE
#define MAPREDUCE


#include <vector>
#include <iostream>

#include "Core.hpp"

template<typename T>
class MapReduce{
    private:
        vector<T> * values; //pointeur vers vector
        Core<T> * core; // coeur courant
    public:
        static const vector<Core<T> *> cores;
        MapReduce(vector<T> * values);
        static void afficherCores();
        vector<T> * getValues();
        Core<T>* getCore();
        Core<T> * chooseCore();
        MapReduce<T> * map(bool(*func)(T&));
};
#endif

