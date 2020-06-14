/***************************************************************************//**
 * Class Compressor Interface.
 ******************************************************************************/
#ifndef _COMPRESSOR_HPP_
#define _COMPRESSOR_HPP_

#include <string>
using std::string;

class Compressor
{
private:
    /** A private constructor
    *   Handle singleton.
    */ 
    Compressor();

    static Compressor* instance; /**< Instance of Compressor to avoid making multiple objects. */
    static Compressor* get_instance();
    
    /** A public member function.
    *   Compress a specific file and return the compressed file name.
    */
    static string compress(string filename /**< [in] Name of the file to compress. */);
    
    /** A public member function.
    *   Decompress a specific file and return the decompressed file name.
    */
    static string decompress(string filename /**< [out] Name of the file to decompress. */);
};
Compressor *Compressor::instance = NULL;

#endif