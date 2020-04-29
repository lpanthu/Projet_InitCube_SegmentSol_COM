/* Boulanger Gabrielle-Anne
 * classe qui ....
 * ligne de compilation :
 * fait le 29/04/2020
 */
#include "Payload.h"
#include <iostream>

using namespace std;

Payload::Payload(char* PayloadBrut){
	cout<<" \n Création de l'objet Payload apparttir du pointeur PayloadBrut"<<endl;
}
Payload::~Payload(){
	cout<<" \n Destruction de l'objet Payload"<<endl;
}
void Payload::extraireInformations(){
	cout <<" \n Extraction des informations de la Trame"<<endl;
}
