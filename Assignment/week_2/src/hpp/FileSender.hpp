/***************************************************************************//**
 * Class FileSender Interface.
 ******************************************************************************/

#ifndef _FILESENDER_HPP_
#define _FILESENDER_HPP_

#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include "Encryptor.hpp"
#include "Compressor.hpp"
#include "Exceptions.hpp"

class FileSender
{
private:
    std::string server_host; /**< Server host. */
    int PORT; /**< The Port that server listens to. */
    int sock; /**< The socket to send data. */
    Compressor* compressor; /**< Instance to compress file. */
    Encryptor* encryptor;   /**< Instance to encrypte file. */

    /** Initial socket.
     *  If initialing was successful returns true else throw CONNECTION_FAILED.
    */
    const bool connect_to_server();
    
    /** Send compressed and encrypted file to server.
     *  If sending file was successful returns true else throw SENDING_FAILED.
     *  @param {string} filename - Name of the file.
    */
    const bool send_to_server(std::string filename);

public:
    /** Get Compressor* and Encryptor* instances.
     *  Set server_host and PORT. Resets sock.
     *  @param {string} host - Server host to initial socket.
     *  @param {int} PORT - The Port that server listens to.
    */
    FileSender(std::string host, int port);

    /** Compress and encrypt file and send to server.
     *  Returns true on success. Else return false and log the problem.
     *  @param {string} filename - Name of the file.
    */
    const bool send_file(std::string filename) noexcept;
};

#endif