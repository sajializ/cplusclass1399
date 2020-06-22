#ifndef _DECRYPT_
#define _DECRYPT_

#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>

void SubRoundKey(unsigned char * state, unsigned char * roundKey);
void InverseMixColumns(unsigned char * state);
void _ShiftRows(unsigned char * state);
void _SubBytes(unsigned char * state);
void _Round(unsigned char * state, unsigned char * key);
void InitialRound(unsigned char * state, unsigned char * key);
void AESDecrypt(unsigned char * encryptedMessage, unsigned char * expandedKey, unsigned char * decryptedMessage);

#endif