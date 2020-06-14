/***************************************************************************//**
 * Class FileSender Interface.
 ******************************************************************************/

#ifndef _FILESENDER_HPP_
#define _FILESENDER_HPP_

#include "Encryptor.hpp"
#include "Compressor.hpp"
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
using std::string;

class FileSender
{
private:

    Compressor* compressor; /**< Instance to compress file. */
    Encryptor* encryptor;   /**< Instance to encrypte file. */

    /** A private member function.
    *   Initial socket
    */
    int connect(string host, int PORT);
    
    /** A private member function.
    *   Send compressed and encrypted file to server.
    */
    int send_to_server(string filename /**< [in] Name of the file to be sent. */);

public:
    /** A constructor
    *   Get Compressor* and Encryptor* instances.
    */
    FileSender();

    /** A public member function.
    *   Compress and encrypt file and send to server.
    */
    void send_file(string filename /**< [in] Name of the file to be sent. */);
};

#endif