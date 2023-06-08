#include "siren.h"
#include <iostream>
using namespace std;

Siren::Siren(){
    state = 0;
}

void Siren::on(){
    state = 1;
    cout << "Siren is now ON" << endl;
}

void Siren::off(){
    state = 0;
    cout << "Siren is now OFF" << endl;
}

int Siren::getState(){
    return state;
}

string Siren::getHeader(){
    return "Siren";
}