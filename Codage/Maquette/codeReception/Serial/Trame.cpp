/* BOULANGER GABRIELLE-ANNE
 * Trame.cpp
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
	
	nbreOctets = (int)trame[2]; 									/// NB d'octet dans la trame
	cout<<"\n nb octets trame : "<< nbOctetTrame <<endl;
	
	int f=0;
	for (int i=0 ; i<=1; i++){ 											/// ID
		id[i] = trame[i];
	}
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
	char donnees[tailleTabDonnees];
	cout<< "les Données brut "<< endl;
	cout <<"taille des données calculées : "<<tailleTabDonnees<<" Octets"<<endl;
	for (int h=0; h < tailleTabDonnees; h++){
		int pointeur = h+caseDebutDonnees ;
		donnees[h] = trame[pointeur];
		}
		cout <<"Les données récupérées sont les suivantes : \n"<<donnees<<endl;
	
}


void Trame::decortiquerPayload(){
	cout<<" \n Decortication du payload"<<endl;
	
}


boolean Trame::verrifierChecksum(){
	cout<<"\n Verrification du checksum"<<endl;
	for (int i=1; i<=0; i --){ 											///checksum
		checksum2[i];
	}
	checksums=checksum2[0]^checksum2[1];
	cout << checksums <<endl ;
	char checksumx = trame[0];									 		/// verrification de validité trame
	for (int i=1;i<strlen(trame);i++)
	{
		checksumx^=trame[i];
	}
	if (checksums == checksumx){
		cout << "trame valide" << endl;
	}
	else{cout <<"trame non valide"<<endl;}
	
}

void Trame::IdTypeTrame(){
	//-> Identification de type de trame 
	//la 1er indication pour la commande se situe à la 3e case // 9 possibilités de commande
	TypeTrame type;
	if (trame[g]=='D' && trame[g+1]=='E'){							//si les 2 1er lettres sont DE
		type = 4;f=6;}												///DEPLOY   6 //4
	if (trame[g]=='D' && trame[g+1]=='A'){							//si les 2 1er lettres sont DA
		type = 9; f=4; }											///DATE     4 //9
		
	if (trame[g]=='E'){												//si la 1er lettre est E
		type = 6; f=5; }											///EMPTY    5 //6
			
		
	if (trame[g]=='M' && trame[g]=='I'){ 							//si les 2 1er lettres sont MI
		 type = 1; f=7; }											///MISSION  7 //1
	if (trame[g]=='M' && trame[g+1]=='E' && trame[g+2]=='E'){ 		//si les 3 1er lettres sont MEE 
		 type = 8; f=7; }											///MEETING  7 //8
	if (trame[g]=='M' && trame[g+1]=='E' && trame[g+2]=='A'){		//si les 3 1er lettres sont MEA
		 type = 2; f=7; }											///MEASURE  7 //2
		
	if (trame[g]=='S' && trame[g+1]=='A'){							// si les 2 1er lettres sont SA
		 type = 7; f=4; }											///SAVE     4 //7
	if (trame[g]=='S' && trame[g+1]=='U'){	                   		// si les 2 1er lettres sont SU
		 type =  5; f=8; }											///SURVIVAL 8 //5
	if (trame[g]=='S' && trame[g+1]=='T' ){							// si les 2 1er lettres sont ST
		 type = 3; f=6; }											///STATUS   6 //3
	char CMD[f];
	if(f==0) {														//Si rien ne correspond 
		type = 10;													/// ERROR     //10
		cout <<"ERREUR :: trame de commmande introuvable \n"<<endl;
	}
	return type;
}
