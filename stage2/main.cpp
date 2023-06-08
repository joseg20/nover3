#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
#include "window.h"
#include "central.h"
#include "siren.h"

using namespace std; //std es un namespace, es un conjunto de funciones que se pueden usar en el programa 

int main(int argc, char * argv[]) {
    ifstream fin;
    int nDoors, nWindows, junk;
    Central central;
    vector<Door *> doors;
    vector<Window *> windows;
    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }
    fin.open(argv[1]);
    if (fin.fail()){
        cout << "Could not read file" << endl;
        return -2;
    }
    cout << "Argument:" << argv[1] << endl;

    Siren siren;
    central.setSiren(&siren);
    central.arm();

    fin >> nDoors >> nWindows;
    
    for( int i=0; i<nDoors; i++) {
        int zone;
        fin >>junk >> junk >> junk >> zone;
        //imprimir por consola la zona
        cout << "Zone: " << zone << endl;

        // si es zona = 0 ocupamos el metodo addNewSensorZone0
        doors.push_back(new Door(zone)); // agregamos una puerta al vector de puertas
        if (zone == 0) {
            central.addNewSensorZone0(doors.back()->getSensor());
        } else {
            central.addNewSensorZone1(doors.back()->getSensor());
        }
    }

    for( int i=0; i<nWindows; i++) {
        int zone;
        fin >> junk >> junk >> junk >> zone;
        //imprimir por consola la zona
        cout << "Zone: " << zone << endl;
        windows.push_back(new Window(zone)); // agregamos una ventana al vector de ventanas
        central.addNewSensorZone1(windows.back()->getSensor()); // agregamos una ventana al vector de ventanas de la central
    }

    for (uint i=0; i<doors.size(); i++) { //uint : unsigned int
        doors[i]->changeState();
        doors[i]->changeState();
    }

    for (uint i=0; i<windows.size(); i++) { //uint : unsigned int
        windows[i]->changeState();
        windows[i]->changeState();
    }
    central.checkZone();
    doors[0]->changeState(); // abrimos la puerta principal
    central.checkZone();
}


/*
#include <iostream>
#include <fstream>
#include <vector>
#include "door.h"
#include "window.h"
#include "central.h"

using namespace std;

int main(int argc, char * argv[]) {
    ifstream fin;
    int nDoors, nWindows;
    vector<Door *> doors;
    vector<Window *> windows;
    Central central;

    if (argc != 2) {
        cout << "Usage: "<<argv[0]<<" <configuration_file>" << endl;
        return -1;
    }
    fin.open(argv[1]);
    if (fin.fail()){
        cout << "Could not read file" << endl;
        return -2;
    }
    fin >> nDoors >> nWindows;
    for( int i=0; i<nDoors; i++) {
        int zone;
        fin >> zone;
        doors.push_back(new Door(zone));
        central.addDoor(doors.back());
    }
    for( int i=0; i<nWindows; i++) {
        int zone;
        fin >> zone;
        windows.push_back(new Window(zone));
        central.addWindow(windows.back());
    }
    for (uint i=0; i<doors.size(); i++) {
        doors[i]->changeState();
        doors[i]->changeState();
    }
    for (uint i=0; i<windows.size(); i++) {
        windows[i]->changeState();
        windows[i]->changeState();
    }
    central.checkZones();

    doors[0]->changeState(); // abrimos la puerta principal
    central.checkZones();
}

*/

/*
Tu archivo de configuración (config.txt) es bastante simple, solo tiene dos números enteros. El primer número representa la cantidad de puertas y el segundo número la cantidad de ventanas.

El código que has proporcionado solo está manejando las puertas. Está leyendo el archivo de configuración, tomando el primer número como la cantidad de puertas, y luego creando esa cantidad de puertas. No está utilizando el segundo número, que es la cantidad de ventanas.

Para satisfacer los requisitos que mencionaste, necesitarás agregar una clase Window similar a tu clase Door. Luego, en tu programa principal, necesitas crear y manejar una lista de ventanas, similar a cómo estás manejando las puertas.

Además, necesitas crear una clase Central, que verificará el estado de todas las puertas y ventanas. Si todas las puertas y ventanas están cerradas, debería imprimir "Zonas Cerradas". Si alguna puerta o ventana está abierta, debería imprimir "Alguna zona está abierta".*/