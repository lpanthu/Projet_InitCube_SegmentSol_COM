/* ligne de compilation :
 * Boulanger Gabrielle-Anne 
 * code principal
 */
/// Inclusions 
#include <iostream>
#include <string.h>
#include "Serial.h"

using namespace std;
/// Début du code principal
int main()
{
	int a =1; // permet un boucle 'infinie'
	string message;	//
	Serial maLiaisonSerie("/dev/ttyUSB0", 9600); // reçois un message avec un débit de 9600 sur le port ttyUSB0
	while (a==1) ///boucle infinie
	{
		message = maLiaisonSerie.readLine(); //stoque les informations recues dans message
		cout << "Message reçu : "<< message <<endl; // affiche les informations reçues
		
		/* Décortication de la trame */
		
		char mess[message.size()+1]; // création d'un tableau de carractère pour stoquer la reception
		strcpy(mess, message.c_str()); // Copie le string recue pour le placer dans la nouvelle chaîne de carractère
		
		/* Création tableau pour décortication */
		char id[2]; 
		char nbOctetTrame[1];
		char checksum[2];
		/* Décortication */
		for (int i=0 ; i<=1; i++){ /// ID
			id[i] = mess[i];
		}
		nbOctetTrame[0]=mess[2]; /// NB d'octet dans la trame
		for (int i=1; i<=0; i --){ ///checksum
			checksum[i];
		}
		/* Affichage des données séparés*/
		cout<<"id :" << id << endl;
		cout<<"nombre d'octet :" << nbOctetTrame <<endl;
	}
}
void creationTrame(){
	/* Création de trame */ //Commenge
	///Déclaration et inititialisation de la trame	
	char trame[100]={'\0'};///Très important pour marquer la fin de la chaine de caractères
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
	///on met à jour la taille de la trame dans la troisième case (= case 2)
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
	return o;
}

