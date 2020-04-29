/* Boulanger Gabrielle-Anne
 * classe qui ....
 * ligne de compilation :
 * création de 29/04/2020
 */
 
#ifndef PAYLOADSTATUT_H
#define PAYLOADSTATUT_H
 
 class PayloadMesure : public payload{
	 public:
		PayloadMesure(char* payloadBrut);
	 private:
		int nombrePaquet;
		int numeroPaquet;
		TypeMesure typeMesure;
		
 };
#endif PAYLOADSTATUT_H
