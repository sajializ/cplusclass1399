#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#define PORT 8080

int main(int argc, char const *argv[]) 
{
	int server_socket, new_socket, valread; 
	struct sockaddr_in address; 
	int opt = 1; 
	int addrlen = sizeof(address); 
	char buffer[1024] = {0}; 
	char temp[1024];
	// Creating Server Socket
	server_socket = socket(AF_INET, SOCK_STREAM, 0);
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(PORT); 
	// bind socket to the port (localhost) 
	bind(server_socket, (struct sockaddr *)&address, sizeof(address)); 
	listen(server_socket, 3);
	new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
	int b = read(new_socket, temp, 1024);
	char* filename = (char*)malloc(b + 2);
	*(filename) = 'c';
	strcat(filename,temp);
	filename[b + 1] = '\0';
	FILE *fp = fopen(filename, "wb");
	while((valread = read(new_socket ,buffer, 1024)) > 0)
		fwrite(buffer, 1, valread, fp);
	fclose(fp);
	return 0;
} 
