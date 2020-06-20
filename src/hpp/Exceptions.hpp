#ifndef _EXCEPTIONS_
#define _EXCEPTIONS_

#include <exception>

class CONNECTION_FAILED: public std::exception
{
    virtual const char* what() const throw()
    {
        return "Failed to connect to the server.";
    }
};

class NOT_EXISTED: public std::exception
{
    virtual const char* what() const throw()    
    {
        return "File does not exist.";
    }
};

class STARTING_FAILED: public std::exception
{
    virtual const char* what() const throw()    
    {
        return "Failed to start the server.";
    }
};

class SAVING_FAILED: public std::exception
{
    virtual const char* what() const throw()    
    {
        return "Failed to save file on server.";
    }
};

class BAD_REQUEST: public std::exception
{
    virtual const char* what() const throw()    
    {
        return "Bad request.";
    }
};

class INVALID_NAME: public std::exception
{
    virtual const char* what() const throw()    
    {
        return "Invalid name of the file.";
    }
};
#endif