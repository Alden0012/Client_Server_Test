#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main(){
	int client, server;
	int port = 1500;
	int running = false;
	int bufferSize = 1024;
	char buffer[bufferSize];

	struct sockaddr_in server_addr;
	socklen_t size;

	client = socket(AF_INET, SOCK_STREAM, 0);
	if (client < 0)
	{
		cout << "\n Could not establish socket." << endl;
		exit(1);
	}
	cout << "Socket created." << endl;
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htons(INADDR_ANY);
	server_addr.sin_port = htons(portNum);
	size = sizeof(server_addr);
	
	if(bind(client, (struct sockaddr*)&server_addr,size < 0){
	cout << "Binding failed, socket already bound" << endl;
	return -1;
	}
	cout << "Listening to clients.." << endl;

	listen(client, 1);

	int clientCount = 1;
	server = accept(client,(struct sockaddr *)&server_addr, &size);

	if (server < 0){
		cout << "Error: Failed to accept client" << endl;
	}
	while (server < 0){
		buffer = "=> Server Connected \n";
		send(server,buffer,bufferSize,0);
		cout << "=> Connected to client #" << clientCount << endl;
		cout << "\n=> Enter # to end the connection\n" << endl;

		cout << "Client: ";
        do {
            recv(server, buffer, bufferSize, 0);
            cout << buffer << " ";	
            if (*buffer == '#') {
                *buffer = '*';
                running = true;
            }
        } while (*buffer != '*');

        do {
            cout << "\nServer: ";
            do {
                cin >> buffer;
                send(server, buffer, bufferSize, 0);
                if (*buffer == '#') {
                    send(server, buffer, bufferSize, 0);
                    *buffer = '*';
                    running = true;
                }
            } while (*buffer != '*');

            cout << "Client: ";
            do {
                recv(server, buffer, bufferSize, 0);
                cout << buffer << " ";
                if (*buffer == '#') {
                    *buffer == '*';
                    running = true;
                }
            } while (*buffer != '*');
        } while (!running);

        

        // inet_ntoa converts packet data to IP, which was taken from client
        cout << "\n\n=> Connection terminated with IP " << inet_ntoa(server_addr.sin_addr);
        close(server);
        cout << "\nGoodbye..." << endl;
        running = false;
        exit(1);
}



