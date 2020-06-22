#include "hpp/Encryptor.hpp"
#include "hpp/structures.h"
using namespace std;
Encryptor* Encryptor::instance = NULL;

Encryptor::Encryptor()
{

}

Encryptor* Encryptor::get_instance() noexcept
{
    if (instance == NULL)
    {
        instance = new Encryptor();
    }
    return instance;
}

unsigned char* Encryptor::encrypt(char message[], int& len) 
{
	int originalLen = strlen((const char *)message);
	int paddedMessageLen = originalLen;
	if ((paddedMessageLen % 16) != 0) {
		paddedMessageLen = (paddedMessageLen / 16 + 1) * 16;
	}
	unsigned char * paddedMessage = new unsigned char[paddedMessageLen];
	for (int i = 0; i < paddedMessageLen; i++) {
		if (i >= originalLen) {
			paddedMessage[i] = 0;
		}
		else {
			paddedMessage[i] = message[i];
		}
	}
	unsigned char * encryptedMessage = new unsigned char[paddedMessageLen];
	string str;
	ifstream infile;
	infile.open("keyfile", ios::in | ios::binary);
	if (infile.is_open())
	{
		getline(infile, str);
		infile.close();
	}
	else throw INVALID_KEYFILE_NAME {};
	istringstream hex_chars_stream(str);
	unsigned char key[16];
	int i = 0;
	unsigned int c;
	while (hex_chars_stream >> hex >> c)
	{
		key[i] = c;
		i++;
	}
	unsigned char expandedKey[176];
	KeyExpansion(key, expandedKey);
	for (int i = 0; i < paddedMessageLen; i += 16) {
		AESEncrypt(paddedMessage+i, expandedKey, encryptedMessage+i);
	}
	delete[] paddedMessage;
	len = paddedMessageLen;
	return encryptedMessage;
}

unsigned char* Encryptor::decrypt(char* msg, int& len) 
{
	int n = strlen((const char*)msg);
	unsigned char * encryptedMessage = new unsigned char[n];
	for (int i = 0; i < n; i++) {
		encryptedMessage[i] = (unsigned char)msg[i];
	}
	string keystr;
	ifstream keyfile;
	keyfile.open("keyfile", ios::in | ios::binary);
	if (keyfile.is_open())
	{
		getline(keyfile, keystr);
		keyfile.close();
	}
	else cout << "Unable to open file";
	istringstream hex_chars_stream(keystr);
	unsigned char key[16];
	int i = 0;
	unsigned int c;
	while (hex_chars_stream >> hex >> c)
	{
		key[i] = c;
		i++;
	}
	unsigned char expandedKey[176];
	KeyExpansion(key, expandedKey);	
	int messageLen = strlen((const char *)encryptedMessage);
	unsigned char * decryptedMessage = new unsigned char[messageLen];
	for (int i = 0; i < messageLen; i += 16) {
		AESDecrypt(encryptedMessage + i, expandedKey, decryptedMessage + i);
	}
	len = messageLen;
	return decryptedMessage;
}
