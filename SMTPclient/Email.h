#ifndef Email_h__
#define Email_h__

#include "SFML/Network.hpp"

class Email{
public:

	Email();

	Email(std::string _emailSubject, std::string _emailBody, std::string _senderAddress, std::string _reciverAddress);

	std::string getEmailBody() const;
	void setEmailBody(std::string val);

	std::string getEmailSubject() const;
	void setEmailSubject(std::string val);

	std::string getSenderAddress() const;
	void setSenderAddress(std::string val);

	std::string ReciverAddress() const;
	void ReciverAddress(std::string val);

	void toString();

	friend sf::Packet& operator <<(sf::Packet& packet, Email& email);

private:

	std::string emailSubject;

	std::string emailBody;
	std::string reciverAddress;

	std::string senderAddress;
};

sf::Packet& operator <<(sf::Packet& packet, Email& email);
Email operator >> (sf::Packet& packet, Email mail);
#endif // Email_h__