// Client side C/C++ program to demonstrate Socket programming 
#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#define PORT 8080 

int main(int argc, char const *argv[]) 
{ 
	int sock = 0, valread; 
	int num;
	char sendbuffer[1024] = {};
	struct sockaddr_in serv_addr; 
	const char *filename = argv[1]; 
	char status[64] = {0}; 
	sock = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 	
	inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
	connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));	
	send(sock, filename, strlen(filename), 0);
	FILE *fp = fopen(filename, "rb");
	while((num = fread(sendbuffer, 1, sizeof(sendbuffer), fp)) > 0)
	{
        send(sock, sendbuffer, num, 0);
    }
	fclose(fp); 
	return 0; 
} 

