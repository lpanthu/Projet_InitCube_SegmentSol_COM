/* BOULANGER GABRIELLE-ANNE
 * ligne de compilation :
 * fait le 29/04/2020
 */

#include "Trame.h"
#include "TypeTrame.h"
#include <iostream>

#define	TAILLE_MAX		104
#define DEBUT			3

using namespace std;

Trame::Trame(char* trameBrute){
	cout<<" \n Création de l'objet trame"<<endl;
	}
	
Trame::~Trame(){
	cout<<" \n Destruction de l'objet trame"<<endl;
}
void Trame::decortiquer(){
	cout <<" \n Decortication de la Trame"<<endl;
	for (int i=0 ; i<=1; i++){ 											/// ID
		id[i] = trame[i];
	}
	int nbOctetTrame = (int)trame[2]; 									/// NB d'octet dans la trame
	cout<<"\n nb octets trame : "<< nbOctetTrame <<endl;
	for (int i=1; i<=0; i --){ 											///checksum
		checksum2[i];
	}
	int taille=0;
	this->IdTypeTrame(DEBUT; Taille);

																		/// Données 
	int caseDebutDonnees = g+f;
	int tailleTabDonnees = strlen(trame)-caseDebutDonnees-2;
	char Donnees[tailleTabDonnees];
	cout<< "les Données brut "<< endl;
	cout <<"taille des données calculées : "<<tailleTabDonnees<<" Octets"<<endl;
	for (int h=0; h < tailleTabDonnees; h++){
		int pointeur = h+caseDebutDonnees ;
		Donnees[h] = trame[pointeur];
		}
		cout <<"Les données récupérées sont les suivantes : \n"<<Donnees<<endl;
	
}
void Trame::decortiquerPayload(){
	cout<<" \n Decortication du payload"<<endl;
	
}
boolean Trame::verrifierChecksum(){
	cout<<"\n Verrification du checksum"<<endl;
}

void Trame::IdTypeTrame(int g; int f){
	//-> Identification de type de trame 
	//la 1er indication pour la commande se situe à la 3e case // 9 possibilités de commandes
	if (trame[g]=='D' && trame[g+1]=='E'){							//si les 2 1er lettres sont DE
		cout<<"Trame de deploiement \n"<<endl; f=6; }				///DEPLOY   6
	if (trame[g]=='D' && trame[g+1]=='A'){							//si les 2 1er lettres sont DA
		cout<<"Trame de date \n"<<endl; f=4; }						///DATE     4
		
	if (trame[g]=='E'){												//si la 1er lettre est E
		cout<<"Trame de empty \n"<<endl; f=5; }						///EMPTY    5
			
		
	if (trame[g]=='M' && trame[g]=='I'){ 							//si les 2 1er lettres sont MI
		cout<<"Trame de mission \n"<<endl; f=7; }					///MISSION  7
	if (trame[g]=='M' && trame[g+1]=='E' && trame[g+2]=='E'){ 		//si les 3 1er lettres sont MEE 
		cout<<"Trame de meeting \n"<<endl; f=7; }					///MEETING  7
	if (trame[g]=='M' && trame[g+1]=='E' && trame[g+2]=='A'){		//si les 3 1er lettres sont MEA
		cout<<"Trame de meeting \n"<<endl; f=7; }					///MEASURE  7
		
	if (trame[g]=='S' && trame[g+1]=='A'){							// si les 2 1er lettres sont SA
		cout<<"Trame de sauvegarde \n"<<endl; f=4; }				///SAVE     4
	if (trame[g]=='S' && trame[g+1]=='U'){	                   		// si les 2 1er lettres sont SU
		cout<<"Trame de SURVIVAL \n"<<endl; f=8; }					///SURVIVAL 8
	if (trame[g]=='S' && trame[g+1]=='T' ){							// si les 2 1er lettres sont ST
		cout<<"Trame de status \n"<<endl; f=6; }					///STATUS   6
	char CMD[f];
	if(f==0) {
		cout <<"ERREUR :: trame de commmande introuvable \n"<<endl;
	}
}
