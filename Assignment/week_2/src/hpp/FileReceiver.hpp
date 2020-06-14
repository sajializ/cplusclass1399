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
using std::string;

class FileReceiver
{
private:
    Compressor* compressor; /**< Instance to decompress file. */
    Encryptor* encryptor;   /**< Instance to decrypt file. */

    /** A private member function.
    *   Start server.
    */
    int start(int PORT);

    /** A private member function.
    *   Save compressed and encrypted file on server.
    */
    int save_on_server();
public:
    /** A constructor
    *   Get Compressor* and Encryptor* instances.
    */ 
    FileReceiver();

    /** A public member function.
    *   Decryptes and decompresses file and save on server.
    *   Return value is file name.
    *   Multi thread reciever.
    */
    std::string receive();
};

#endif