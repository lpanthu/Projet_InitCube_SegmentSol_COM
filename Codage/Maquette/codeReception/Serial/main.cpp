/* BOULANGER GABRIELLE-ANNE
 * Code main / principal
 * fait le 05/05/2020
 */
/// Inclusions de toutes les classes ///
	#include "Trame.cpp"
	#include "Payload.cpp"
	#include "PayloadMesure.cpp"
	#include "PayloadMission.cpp"
	#include "PayloadStatut.cpp"
	#include "Trame.cpp"
/// Inclusions de Biliothèques ///
	#include <iostream>
	#include <string.h>
	#include <stdlib.h>
	#include <stdio.h>
///  Code Principal ///

using namespace std;

int main(){
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
}
	
	return 0;
}
