/* ligne de compilation :
 * Boulanger Gabrielle-Anne 
 * code principal
 */
/// Inclusions 
#include <iostream>
#include <string.h>

using namespace std;
/// Début du code principal
int main()
{
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
	//// Gabrielle
	while (a==1) ///boucle infinie
	{
		/* Décortication de la trame */
		char mess[trame.size()+1]; // création d'un tableau de carractère pour stoquer la reception
		
		/* Création tableau pour décortication */
		char id[2]; 
		char nbOctetTrame[1];
		char checksum[2];
		char status[6];
		
		/* Décortication */
		for (int i=0 ; i<=1; i++){ /// ID
			id[i] = mess[i];
		}
		nbOctetTrame[0]=mess[2]; /// NB d'octet dans la trame
		for (int i=1; i<=0; i --){ ///checksum
			checksum[i];
		}
		///CMD

// si tableau à partir de la case 1+1 +1 ==[S,T,A,T,U,S]
			int g=3;
			if (trame[g]=="D" & tram[g+1]=="E"){					//si les 2 1er lettres sont DE
				cout<<"Trame de deploiement"; char CMD[6]; }		///DEPLOY   6
			if (trame[g]=="D" & tram[g+1]=="E"){					//si les 2 1er lettres sont DA
				cout<<"Trame de date"; char CMD[4]; }				///DATE     4
				
			if (trame[g]=="E"){										//si la 1er lettre est E
				cout<<"Trame de empty"; char CMD[5]; }				///EMPTY    5
				
				
			if (trame[g]=="M" & trame[g]=="I"){ 					//si les 2 1er lettres sont MI
				cout<<"Trame de mission"; char CMD[7]; }			///MISSION  7
			if (trame[g]=="M" & tram[g+1]=="E" & tram[g+2]=="E"){ 	//si les 3 1er lettres sont MEE 
				cout<<"Trame de meeting"; char CMD[7]; }			///MEETING  7
			if (trame[g]=="M" & tram[g+1]=="E" & tram[g+2]=="A"){	// si les 3 1er lettres sont MEA
				cout<<"Trame de meeting"; char CMD[7]; }			///MEASURE  7
				
			if (trame[g]=="M" & tram[g+1]=="E" & tram[g+2]=="A"){	// si les 3 1er lettres sont MEA
				cout<<"Trame de meeting"; char CMD[4]; }			///SAVE     4
			if (trame[g]=="M" & tram[g+1]=="E" & tram[g+2]=="A"){	// si les 3 1er lettres sont MEA
				cout<<"Trame de meeting"; char CMD[8]; }			///SURVIVAL 8
			if (trame[g]=="M" & tram[g+1]=="E" & tram[g+2]=="A"){	// si les 3 1er lettres sont MEA
				cout<<"Trame de meeting"; char CMD[6]; }			///STATUS   6
			else {
				cout <<"ERREUR :: trame de commmande introuvable"
			}
		}
// 9 possibilités de commandes
// 
//alors c'est une trame de status 
		/// Données 
		
// si c'est une trame de status alors ...
// si c'est une trame de mission alors ...

		/* Affichage des données séparés*/
		cout<<"id :" << id << endl;
		cout<<"nombre d'octet :" << nbOctetTrame <<endl;
	}
}
