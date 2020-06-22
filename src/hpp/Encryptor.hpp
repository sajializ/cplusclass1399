/***************************************************************************//**
 * Class Encryptor Interface.
 ******************************************************************************/

#ifndef _ENCRYPTOR_HPP_
#define _ENCRYPTOR_HPP_

#include <string>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Exceptions.hpp"

class Encryptor
{
private:
    Encryptor();

    static Encryptor* instance; /**< Instance of Encryptor to avoid making multiple objects. */
       
public:
    static Encryptor* get_instance() noexcept;

    /** Encrypt a specific message and return the encrypted result.
     *  @param {char[]} message - message to encrypt.
     *  @param {int} len - length of encrypted message.
    */
    unsigned char* encrypt(char message[], int& len) const;
    
    /** Decrypt a specific message and return the decrypted result.
     *  @param {char*} msg - message to decrypt.
     *  @param {int} len - length of decrypted message.
    */
    unsigned char* decrypt(char* msg, int& len) const;
};

#endif