#include <iostream>
#include <regex>

#include "SMTPclient.h"
#include "Email.h"

SMTPclient::SMTPclient()
{
}

void SMTPclient::Init(){
	using namespace std;

	string senderAddr;
	string serverIP;

	regex ipRegex("^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$");

	cout << "Pls give me the SMTP servers IPv4 adress: ";
	cin >> serverIP;
	cout << endl;

	while (!regex_match(serverIP, ipRegex)){
		cout << "Not valid IP!" << endl;
	}
	cout << "Valid ip" << endl;


	regex emailRegex("^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}$");

	cout << "PLease give me the email adress youwant to use";
	cin >> senderAddr;
	cout << endl;

	while (!regex_match(senderAddr, emailRegex)){
		cout << "Not valid adress!" << endl;
	}
	cout << "Valid adress" << endl;
}

Email SMTPclient::ReadEmailData()
{
}

bool SMTPclient::SendEmail(Email mail){
	sf::Packet packet;

	packet << mail;

	sf::Socket::Status status = socket.send(packet);

	std::cout << "The sending ended with code: " << status << std::endl;
}

bool SMTPclient::SendAllEmail(){
	try
	{
		for (int i = 0; i < emails.size(); i++){
			SendEmail(emails[0]);
		}
	}
	catch (...)
	{
		std::cout << "Error happened while sending emails" << std::endl;
		return false;
	}

	return true;
}