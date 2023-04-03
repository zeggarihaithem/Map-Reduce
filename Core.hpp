#ifndef CORE
#define CORE

#include <vector>
#include <iostream>
using namespace std;
template<typename T>
class MapReduce;
template<typename T>
class Core{
    friend MapReduce<T>;
    private:
        static int lastId;//pour générer les ids automatiquement
        static int nbInstance;//le nombre d'instanciations
        const int id;//immuable
        int degradation;//le taux de dégradation
        vector<T> * values; //pointeur vers vector
        Core();
    public:
        int getId() const;
        int getDegradation() const;
        static int getCount();
        vector<T>* getValues() const;
        void set(vector<T> * values);
        Core<T> & map(bool(*func)(T&));
        template<typename U>
        U reduce(U(*func)(U,T), U z);
};

template<typename T>
ostream& operator<<(ostream& out, const Core<T> * obj);

#endif




