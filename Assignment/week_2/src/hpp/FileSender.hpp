/// Class FileSender Interface.

#include "Encryptor.hpp"
#include "Compressor.hpp"
class FileSender
{
private:
    /// Instances to compress and encrypt files.
    Compressor* compressor; ///< Instance to compress file.
    Encryptor* encryptor;   ///< Instance to encrypte file.

    /// This function initials socket.
    int connect();

    /// This function sends compressed and encrypted file to server.
    int send_to_server(std::string filename /**< [in] Name of the file to be sent. */);

public:
    /// Constructor of this class. 
    FileSender();

    /// This function compresses file, encryptes the 
    /// compressed file and send on server.
    void send_file(std::string filename /**< [in] Name of the file to be sent. */);
};