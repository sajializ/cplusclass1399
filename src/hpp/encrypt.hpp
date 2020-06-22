#ifndef _ENCRYPT_
#define _ENCRYPT_


#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

void AddRoundKey(unsigned char * state, unsigned char * roundKey);
void SubBytes(unsigned char * state);
void ShiftRows(unsigned char * state);
void MixColumns(unsigned char * state);
void Round(unsigned char * state, unsigned char * key);
void FinalRound(unsigned char * state, unsigned char * key);
void AESEncrypt(unsigned char * message, unsigned char * expandedKey, unsigned char * encryptedMessage);

#endif