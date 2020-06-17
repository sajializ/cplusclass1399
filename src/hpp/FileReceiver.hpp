/***************************************************************************//**
 * Class FileReceiver Interface.
 ******************************************************************************/

#ifndef _FILERECEIVER_HPP_
#define _FILERECEIVER_HPP_

#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>
#include <string>
#include <iostream>
#include <fstream>
#include <thread>
#include "Encryptor.hpp"
#include "Compressor.hpp"
#include "Exceptions.hpp"

class FileReceiver
{
private:
    int PORT; /**< The Port that server listens to. */
    int server_socket; /**< The server socket. */
    int DOMAIN; /**< The socket domain. */
    int TYPE; /**< The socket type. */
    int PROTOCOL; /**< The socket protocol. */
    struct sockaddr_in address; /**< Server config. */
    Compressor* compressor; /**< Instance to decompress file. */
    Encryptor* encryptor;   /**< Instance to decrypt file. */

    /** Initial server.
     *  If initialing server was successful returns true else throw STARTING FAILED.
    */
    bool initial_server();

    /** Save compressed and encrypted file on server.
     *  If saving on server was successful returns true else throw SAVING_FAILED.
    */
    bool save_on_server(const int thread_socket);

    /** Decryptes and decompresses file and save on server.
    *   Return value is true on success. Else it is false.
    *   Multi thread reciever.
    */
    bool receive(const int thread_socket) noexcept;

public:
    /** Get Compressor* and Encryptor* instances.
     *  @param {int} port - PORT
     *  @param {int} domain - socket domain - AF_INET is default.
     *  @param {int} type - socket type - SOCK_STREAM is default.
     *  @param {int} protocol - socket protocol - 0 is default.
    */ 
    FileReceiver(int port, int domain, int type, int protocol);

    /** Start server ready to receive data
    */
    void start() noexcept;
};

#endif