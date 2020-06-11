/// Class Encryptor Interface.
#include <string>

class Encryptor
{
private:
    /// Constructor of this class.
    Encryptor();

    static Encryptor* instance; ///< Instance of Encryptor to avoid making multiple objects.
    static Encryptor* get_instance();
    
    /// This function encrypts a specific file.
    /// Return value is name of the encrypted file.
    static std::string encrypt(std::string filename /**< [in] Name of the file to encrypt. */);
    
    /// This function decrypts a specific file.
    /// Return value is name of the decrypted file.
    static std::string decrypt(std::string filename /**< [out] Name of the file to decrypt. */);
};
Encryptor *Encryptor::instance = NULL;