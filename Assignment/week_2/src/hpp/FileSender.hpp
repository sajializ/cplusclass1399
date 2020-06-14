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

class FileSender
{
private:

    Compressor* compressor; /**< Instance to compress file. */
    Encryptor* encryptor;   /**< Instance to encrypte file. */

    /** Initial socket.
     *  If initialing was successful returns 1 else throw exception.
     *  @param {string} host - Server host to initial socket.
     *  @param {int} PORT - The Port that server listens to.
    */
    int connect(std::string host, int PORT);
    
    /** Send compressed and encrypted file to server.
     *  If sending file was successful returns 1 else throw exception.
     *  @param {string} filename - Name of the file.
    */
    int send_to_server(std::string filename);

public:
    /** Get Compressor* and Encryptor* instances.
    */
    FileSender();

    /** Compress and encrypt file and send to server.
     *  @param {string} filename - Name of the file.
    */
    void send_file(std::string filename);
};

#endif