#include "SMTPclient.h"


int main(){

	SMTPclient client;
	client.Init();

	while ( client.ReadEmailData() ){}

	client.SendAllEmail();

	return 0;

}