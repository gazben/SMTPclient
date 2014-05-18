#ifndef Email_h__
#define Email_h__

#include "SFML/Network.hpp"

class Email{

public:

	Email(std::string _emailSubject, std::string _emailBody, std::string _senderAddress);

	std::string getEmailBody() const;
	void setEmailBody(std::string val);

	std::string getEmailSubject() const;
	void setEmailSubject(std::string val);

	std::string getSenderAddress() const;
	void setSenderAddress(std::string val);

private:

	std::string emailSubject;

	std::string emailBody;

	std::string senderAddress;

};

sf::Packet& operator <<(sf::Packet& packet, const Email& email);

#endif // Email_h__