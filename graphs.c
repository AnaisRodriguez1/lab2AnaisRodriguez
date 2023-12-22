#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <climits>
#include <cmath>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// Definición de la clase Nodo
class Nodo {
public:
    int valor;
    int velocidad;

    Nodo(int v, int vel) : valor(v), velocidad(vel) {}
};

// Definición de la clase Arista
class Arista {
public:
    int valor;
    Nodo* inicio;
    Nodo* fin;
    int tiempo;

    Arista(int val, Nodo* i, Nodo* f, int t) : valor(val), inicio(i), fin(f), tiempo(t) {}
};

// Función para aplicar Bellman-Ford y calcular el tiempo total de conexión
int bellmanFord(Nodo* origen, Nodo* destino, vector<Arista*>& aristas) {
    const int numNodos = aristas.size() + 2;  // Agregamos 2 nodos adicionales para representar el nodo inicial y el nodo final
    vector<int> distancias(numNodos, INT_MAX);

    distancias[origen->valor - 1] = 0;  // Nodo de inicio

    // Aplicar el algoritmo de Bellman-Ford
    for (int i = 0; i < numNodos - 1; ++i) {
        for (Arista* arista : aristas) {
            if (distancias[arista->inicio->valor - 1] != INT_MAX) {
                int nuevaDistancia = distancias[arista->inicio->valor - 1] + arista->tiempo;
                if (nuevaDistancia < distancias[arista->fin->valor - 1]) {
                    distancias[arista->fin->valor - 1] = nuevaDistancia;
                }
            }
        }
    }

    // Verificar ciclos negativos
    for (Arista* arista : aristas) {
        if (distancias[arista->inicio->valor - 1] != INT_MAX) {
            int nuevaDistancia = distancias[arista->inicio->valor - 1] + arista->tiempo;
            if (nuevaDistancia < distancias[arista->fin->valor - 1]) {
                cout << "Se detectó un ciclo negativo. No se puede calcular el tiempo correctamente." << endl;
                return -1;
            }
        }
    }

    // Devolver el tiempo de conexión desde el nodo origen al nodo destino
    return distancias[destino->valor - 1];
}

// Función para cargar nodos y aristas desde un archivo CSV
void cargarDesdeCSV(const string& archivo, vector<Nodo*>& nodos, vector<Arista*>& aristas) {
    ifstream archivoCSV(archivo);

    if (!archivoCSV.is_open()) {
        cerr << "Error al abrir el archivo " << archivo << endl;
        exit(EXIT_FAILURE);
    }

    // Leer la cabecera (descartarla)
    string cabecera;
    getline(archivoCSV, cabecera);

    // Mapeo para asociar valores a instancias de nodos
    unordered_map<int, Nodo*> mapaNodos;

    // Leer cada línea del archivo
    while (archivoCSV.good()) {
        string linea;
        getline(archivoCSV, linea);

        if (linea.empty()) {
            break;
        }

        stringstream ss(linea);
        string nodoStr, aristaStr, velocidadStr, tiempoStr;

        getline(ss, nodoStr, ',');
        getline(ss, aristaStr, ',');
        getline(ss, velocidadStr, ',');
        getline(ss, tiempoStr, ',');

        int nodo = stoi(nodoStr);
        int arista = stoi(aristaStr);
        int velocidad = stoi(velocidadStr);
        int tiempo = stoi(tiempoStr);

        // Crear nodos si aún no existen
        if (!mapaNodos.count(nodo)) {
            mapaNodos[nodo] = new Nodo(nodo, velocidad);
        }

        if (!mapaNodos.count(arista)) {
            mapaNodos[arista] = new Nodo(arista, 0);  // Nodo sin velocidad
        }

        // Crear arista
        Arista* nuevaArista = new Arista(arista, mapaNodos[nodo], mapaNodos[arista], tiempo);
        aristas.push_back(nuevaArista);
    }

    // Copiar nodos desde el mapa al vector
    nodos.reserve(mapaNodos.size());
    for (auto& kv : mapaNodos) {
        nodos.push_back(kv.second);
    }

    archivoCSV.close();
}

