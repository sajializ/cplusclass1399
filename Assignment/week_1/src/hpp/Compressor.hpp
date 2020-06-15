/// Class Compressor Interface.
#include <string>

class Compressor
{
private:
    /// Constructor of this class.
    Compressor();

    static Compressor* instance; ///< Instance of Compressor to avoid making multiple objects.
    static Compressor* get_instance();
    
    /// This function compress a specific file.
    /// Return value is name of the compressed file.
    static std::string compress(std::string filename /**< [in] Name of the file to compress. */);
    
    /// This function decompress a specific file.
    /// Return value is name of the decompressed file.
    static std::string decompress(std::string filename /**< [out] Name of the file to decompress. */);
};
Compressor *Compressor::instance = NULL;