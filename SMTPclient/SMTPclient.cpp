#include "SMTPclient.h"
#include "Email.h"

SMTPclient::SMTPclient(std::string _senderAddr, std::string _serverIP)
{
	senderAddress = _senderAddr;
	serverIp = _serverIP;
}

Email SMTPclient::ReadEmailData()
{

}

bool SMTPclient::SendEmail(Email mail)
{

}

bool SMTPclient::SendAllEmail()
{

}
