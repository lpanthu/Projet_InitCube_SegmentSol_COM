#include <iostream>
#include "Serial.h"

using namespace std;

int main()
{
	int a =1;
	string message;	
	Serial maLiaisonSerie("/dev/ttyUSB0", 9600);
	while (a==1)
	{
		message = maLiaisonSerie.readLine();
		cout << "Message reçu : "<< message <<endl;
		char mess[message.size()+1];
		strcpy(mess, message.c_str());
		char id[2];
		char nbOctetTrame[1];
		nbOctetTrame[0]=mess[2];
		for (int i=0 ; i<=1; i++){
			id[i] = mess[i];
		}	
		cout<<"id :" << id << endl;
		cout<<"nombre d'octet :" << nbOctetTrame <<endl;
	}
}
