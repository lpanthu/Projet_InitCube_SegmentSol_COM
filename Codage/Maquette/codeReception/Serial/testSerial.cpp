#include <iostream>
#include "Serial.h"

using namespace std;

int main()
{
	string message;	
	Serial maLiaisonSerie("/dev/ttyUSB0", 19200);
	while (1)
	{
		message = maLiaisonSerie.readLine();
		cout << "Message reçu : "<< message <<endl;
	}
	return 0;
}
