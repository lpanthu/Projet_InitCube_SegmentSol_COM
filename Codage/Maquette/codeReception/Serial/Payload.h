/* Boulanger Gabrielle-Anne
 * classe qui ....
 * ligne de compilation :
 * fait le 29/04/2020
 */


#ifndef PAYLOAD_H
#define PAYLOAD_H

public abstract class Payload {
	public :
		void extraireInformations();									//initialisation de la fonction d'extraxtion d'informations
		Payload(char* payloadBrut); 									//initialisation du constructeur
	private :
		char payloadBrut[TAILLE_PAYLOAD]; 							    //initialisation du tableau
		void numeroPaquet;												///initialisation d'une varriable ..... 
};

#endif /* PAYLOAD_H */
