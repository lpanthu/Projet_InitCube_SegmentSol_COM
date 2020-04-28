/* ligne de compilation :
 * Boulanger Gabrielle-Anne 
 * code principal
 */
/// Inclusions 
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <boost/asio.hpp>

using namespace std;
/// Début du code principal
int main()
{
	/* Création de trame */ 											//Commenge
	
	//Déclaration et inititialisation de la trame	
	char trame[100]={'\0'};												///Très important pour marquer la fin de la chaine de caractères
	///Construction de la trame
	///identifiant	
	trame [0]='~';
	trame [1]='1';
	///taille provisoire de la trame
	trame[2]=strlen(trame);
	///ajout du type de trame
    strcat(trame,"STATUS");
	///nombre de paquets
	trame[strlen(trame)]=1;
	///numéro du paquet
	trame[strlen(trame)]=1;
	///données utiles
	strcat(trame,"-BORD-SMo1570-S%25-RMo1249-R%35-DT2020/03/28 12:19:25 -T25.9 ");
	///maintenant que la trame est complète (hors checksum)
	///on met à jour la taille de la trame dans la troisième case (=  case 2)
	trame[2]=strlen(trame);
	///calcul du checksum (OU exclusif entre chaque octet de la trame)
	char checksum = trame[0];
	for (int i=1;i<strlen(trame);i++)
	{
		checksum^=trame[i];
	}
	///ajout du checksum à la fin de la trame
	trame[strlen(trame)]=checksum;

	///affichage de la trame et de sa taille
	cout << "Trame : " << trame << endl;	
	cout << "Taille de la trame checksum compris : "<<strlen(trame)<<endl;
	cout << "Extraction du checksum : "<< trame[trame[2]]<< endl;
	///initialisation des variables
																		//// Gabrielle
	cout <<endl;
	cout <<endl;
	cout <<"Code en cours " << endl ;
	/* Décortication de la trame */
	//char mess[]; // création d'un tableau de carractère pour stoquer la reception

	/* Création tableau pour décortication */
	char id[2]; 
	char nbOctetTrame[1];
	char checksum2[2];
	char status[6];
	
	/* Décortication */
	for (int i=0 ; i<=1; i++){ 											/// ID
		id[i] = trame[i];
	}
	nbOctetTrame[0]=trame[2]; 											/// NB d'octet dans la trame
	for (int i=1; i<=0; i --){ 											///checksum
		checksum2[i];
	}
																		///CMD
		int f=0;
		int g=3;	// la 1er indication pour la commande se situe à la 3e case // 9 possibilités de commandes
		//cout <<"Ici nous reçevons la trame suivante \n"<< trame[g]<<endl;
		if (trame[g]=='D' && trame[g+1]=='E'){							//si les 2 1er lettres sont DE
			cout<<"Trame de deploiement \n"; f=6; /*char CMD[6]*/; }	///DEPLOY   6
		if (trame[g]=='D' && trame[g+1]=='A'){							//si les 2 1er lettres sont DA
			cout<<"Trame de date \n"; f=4; /*char CMD[4];*/ }			///DATE     4
			
		if (trame[g]=='E'){												//si la 1er lettre est E
			cout<<"Trame de empty \n"; f=5; /*char CMD[5];*/ }			///EMPTY    5
			
			
		if (trame[g]=='M' && trame[g]=='I'){ 							//si les 2 1er lettres sont MI
			cout<<"Trame de mission \n"; f=7; /*char CMD[7];*/ }			///MISSION  7
		if (trame[g]=='M' && trame[g+1]=='E' && trame[g+2]=='E'){ 		//si les 3 1er lettres sont MEE 
			cout<<"Trame de meeting \n"; f=7; /*char CMD[7];*/ }		///MEETING  7
		if (trame[g]=='M' && trame[g+1]=='E' && trame[g+2]=='A'){		//si les 3 1er lettres sont MEA
			cout<<"Trame de meeting \n"; f=7; /*char CMD[7];*/ }		///MEASURE  7
			
		if (trame[g]=='S' && trame[g+1]=='A'){							// si les 2 1er lettres sont SA
			cout<<"Trame de sauvegarde \n"; f=4; /*char CMD[4];*/ }		///SAVE     4
		if (trame[g]=='S' && trame[g+1]=='U'){	                   		// si les 2 1er lettres sont SU
			cout<<"Trame de SURVIVAL \n"; f=8; /*char CMD[8];*/ }		///SURVIVAL 8
		if (trame[g]=='S' && trame[g+1]=='T' ){							// si les 2 1er lettres sont ST
			cout<<"Trame de status \n"; f=6; /*char CMD[6];*/ }			///STATUS   6
		char CMD[f];
		if(f==0) { 
			cout <<"ERREUR :: trame de commmande introuvable \n"; 
		}

		/// Données 
		int caseDebutDonnees = 5+f;
		int tailleTabDonnees = strlen(trame)-caseDebutDonnees-2;
		
		cout <<"taille des données calculées : "<<tailleTabDonnees<<" Octets"<<endl;
		for (int h=0; h < tailleTabDonnees; h++){
			int pointeur = h+caseDebutDonnees ;
		}
		/*
		int tailleTabDonnees = trame.size()+1 - checksum1.size()+1 - f - id.size()+1;
		for (int h=f+ ; h <= trame.size()-1; h++){						//Stoquage des données dans un nouveau tableau
			trame
		}*/
		
// si c'est une trame de status alors ...
// si c'est une trame de mission alors ...

		/* Affichage des données séparés*/
		
		/*int iid1 = (int)id[0];										Premier test de convertion de l'id en int
		int iid2 = (int)id[1];
		cout<<"id :" << iid1 << iid2 << endl;*/
		int intId[2];													///Test 2 de conversion de l'id en int ; résultats plus complets
		intId[0]=(int)id[0];
		intId[1]= (int) id[1];
		cout<<endl;
		cout <<"Id : "<< intId<<"\n et id : "<< intId[0] << intId[1] << endl;
		int inbOctetTrame = (int)nbOctetTrame[0];
		cout<<"nombre d'octet :" << inbOctetTrame <<endl;
	}
