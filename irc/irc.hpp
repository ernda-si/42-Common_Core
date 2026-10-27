#ifndef IRC_HPP
# define IRC_HPP

# include <iostream>
# include <vector> // vectors
# include <sys/socket.h> // socket()
# include <sys/types.h> // socket()
# include <netinet/in.h> // sockaddr_in
# include <fcntl.h> // fcntl()
# include <unistd.h> //close()
# include <arpa/inet.h> // inet_ntoa()
# include <poll.h> // poll()
# include <csignal> // signal()

# define RED "\e[1;31m"
# define WHI "\e[0;37m"
# define GRE "\e[1;32m"
# define YEL "\e[1;33m"

class Client {
private:
    int _Fd;
    std::string _Ip;
public:
    Client(){};
    int getfd(){return _Fd;}

    void    setfd(int fd){_Fd = fd;}
    void    setip(std::string ip){_Ip = ip;}
};

class Server {
private:
    int _Port; // server port
    int _socketFd; // server socket file descriptor
    static bool _Signal;
    std::vector<Client> clients; // vector for clients
    std::vector<struct pollfd> fds; // vector of pollfd
public:
    Server(){_socketFd = -1;}

    void    serverInit();
    void    serverSocket(); // server socket creation
    void    accNewClient(); // accept new client
    void    receiveNewData(); // receive new data from a registered client

    static void signalHandler(int signum);

    void    closeFds();
    void    clearClients(int fd);
};

#endif
