/// Class FileReceiver Interface.

#include "Encryptor.hpp"
#include "Compressor.hpp"
class FileReceiver
{
private:
    /// Instances to compress and encrypt files.
    Compressor* compressor; ///< Instance to decompress file.
    Encryptor* encryptor;   ///< Instance to decrypte file.

    /// This function initials server.
    int start();

    /// This function saves compressed and encrypted file on server.
    int save_on_server();
public:
    /// Constructor of this class. 
    FileReceiver();

    /// This function decryptes file and decompresses the 
    /// decrypted file on server after receiving it.
    /// Return value is name of the received file.
    std::string receive();
};