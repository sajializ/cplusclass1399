#include "hpp/FileSender.hpp"

FileSender::FileSender(std::string host, int port, int domain = AF_INET, int type = SOCK_STREAM, int protocol = 0)
{
    server_host = host;
    PORT = port;
    sock = -1;
}
bool FileSender::connect_to_server()
{
    int inet_flag, connect_flag;
    struct sockaddr_in serv_addr; 
    sock = socket(AF_INET, SOCK_STREAM, 0);
	serv_addr.sin_family = AF_INET; 
	serv_addr.sin_port = htons(PORT); 	
	inet_flag = inet_pton(AF_INET, server_host.c_str(), &serv_addr.sin_addr);
	connect_flag = connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if(sock < 0 || inet_flag <= 0 || connect_flag < 0)
    {
        throw CONNECTION_FAILED {};
    }
    return true;
}
bool FileSender::send_to_server(std::string filename) const
{
    char sendbuffer[1025] = {};
    unsigned char* encrypted = nullptr;
    int num = -1;
    FILE *fp = fopen(filename.c_str(), "r");
    if(fp == nullptr)
        throw NOT_EXISTED {};
    send(sock, filename.c_str(), filename.size(), 0);
    int len = 0;
	while((num = fread(sendbuffer, 1, 1024, fp)) > 0)
	{
        encrypted = Encryptor::get_instance()->encrypt(sendbuffer, len);
        send(sock, encrypted, len, 0);
        memset(sendbuffer, '\0', sizeof(sendbuffer));
    }
	fclose(fp); 
    return true; 
}
bool FileSender::send_file(std::string filename) noexcept
{
    std::string cn;
    try
    {
        // TODO compress file.
        // cn = (Compressor::get_instance())->compress(filename);
        this->connect_to_server();
        this->send_to_server(filename);
        std::cout << "File sent successfuly." << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
        return false;
    }
    return true;  
}


int main(int argc, char *argv[])
{
    FileSender f("127.0.0.1",9090);
    f.send_file(std::string(argv[1]));
}