int logicGraph() {
    vector<Nodo*> nodos;
    vector<Arista*> aristas;

    // Cargar nodos y aristas desde el archivo CSV
    cargarDesdeCSV("conexiones.csv", nodos, aristas);

    // Mostrar el grafo cargado con información detallada
    cout << "Grafo:" << endl;
    for (Arista* arista : aristas) {
        cout << "Nodo " << arista->inicio->valor << " -> Nodo " << arista->fin->valor << " (Velocidad: " << arista->inicio->velocidad << ", Tiempo: " << arista->tiempo << ")" << endl;
    }

    // Solicitar al usuario ingresar un valor manual
    int valorManual;
    cout << "\nIngrese un valor manual: ";
    cin >> valorManual;

    // Calcular y mostrar el tiempo total de conexión entre cada par de nodos conectados a una misma arista
    cout << "\nTiempos totales de conexion entre nodos conectados a la misma arista:" << endl;

    // Conjunto para rastrear las aristas ya procesadas
    unordered_set<int> aristasProcesadas;

    for (size_t i = 0; i < aristas.size(); ++i) {
        for (size_t j = i + 1; j < aristas.size(); ++j) {
            Arista* arista1 = aristas[i];
            Arista* arista2 = aristas[j];

            // Comprobar si ambas aristas comparten el mismo nodo
            if (arista1->inicio == arista2->inicio || arista1->inicio == arista2->fin ||
                arista1->fin == arista2->inicio || arista1->fin == arista2->fin) {

                // Calcular y mostrar el tiempo total
                int tiempoTotal1 = bellmanFord(arista1->inicio, arista1->fin, aristas);
                int tiempoTotal2 = bellmanFord(arista2->inicio, arista2->fin, aristas);

                if (tiempoTotal1 != -1 && tiempoTotal2 != -1) {
                    int tiempoManual1 = round((valorManual / static_cast<double>(arista1->inicio->velocidad)) * tiempoTotal1);
                    int tiempoManual2 = round((valorManual / static_cast<double>(arista2->inicio->velocidad)) * tiempoTotal2);
                    cout << "--------------------------------------------------------" << endl;
                    cout << "Tiempo total del Nodo " << arista1->inicio->valor << " a la Arista " << arista1->fin->valor
                         << " y del Nodo " << arista2->inicio->valor << " a la Arista " << arista2->fin->valor
                         << ": " << tiempoManual1 + tiempoManual2 << " segundo(s)." << endl;

                    // Mostrar el tiempo total para la arista actual
                    int tiempoTotalArista = bellmanFord(arista1->inicio, arista1->fin, aristas);
                    if (tiempoTotalArista != -1) {
                        int tiempoManualArista = round((valorManual / static_cast<double>(arista1->inicio->velocidad)) * tiempoTotalArista);
                        cout << "Tiempo total de " << arista1->inicio->valor << " a " << arista1->fin->valor
                             << ": " << tiempoManualArista << " unidades de tiempo." << endl;
                    }

                    // Mostrar el tiempo total para el otro nodo de la arista
                    tiempoTotalArista = bellmanFord(arista2->inicio, arista2->fin, aristas);
                    if (tiempoTotalArista != -1) {
                        int tiempoManualArista = round((valorManual / static_cast<double>(arista2->inicio->velocidad)) * tiempoTotalArista);
                        cout << "Tiempo total de " << arista2->inicio->valor << " a " << arista2->fin->valor
                             << ": " << tiempoManualArista << " unidades de tiempo." << endl;
                    }
                }
            }
        }
    }

    // Liberar memoria
    for (Nodo* nodo : nodos) {
        delete nodo;
    }

    for (Arista* arista : aristas) {
        delete arista;
    }

    return 0;
}
