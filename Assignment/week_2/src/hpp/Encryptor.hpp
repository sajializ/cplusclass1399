/***************************************************************************//**
 * Class Encryptor Interface.
 ******************************************************************************/

#ifndef _ENCRYPTOR_HPP_
#define _ENCRYPTOR_HPP_

#include <string>
using std::string;

class Encryptor
{
private:
    /** A private constructor
    *   Handle singleton.
    */ 
    Encryptor();

    static Encryptor* instance; /**< Instance of Encryptor to avoid making multiple objects. */
    static Encryptor* get_instance();
    
public:
    /** A public member function.
    *   Encrypt a specific file and return the encrypted file name.
    */
    static string encrypt(string filename /**< [in] Name of the file to encrypt. */);
    
    /** A public member function.
    *   Dncrypt a specific file and return the decrypted file name.
    */
    static string decrypt(string filename /**< [out] Name of the file to decrypt. */);
};
Encryptor *Encryptor::instance = NULL;

#endif