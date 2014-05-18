#ifndef SMTPclient_h__
#define SMTPclient_h__

#include "SFML/Network.hpp"
#include "Email.h"

class Email;

class SMTPclient{

public:

	SMTPclient();
	void Init();

	bool ReadEmailData();

	void SendEmail(Email);

	bool SendAllEmail();

private:

	sf::IpAddress serverIp;

	std::string senderAddress;

	std::vector<Email> emails;

	sf::TcpSocket socket;

};
#endif // SMTPclient_h__