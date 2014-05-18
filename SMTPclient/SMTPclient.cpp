#include <iostream>
#include <regex>

#include "SMTPclient.h"
#include "Email.h"

SMTPclient::SMTPclient()
{
}

void SMTPclient::Init(){
	using namespace std;

	string _senderAddr;
	string _serverIP;

	regex ipRegex("^(?:[0-9]{1,3}\.){3}[0-9]{1,3}$");

	cout << "Pls give me the SMTP servers IPv4 adress: ";
	cin >> _serverIP;
	cout << endl;

	while (!regex_match(_serverIP, ipRegex)){
		cout << "Not valid IP!" << endl;
	}
	cout << "Valid ip" << endl;
	serverIp = _serverIP;

	regex emailRegex("^[A-Z0-9._%+-]+@[A-Z0-9.-]+\.[A-Z]{2,4}$");

	cout << "PLease give me the email adress youwant to use";
	cin >> _senderAddr;
	cout << endl;

	while (!regex_match(_senderAddr, emailRegex)){
		cout << "Not valid adress!" << endl;
	}

	cout << "Valid adress" << endl;
	senderAddress = _senderAddr;

	socket.connect(serverIp, 25);
}

bool SMTPclient::ReadEmailData(){
	using namespace std;

	string emailSubject;
	string emailBody;

	cout << "Enter the subject of the mail: " << endl;
	cin >> emailSubject;

	cout << "Enter the body of the email: " << endl;
	cin >> emailBody;

	Email tempMail(emailSubject, emailBody, senderAddress);

	cout << "Do you want to send the e-mail now? ";
	string answer;
	cin >> answer;
	cout << endl;
	if (answer == "yes" || answer == "Yes" || answer == "y"){
		SendEmail(tempMail);
	}
else
	emails.push_back(tempMail);

	cout << "Do you want to send another e-mail now? ";
	cin >> answer;
	cout << endl;
	if (answer == "yes" || answer == "Yes" || answer == "y"){
		return true;
	}
	else
		return false;
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