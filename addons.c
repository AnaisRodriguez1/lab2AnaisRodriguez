#include <stdio.h>
#include <limits>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int displayMenu(){
    int option;
    do{
        cout <<"\n------------------------------\n";
        cout <<"1 => Ver grafo\n";
        cout <<"2 => Generar nuevos archivos\n";
        cout <<"3 => Salir\n";
        cout <<"------------------------------\n";
        option = validateOption();
        switch(option){
        case 1:
            logicGraph();
            break;
        case 2:
            generateFiles();
            break;
        case 3:
            cout << "Hasta luego!\n";
            return 0; 
    }
}while(option !=3);
return 0;
}

int validateOption(){
    string mode;
    int option;
        cout <<"\nSeleccione una opcion: ";
        cin >> mode;
    try{
        option = stoi(mode); //stoi intenta convertir lo que se le brinde como parámetro a un número
        if(option >= 1 && option <=4){ //Verifica que la conversión esté dentro del rango 1-4 
            return option;
        }else{
            cerr << "\nError: No es una option valida\n";
        }
    } catch (const invalid_argument& e) { //Si la conversión falla, muestra un mensaje de error
        cerr << "Error: La entrada no es un numero valido.\n" << endl;
    } catch (const out_of_range& e) {
        cerr << "Error: El numero ingresado esta fuera del rango valido.\n" << endl;
    }

    // Limpiar el estado de error y el buffer de entrada
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return -1;  // Valor no válido para indicar error
}