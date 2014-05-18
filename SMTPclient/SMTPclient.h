#ifndef SMTPclient_h__
#define SMTPclient_h__

#include "SFML/Network.hpp"

class Email;

class SMTPclient{

public:

	SMTPclient(std::string _senderAddr , std::string _serverIP);

	Email ReadEmailData();

	bool SendEmail(Email);

	bool SendAllEmail();

private:

	sf::IpAddress serverIp;

	std::string senderAddress;

	std::vector<Email> emails;

};
#endif // SMTPclient_h__