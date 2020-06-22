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
#include <vector>
#include "Encryptor.hpp"
#include "Compressor.hpp"
#include "Exceptions.hpp"

#define MULTI_THREAD_ON 1
#define MULTI_THREAD_OFF 0

class FileReceiver
{
private:
    unsigned int PORT; /**< The Port that server listens to. */
    unsigned int server_socket; /**< The server socket. */
    unsigned int DOMAIN; /**< The socket domain. */
    unsigned int TYPE; /**< The socket type. */
    unsigned int PROTOCOL; /**< The socket protocol. */
    unsigned int MULTI_THREAD; /**< 1 if multi thread is on. Else zero. */
    struct sockaddr_in address; /**< Server config. */
    Compressor* compressor; /**< Instance to decompress file. */
    Encryptor* encryptor;   /**< Instance to decrypt file. */

    /** Initial server.
     *  If initialing server was successful returns true else throw STARTING FAILED.
    */
    bool initial_server();

    /** Save compressed and encrypted file on server.
     *  If saving on server was successful returns name of the file
     *  else throw SAVING_FAILED.
    */
    std::string save_on_server(const int thread_socket) const;

    /** Decryptes and decompresses file and save on server.
    *   Return value is true on success. Else it is false.
    *   Multi thread reciever.
    */
    bool receive(const int thread_socket) const noexcept;

public:
    /** Get Compressor* and Encryptor* instances.
     *  @param {int} port - PORT
     *  @param {int} domain - socket domain - AF_INET is default.
     *  @param {int} type - socket type - SOCK_STREAM is default.
     *  @param {int} protocol - socket protocol - 0 is default.
    */ 
    FileReceiver(int port, int domain, int type, int protocol);

    /** Start server ready to receive data
     *  @param {int} multi_thread_option - sets MULTI_THREAD. 
    */
    void start(int multi_thread_option) noexcept;
};

#endif