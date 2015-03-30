#include "server_socket.h"
#include "socket_exception.h"
#include <string>

int main ( int argc, char* argv[] )
{
  std::cout << "server running....\n";
  try
    {
      /*1.Create the server socket*/
      ServerSocket server (3001);
	  /*2.It is the responsibility of the server to accept the client's connection attempt, which opens up a channel of communication between the two socket endpoints.*/

	    while ( true )
		{

		  ServerSocket new_sock;
		  server.accept ( new_sock );
			/*Every piece of data that gets sent from the client to the server gets sent back to the client as is.*/
		  try
		    {
				while ( true )
				{
					std::string data;
				  	new_sock >> data;//read data from client through new_sock
				  	new_sock << data;//write data to client through new_sock
				}
		    }
		  catch (SocketException&) {}

		}
    }
  //exception: throws an exception of type SocketException,, which is defined in SocketException.h
  	catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\nExiting.\n";
    }

  	return 0;
}
