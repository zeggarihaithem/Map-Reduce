#include "Core.cpp"

#include "MapReduce.cpp"


int sum(int x, int y)
{
    return x + y;
}

bool positive(int &x)
{
    if(x > 0){
        return true;
    }
    return false;
}

bool gt50(int &x)
{
    if(x > 50){
        return true;
    }
    return false;
}


int count(int i1, std::string i2)
{
    return i1+1;
}


bool countains(std::string  &i)
{
    if(i.find("p") != std::string::npos){
        return true; 
    }
	return false;
}


bool example(std::string  &i)
{
    if(i.find("o") != std::string::npos){
        i = i+"j";
        return true; 
    }
    return false;
}

int main(int argc, char **argv)
{


    std::vector<int> b = std::vector<int>( { 12, 3, 100 ,60, -7, -8, -9, -10 } );

    MapReduce<int> mri(&b);

    // 0- Affichage du nombre de coeurs initiaux
    std::cout<<std::endl<< "####### test 0 #######"<<std::endl;
    std::cout<< std::endl<<"Nombre de coeurs initiaux: "<<Core<int>::getCount()<<std::endl;


    //1- Décommentez pour tester si on peut instancier un nouveau coeur (ne doit pas fonctionnererrr)
    //Core<int> core1;


    //2 - Test d'affichage des coeurs disponibles (id s'incrémente et degradation 0)
    std::cout<<std::endl<< "####### test 2 #######"<<std::endl<<std::endl;
    MapReduce<int>::afficherCores(); 

    //3- Choix et affichage d'un coeur avec l'operateur <<
    std::cout<<std::endl<< "####### test 3 #######"<<std::endl<<std::endl;
    std::cout<< mri.chooseCore()<< std::endl;

    //4- Tester ma possibilité de faire core.map(...).map(...)
    Core<int> & core = mri.map(positive)->getCore()->map(gt50);
    std::cout<<std::endl<< "####### test 4 #######"<<std::endl<<&core << std::endl;

    //5- Tester ma possibilité de faire mri.map(...)->map(...) puis reduce
    std::cout<<std::endl<< "####### test 5 #######"<<std::endl;
    std::cout<<std::endl<< "Resultat mapReduce : " <<mri.map(positive)->map(gt50)->chooseCore()->reduce(sum, 0) << std::endl<< std::endl;
    
    // 6- les dégradations doivent etre plus ou moins bien réparties dans les coeurs 
    std::cout<<std::endl<< "####### test 6 #######"<<std::endl;
    MapReduce<int>::afficherCores();

    // 7- le nombre de coeurs instancés ne doit pas changer à la fin

    std::cout<< std::endl<<"Nombre de coeurs instanciés: "<<Core<int>::getCount()<<std::endl;

    std::cout<<"---------------------------------------------------------"<< std::endl;
    std::cout<<"---------------------------------------------------------"<< std::endl;

    
    // Mapreduce doit fonctionner avec n'importe quel objet, ici, un vecteur de string

        std::vector<std::string> c = std::vector<std::string>( { "group1","group2","group3", "poo", "programmation" } );

        MapReduce<std::string> mrs(&c);

        //8 - Test d'affichage des coeurs disponibles (id s'incrémente et degradation 0)
        std::cout<<std::endl<< "####### test 8 #######"<<std::endl<<std::endl;
        MapReduce<std::string>::afficherCores(); 


        //9 - Affichage du coeur contenant tous les mots contenant "p" (voir ligne 34)
        std::cout<<std::endl<< "####### tests  9 #######"<<std::endl;

        std::cout<< mrs.map(countains)->map(countains)->getCore()<< std::endl;

        MapReduce<std::string>::afficherCores();

    //10 - Compter les mots contenant la lettre "p" (voir ligne 28 pour la fonction reduce et 34 pour map)  
        std::cout<<std::endl<< "####### tests  9 #######"<<std::endl;
    std::cout<< std::endl<<"Resultat mapReduce : " << mrs.map(countains)->chooseCore()->reduce(count, 0) << std::endl;

    MapReduce<std::string>::afficherCores(); 

    std::cout<< std::endl<<"Nombre de coeurs instanciés:  "<<Core<std::string>::getCount()<<std::endl;
    
    

    return 0;
}


