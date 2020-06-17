/***************************************************************************//**
 * Class FileSender Interface.
 ******************************************************************************/

#ifndef _FILESENDER_HPP_
#define _FILESENDER_HPP_

#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include "Encryptor.hpp"
#include "Compressor.hpp"
#include "Exceptions.hpp"

class FileSender
{
private:
    std::string server_host; /**< Server host. */
    int PORT; /**< The Port that server listens to. */
    int sock; /**< The socket to send data. */
    int DOMAIN; /**< The socket domain. */
    int TYPE; /**< The socket type. */
    int PROTOCOL; /**< The socket protocol. */
    Compressor* compressor; /**< Instance to compress file. */
    Encryptor* encryptor;   /**< Instance to encrypte file. */

    /** Initial socket.
     *  If initialing was successful returns true else throw CONNECTION_FAILED.
    */
    bool connect_to_server();
    
    /** Send compressed and encrypted file to server.
     *  If sending file was successful returns true else throw SENDING_FAILED.
     *  @param {string} filename - Name of the file.
    */
    bool send_to_server(std::string filename) const;

public:
    /** Get Compressor* and Encryptor* instances.
     *  Set server_host and PORT. Resets sock.
     *  @param {string} host - Server host to initial socket.
     *  @param {int} PORT - The Port that server listens to.
     *  @param {int} domain - socket domain - AF_INET is default.
     *  @param {int} type - socket type - SOCK_STREAM is default.
     *  @param {int} protocol - socket protocol - 0 is default.
    */
    FileSender(std::string host, int port, int domain, int type, int protocol);

    /** Compress and encrypt file and send to server.
     *  Returns true on success. Else return false and log the problem.
     *  @param {string} filename - Name of the file.
    */
    bool send_file(std::string filename) noexcept;
};

#endif