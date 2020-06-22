#include "hpp/Compressor.hpp"

Compressor* Compressor::instance = NULL;

Compressor::Compressor()
{

}

void Compressor::destruct(std::string filename)
{
    system(("rm " + filename).c_str());
}

Compressor* Compressor::get_instance() noexcept
{
    if (instance == NULL)
    {
        instance = new Compressor();
    }
    return instance;
}

std::string Compressor::compress(std::string filename)
{
    int pos = filename.find(".");
    std::string command; 
    std::string sub = filename;
    if(pos == 0)
    {
        throw INVALID_NAME {};
    }
    else if(pos > 0)
    {
        sub = filename.substr(0,pos);
        command = "zip " + sub + ".zip " + filename;
    }  
    else
    {
        command = "zip -r " + sub + ".zip " + filename;
    } 
    system(command.c_str());
    return sub + ".zip";
}

void Compressor::decompress(std::string filename)
{
    system(("unzip " + filename).c_str());
    return;
}
