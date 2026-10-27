#include "irc.hpp"

void    Server::clearClients(int fd)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < fds.size())
    {
        if (fds[i].fd == fd)
        {
            fds.erase(fds.begin() + 1);
            break;
        }
        i++;
    }
    while (j < clients.size())
    {
        if (clients[j].getfd() == fd)
        {
            clients.erase(clients.begin() + j);
            break;
        }
        j++;
    }
}

bool    Server::_Signal = false;
void    Server::signalHandler(int signum)
{
    (void)signum;
    std::cout << std::endl << "Signal received" << std::endl;
    Server::_Signal = true;
}

void    Server::closeFds()
{
    int i;
    
    i = 0;
    while (i < clients.size())
    {
        std::cout << RED << "Client <" << clients[i].getfd() << "> Disconnected";
        close(clients[i].getfd());
        i++;
    }
    if (_socketFd != -1)
    {
        std::cout << RED << "Server <" << _socketFd << "> Disconnected" << WHI;
        close(_socketFd);
    }
}

void    Server::serverSocket()
{
    struct  sockaddr_in add;
    struct  pollfd      newPoll;

    add.sin_family = AF_INET; // set the address family to ipv4
    add.sin_port = htons(this->_Port); // convert the port to network byte order (big endian)
    add.sin_addr.s_addr = INADDR_ANY; // set the address to any local machine address

    _socketFd = socket(AF_INET, SOCK_STREAM, 0); // create the server socket
    
}