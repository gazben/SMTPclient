#include "Email.h"

#include <iostream>
#include <SFML/Network.hpp>

void Email::setSenderAddress(std::string val)
{
	senderAddress = val;
}

std::string Email::getSenderAddress() const
{
	return senderAddress;
}

void Email::setEmailSubject(std::string val)
{
	emailSubject = val;
}

std::string Email::getEmailSubject() const
{
	return emailSubject;
}

void Email::setEmailBody(std::string val)
{
	emailBody = val;
}

std::string Email::getEmailBody() const
{
	return emailBody;
}

Email::Email(std::string _emailSubject, std::string _emailBody, std::string _senderAddress, std::string _reciverAddress)
{
	emailSubject = _emailSubject;
	emailBody = _emailBody;
	senderAddress = _senderAddress;
	reciverAddress = _reciverAddress;
}

Email::Email()
{
}

void Email::toString()
{
	using namespace std;

	cout << "Email details" << endl;
	cout << "Subject:  " << emailSubject << endl;

	cout << "Body: " << emailBody << endl;

	cout << "Sender adress:" << senderAddress << endl;
	cout << "Reciver adress: " << reciverAddress << endl;
}

void Email::ReciverAddress(std::string val)
{
	reciverAddress = val;
}

std::string Email::ReciverAddress() const
{
	return reciverAddress;
}

sf::Packet& operator <<(sf::Packet& packet, Email& email)
{
	return packet << email.senderAddress.c_str() << email.reciverAddress.c_str() << email.emailSubject.c_str() << email.emailBody.c_str();
}

Email operator >> (sf::Packet& packet, Email mail){
	std::string emailSubject;
	std::string emailBody;
	std::string senderAddress;
	std::string reciverAddress;

	packet >> senderAddress >> reciverAddress >> emailSubject >> emailBody;

	return Email(emailSubject, emailBody, senderAddress, reciverAddress);
}