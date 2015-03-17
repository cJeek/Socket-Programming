#include "client_socket.h"
#include "socket_exception.h"
#include <iostream>
#include <string>

int main ( int argc, char* argv[] )
{
	try
	{
		/*Create the client socket*/
      ClientSocket client_socket ( "localhost", 30000 );

      std::string reply;
	/*We send the string "Test Message." to the server, read the response from the server, and print out the response to std output.*/
      while (1)
	  {
	  
		try
		{
			client_socket << "Test message.";
			client_socket >> reply;
		}
		catch ( SocketException& ) {}


		std::cout << "We received this response from the server:\n\"" << reply << "\"\n";;

		}
	}
  catch ( SocketException& e )
    {
      std::cout << "Exception was caught:" << e.description() << "\n";
    }

  return 0;
}
