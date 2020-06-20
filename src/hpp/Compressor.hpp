/***************************************************************************//**
 * Class Compressor Interface.
 ******************************************************************************/
#ifndef _COMPRESSOR_HPP_
#define _COMPRESSOR_HPP_

#include <string>
#include <iostream>
#include <vector>
#include "Exceptions.hpp"

class Compressor
{
private:
    Compressor();
    static Compressor* instance; /**< Instance of Compressor to avoid making multiple objects. */
    
public:
    static Compressor* get_instance() noexcept;
    
    /** Compress a specific file and return the compressed file name.
     *  @param {string} filename - Name of the file.
    */
    std::string compress(std::string filename);
    
    /** Decompress a specific file and return the decompressed file name.
     *  @param {string} filename - Name of the file.
    */
    void decompress(std::string filename);

    /** Delete file.
     *  @param {string} filename - Nacompresse of the file.
    */
    void destruct(std::string filename);
};

#endif