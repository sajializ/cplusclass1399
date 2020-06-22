#include "hpp/FileReceiver.hpp"

FileReceiver::FileReceiver(int port, int domain = AF_INET, int type = SOCK_STREAM, int protocol = 0)
{
    PORT = port;
	DOMAIN = domain;
	TYPE = type;
	PROTOCOL = protocol;
}

bool FileReceiver::initial_server()
{
	int bind_flag, listen_flag;
	server_socket = socket(DOMAIN, TYPE, PROTOCOL);
	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; 
	address.sin_port = htons(PORT); 
	bind_flag = bind(server_socket, (struct sockaddr *)&address, sizeof(address)); 
	listen_flag = listen(server_socket, 3);
	if(server_socket == 0 || bind_flag < 0 || listen_flag < 0)
	{
		throw STARTING_FAILED {};
	}
	std::cout << "-> Starting server." << std::endl;
    return true;
}
std::string FileReceiver::save_on_server(const int thread_socket)
{
	int valread, bread;
	std::string filename;
    char buffer[1024] = {0}; 
	unsigned char* decrypted;
	read(thread_socket, buffer, 1024);
	if(((std::string)buffer).size() == 0)
	{
		throw BAD_REQUEST {}; 
	}
	filename = (std::string)buffer;
	FILE *fp = fopen(filename.c_str(), "w");
	int len;
	while((valread = read(thread_socket ,buffer, 1024)) > 0)
	{	
		// This part is for decrypting data
//		decrypted = Encryptor::get_instance()->decrypt(buffer, len);
//		fwrite(decrypted, 1, strlen((const char *)decrypted), fp);
//		delete[] decrypted;
		fwrite(buffer, 1, valread, fp);
	}
	fclose(fp);
	std::cout << "-> Receiving "<< filename <<" successful." << std::endl;
    return filename;
}
bool FileReceiver::receive(const int thread_socket) noexcept
{
	std::string filename;
	try
	{
		filename = this->save_on_server(thread_socket);
		(Compressor::get_instance())->decompress(filename);
		(Compressor::get_instance())->destruct(filename);
		return true;
	}
	catch(const std::exception& e)
	{
		std::cout << "-> " << e.what() << std::endl;
		return false;
	}
}
void FileReceiver::start() noexcept
{
//	std::vector<std::thread*> ts;
	try
	{
		this->initial_server();
	}
	catch(const std::exception& e)
	{
		std::cout << "-> " << e.what() << std::endl;
		return;
	}
	while(true)
	{
		try
		{
			int addrlen = sizeof(address);
			std::cout << "-> Waiting..." << std::endl;
    		int new_socket = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen);
			if(new_socket < 0)
			{
				throw SAVING_FAILED {};
			}
			this->receive(new_socket);
			// This part is for multi threading.
			//std::thread* t = new std::thread(&FileReceiver::receive, this, new_socket);
			//ts.push_back(t);
		}
		catch(const std::exception& e)
		{
			std::cout << "-> " << e.what() << std::endl;
		}
	}
/*	for(int i = 0; i < ts.size();i++)
	{
		ts[i]->join();
	}*/
	
}
int main()
{
    FileReceiver s(9090);
	s.start();
}