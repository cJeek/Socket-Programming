// Implementation of the ServerSocket class

#include "server_socket.h"
#include "socket_exception.h"

#define THREAD_NUM 20
using namespace std;

ServerSocket::ServerSocket(int port)
{
	if (!Socket::create())
    {
		throw SocketException ("Could not create server socket.");
    }

	if (!Socket::bind (port))
    {
      	throw SocketException ( "Could not bind to port." );
    }

	if (!Socket::listen())
    {
      	throw SocketException ( "Could not listen to socket." );
    }

}

ServerSocket::~ServerSocket()
{
}


const ServerSocket& ServerSocket::operator << (const std::string& s) const
{
	if(!Socket::send(s))
    {
      	throw SocketException("Could not write to socket.");
    }
	
	return *this;
}


const ServerSocket& ServerSocket::operator >> ( std::string& s ) const
{
	if (!Socket::recv(s))
    {
    	throw SocketException ( "Could not read from socket." );
    }

  	return *this;
}

void ServerSocket::accept(ServerSocket& sock)
{
	if (!Socket::accept(sock))
    {
		throw SocketException ("Could not accept socket.");
    }
}


void ServerSocket::create_thread_pool()
{
	int i = 0;
	for (i = 0; i < THREAD_NUM; ++i)
	{                                                                           
		//pthread_t tid = 0;                                                                                 
		//pthread_create(&tid, NULL, (void *)process, NULL); 
		//ThreadIdleId[TIdleNum]=tid;          
		//++TIdleNum;
		
	}
}

