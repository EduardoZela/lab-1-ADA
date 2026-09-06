Midan el tiempo de las tres duplicando n: 1000, 2000, 4000, 8000  asta donde alcance. Construyan una tabla con los tiempos y con la razón entre cada tiempo y el anterior. Indiquen qué orden de crecimiento deducen de esas razones. 

Se midio el tiempo en la segunda funcion "medicion" :

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
            
        }
    } 


los resultados de esta funcion son: 


         Lineal : cuando n es 1000 se demora 0 ns
         cuadratico : cuando n es 1000 se demora 0 ns
         cubo : cuando n es 1000 se demora 369738000 ns 
        
         Lineal : cuando n es 2000 se demora 0 ns
         cuadratico : cuando n es 2000 se demora 4029000 ns
         cubo : cuando n es 2000 se demora 2852784000 ns
        
         Lineal : cuando n es 4000 se demora 0 ns
         cuadratico : cuando n es 4000 se demora 16768000 ns
         cubo : cuando n es 4000 se demora 22742596000 ns
        
         Lineal : cuando n es 8000 se demora 0 ns
         cuadratico : cuando n es 8000 se demora 71614000 ns
         cubo : cuando n es 8000 se demora 180865876000 ns

con toda esta informacion se hizo la siguiente tabla:

|    n | Lineal (ns) | Razón | Cuadrático (ns) |    Razón |  Cúbico (ns) |    Razón |
| ---: | ----------: | ----: | --------------: | -------: | -----------: | -------: |
| 1000 |           0 |     — |               0 |        — |    369738000 |        — |
| 2000 |           0 |     — |         4029000 |        — |   2852784000 | **7.72** |
| 4000 |           0 |     — |        16768000 | **4.16** |  22742596000 | **7.97** |
| 8000 |           0 |     — |        71614000 | **4.27** | 180865876000 | **7.95** |

Viendo las razones de crecimiento podemos deducir que en el algoritmo cuadrático al duplicar n este aumenta si tiempo aproximadamente en 4 y con el algoritmo cubico el tiempo aumenta en 8.
