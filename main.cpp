#include "values.h"
#include "files.c"
#include "addons.c"
#include "graphs.c"

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <ctime>
#include <cstdlib>


using namespace std;

int main() {
    cout <<"\nBienvenido al Sistema de Envio de Archivos\n";
    generateFiles();
    displayMenu();
    return 0;
}