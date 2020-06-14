/***************************************************************************//**
 * Class FileReceiver Interface.
 ******************************************************************************/

#ifndef _FILERECEIVER_HPP_
#define _FILERECEIVER_HPP_

#include "Encryptor.hpp"
#include "Compressor.hpp"
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 

class FileReceiver
{
private:
    Compressor* compressor; /**< Instance to decompress file. */
    Encryptor* encryptor;   /**< Instance to decrypt file. */

    /** Start server.
     * If starting server was successful returns 1 else throw exception.
     * @param {int} PORT - Port to listen.
    */
    int start(int PORT);

    /** Save compressed and encrypted file on server.
     *  If saving on server was successful returns 1 else throw exception.
    */
    int save_on_server();

public:
    /** Get Compressor* and Encryptor* instances.
    */ 
    FileReceiver();

    /** Decryptes and decompresses file and save on server.
    *   Return value is file name.
    *   Multi thread reciever.
    */
    std::string receive();
};

#endif