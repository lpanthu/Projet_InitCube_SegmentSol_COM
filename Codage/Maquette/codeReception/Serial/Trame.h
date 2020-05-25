/* BOULANGER GABRIELLE-ANNE
 * Trame.h
 * ligne de compilation :
 * fait le 29/04/2020
 */
 
#ifndef TRAME_H
#define TRAME_H

class Trame {
	public :
		Trame(char* trameBrute);
		void decortiquer(); 			//initialisation de la fonction de décortiquation de trame
		void decortiquerPayload(); 		//initialisation d'une fonction poour décortiquer le payload
		int IdTypeTrame();
	private :
		char trameBrute[TAILLE_MAX] ; 	//initialisation d'un tableau contenant la trame reçue
		char id [2];					//initialisation de la varriable contenant l'id transmis par la trame
		int nbreOctets;					//initialisation de la varriable contenant le nombre d'octet dans la trame
		char checksum;					//initialisation de la varriable contenant le checksum
		TypeTrame typeTrame;			//initialisation de la varriable stoquant le type de trame reçue
		boolean verrifierChecksum();	//initialisation d'une fonction verrifiant la validité d'une trame
		payload Payload;				//initialisation d'un objet probenant d'une classe abstraite
};

#endif /* TRAME_H */
