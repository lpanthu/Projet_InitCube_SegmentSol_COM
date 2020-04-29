/* BOULANGER GABRIELLE-ANNE
 * ligne de compilation :
 * fait le 29/04/2020
 */

#include "Trame.h"
#include <iostream>

#define	TAILLE_MAX		104
using namespace std;

Trame::Trame(char* trameBrute){
	cout<<" \n Création de l'objet trame"<<endl;
}
Trame::~Trame(){
	cout<<" \n Destruction de l'objet trame"<<endl;
}
void Trame::decortiquer(){
	cout <<" \n Decortication de la Trame"<<endl;
}
void Trame::decortiquerPayload(){
	cout<<" \n Decortication du payload"<<endl;
	
}
boolean Trame::verrifierChecksum(){
	cout<<"\n Verrification du checksum"<<endl;
}
