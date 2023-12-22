#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

struct file1 {
    int id;
    string name;
    string type;
};

struct file2 {
    int idClient;
    int idServer;
    int velocity;
    int distance;
};

int generateFiles(){
    srand(time(NULL));
    ofstream archivo;
    ofstream archivo2;
    archivo2.open("conexiones.csv");
    archivo.open("servidores.csv");
    archivo<<"id,nombre,tipo"<<endl;
    archivo2<<"idCliente,idServidor,velocidad,distancia"<<endl;
    vector<string> cliente;
    vector<string> servidor;
    for (int i = 0; i < 300; i++) {
        int num = i;
        string nombre = "Servidor" + to_string(i);
        int random = rand()%5+1;
        string tipo;
        if(random == 5){
            tipo = "router";
            servidor.push_back(to_string(i));
            for(string client:cliente){
                int random2 = rand()%10+1;
                int velocidadrand = (rand()%3+1)*300;
                archivo2<<client<<","<<i<<","<<velocidadrand<<","<<random2<<endl;
            }
            cliente.clear();
        }else{
            tipo="cliente";
            cliente.push_back(to_string(i));
        }
        archivo << num << "," << nombre << "," << tipo << endl;
    }
    archivo.close();
    for(int i = 0; i< servidor.size(); i++){
        for(int j = i+1; j< servidor.size(); j++){
            if(i!=j){
                int moneda = rand()%4+1;
                if(moneda == 1){
                    int random = rand()%1000+1;
                    int velocidad = (rand()%3+1)*1000;
                    archivo2<<servidor[i]<<","<<servidor[j]<<","<<velocidad<<","<<random<<endl;
                }
            }
        }
        
    }
    cout << "\n*Nuevos Archivos generados*";
    archivo2.close();
    return 0;
}

void readFiles(){
    vector<file1> conexiones;
    vector<file2> servidores;

    ifstream conexionesStream("conexiones.csv");
    if(conexionesStream.is_open()){
        string header;
        getline(conexionesStream, header);

        string line;
        while (getline(conexionesStream, line)){
            istringstream ss(line);
            file1 lineFile1;
            ss >>  lineFile1.id >> lineFile1.name >> lineFile1.type;
            conexiones.push_back(lineFile1);
        }
        conexionesStream.close();
    }
    for (const auto& line : conexiones){
    cout << line.id << line.name << line.type<<endl;
    }
}