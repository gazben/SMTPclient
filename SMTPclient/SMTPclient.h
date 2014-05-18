#ifndef SMTPclient_h__
#define SMTPclient_h__

#include "SFML/Network.hpp"

class Email;

class SMTPclient{

public:

	SMTPclient();
	void Init();

	Email ReadEmailData();

	bool SendEmail(Email);

	bool SendAllEmail();

private:

	sf::IpAddress serverIp;

	std::string senderAddress;

	std::vector<Email> emails;

	sf::TcpSocket socket;

};
#endif // SMTPclient_h__