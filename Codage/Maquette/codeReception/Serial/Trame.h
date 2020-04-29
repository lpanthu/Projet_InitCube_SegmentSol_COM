#ifndef TRAME_H
#define TRAME_H

class Trame {
	public :
	void trame(char* trameBrute);
	void decortiquer();
	void decortiquerPayload();
	private :
	char trameBrute[TAILLE_MAX] ;
	char id [2];
	int nbreOctets;
	char checksum;
	TypeTrame typeTrame;
	boolean verrifierChecksum();
	
};

#endif /* TRAME_H */
