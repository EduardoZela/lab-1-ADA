Las tres deben devolver la suma máxima. Verifiquen que coinciden entre sí sobre al menos 100 arreglos pequeños generados al azar, con enteros positivos y negativos. 

Se logro confirmar que los 3 algoritmos funcionan entre si, se hace la prueba en la función implementación,  :

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
