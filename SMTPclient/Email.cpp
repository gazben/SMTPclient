#include "Email.h"

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

Email::Email(std::string _emailSubject, std::string _emailBody, std::string _senderAddress)
{
	emailSubject = _emailSubject;
	emailBody = _emailBody;
	senderAddress = _senderAddress;
}

sf::Packet& operator <<(sf::Packet& packet, const Email& email)
{
	return packet << email.getSenderAddress() << email.getEmailSubject() << email.getEmailBody();
}
