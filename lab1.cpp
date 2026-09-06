#include <iostream>
#include <cmath> //para el exponente
#include <cstdlib> // para el randon
#include <ctime>   // para tener un dato inicial para el random
#include <chrono> // con esto medire el tiempom

using namespace std;
using namespace std::chrono;

int cubo(int n, int L[]){ // en esta seccion hago resuelvo el problema pero con una solucion O(nº3)

    int mejor = L[0];  //aqui guardamos el mejor sub grupo
    
    for(int i = 0; i < n; i++){

        for(int j = i; j < n; j++){

            int subgrupos = 0; //esta variable almacenara todos los subgrupos posibles

            for(int k = i; k<=j; k++){

                subgrupos += L[k];
            }

            if(subgrupos > mejor) // si el sungrupo encontrado es mejor al q ya ten emos guardado cambiamos
                mejor = subgrupos;
        }
    }

    return mejor;
}

int cuadratico(int n, int L[]){ // aqui la solucion mejora a O(nº2)


    int mejor = L[0]; //esto guarda a el mejor sub grupo encontrado
    for(int i = 0; i < n; i++){

        int subgrupos = 0; // aca todos los subgrupos posibles

        for(int j = i ; j < n; j++){

            subgrupos += L[j];

            if(subgrupos > mejor)  // si encontro otro mejor reemplaza
                mejor = subgrupos;
        }
    }

    return mejor;
}

int lineal(int n, int L[]){ // aca la solucion pasa a ser lineal O(n) al parecer a esta solucion se le llama Kadane
    
    int global = L[0]; // este seria el global
    int aqui = L[0]; // los subgrupos
    
    for(int i = 1; i < n; i++){

        aqui = max(aqui + L[i], L[i]);
        global = max(aqui, global);
    }

    return global;
}

void implementacion(){

    srand(time(NULL));

    int L[20]; // el arreglo
    int lineal1;

    for(int i = 0; i < 100; i++){                           // aca creamos 100 areglos

        for(int j = 0; j < 20; j++){                        // aca hacemos q cada arreglo tenga 20 elementos
            L[j] = rand() % 101;                            // los elementos sean de 0 a 100
        }
        cout << "arreglo " << i << ": " << endl;            // imprime

        lineal1 = lineal(20,L);

        if ( ( lineal1 == cuadratico(20, L) ) && ( lineal1 == cubo(20, L) )){ //comparamos si son iguales
            cout<<" todos los algoritmos dan la misma respuesta: "<< lineal1 << endl << endl;
        }else{
            cout<< "error" << endl;
        }
    }
}

void Medicion(){// aca mediremos el tiempo q demora cada algoritmo con n: 1000, 2000, 4000 y 8000.
    
    for(int i = 0; i < 5; i++){ 

        int n = pow(2,i) * 1000;  // aca ponemos el tamñao de n
        int L[n]; //declaramos la lista 
        for(int j = 0; j < n; j++){   //creamos cada lista con n ele,mentos
            L[j] = rand() % 1001;  // los datos son de 0 a 1000
        }

        //-------------------------------- LINHEAL------------------------

        auto inicio = high_resolution_clock::now();                  //inicio del tiempo

        lineal(n, L);

        auto fin = high_resolution_clock::now();                     //final del tiempo
       
        auto tiempo = duration_cast<nanoseconds>(fin - inicio);      //tiempo total

        cout<< " Lineal : cuando n es " << n << " se demora " << tiempo.count() <<endl;

        /*

        //-------------------------------- CUADRATICO------------------------
        
        inicio = high_resolution_clock::now();                  //inicio del tiempo

        cuadratico(n, L);

        fin = high_resolution_clock::now();                     //final del tiempo

        tiempo = duration_cast<nanoseconds>(fin - inicio);      //tiempo total

        cout<< " cuadratico : cuando n es " << n << " se demora " << tiempo.count() <<endl;

        //-------------------------------- CUBO------------------------

        inicio = high_resolution_clock::now();                  //inicio del tiempo

        cubo(n, L);

        fin = high_resolution_clock::now();                     //final del tiempo

        tiempo = duration_cast<nanoseconds>(fin - inicio);      //tiempo total

        cout<< " cubo : cuando n es " << n << " se demora " << tiempo.count() <<endl<<endl;
        
        */
    }
} 



int main(){

    Medicion();

    return 0;
}