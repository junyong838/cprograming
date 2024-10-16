#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

void encrypt(const char* inputString, const unsigned char* key, char* encryptedOutput, int* num);
void decrypt(const char* hexString, const unsigned char* key, char** decryptedOutput);

#pragma comment(lib, "libssl.lib")
#pragma comment(lib, "libcrypto.lib")

#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/conf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	errno_t err = 0;
	FILE* in_file, * key_file;
	int numbytes;

	// 암호화된 파일 열기
	err = fopen_s(&in_file, "cipher.txt", "rt");
	if (err != 0) {
		printf("Failed to open cipher file\n");
		return 1;
	}

	// 키 파일 열기
	err = fopen_s(&key_file, "secret_key.txt", "rt");
	if (err != 0) {
		printf("Failed to open key file\n");
		return 2;
	}

	// 암호문 파일 크기 확인
	fseek(in_file, 0L, SEEK_END);
	numbytes = ftell(in_file);
	fseek(in_file, 0L, SEEK_SET);

	// 암호문 파일 읽기
	char* encryptedMessage = (char*)malloc(numbytes + 1);
	fread(encryptedMessage, numbytes, 1, in_file);
	encryptedMessage[numbytes] = '\0';

	// 키 파일 읽기
	char hexKey[(EVP_MAX_KEY_LENGTH * 2) + 1];
	fread(hexKey, sizeof(hexKey), 1, key_file);
	hexKey[EVP_MAX_KEY_LENGTH * 2] = '\0';

	// 복호화할 평문 저장 공간
	char* decryptedMessage = NULL;

	// 복호화 수행
	decrypt(encryptedMessage, (const unsigned char*)hexKey, &decryptedMessage);

	// 복호화된 평문 출력
	printf("Decrypted message: %s\n", decryptedMessage);

	// 파일 닫기 및 메모리 해제
	fclose(in_file);
	fclose(key_file);
	free(encryptedMessage);
	free(decryptedMessage);

	return 0;
}


void encrypt(const char* inputString, const unsigned char* key, char* encryptedOutput, int* num) {
	EVP_CIPHER_CTX* ctx;
	int len;
	int ciphertextLen;
	unsigned char ciphertext[512];

	// Create and initialize the context
	ctx = EVP_CIPHER_CTX_new();
	EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL);

	// Encrypt the input string
	EVP_EncryptUpdate(ctx, ciphertext, &len, (const unsigned char*)inputString, strlen(inputString));
	ciphertextLen = len;

	// Finalize the encryption
	EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
	ciphertextLen += len;

	// Clean up the context
	EVP_CIPHER_CTX_free(ctx);

	// Convert the encrypted data to a hexadecimal string
	for (int i = 0; i < ciphertextLen; ++i) {
		sprintf(&encryptedOutput[i * 2], "%02x", ciphertext[i]);
	}
	*num = ciphertextLen * 2;
	encryptedOutput[ciphertextLen * 2] = '\0';
}
void decrypt(const char* hexString, const unsigned char* key, char** decryptedOutput) {
	EVP_CIPHER_CTX* ctx;
	int len;
	int plaintextLen;

	// Create and initialize the context
	ctx = EVP_CIPHER_CTX_new();
	EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, NULL);

	// Convert the hexadecimal string to binary
	int hexLen = strlen(hexString);
	unsigned char* binaryData = (unsigned char*)malloc(hexLen / 2);

	for (int i = 0; i < hexLen / 2; ++i) {
		sscanf(&hexString[i * 2], "%2hhx", &binaryData[i]);
	}

	// Decrypt the binary data
	unsigned char* plaintext = (unsigned char*)malloc(hexLen / 2);
	EVP_DecryptUpdate(ctx, plaintext, &len, binaryData, hexLen / 2);
	plaintextLen = len;

	// Finalize the decryption
	EVP_DecryptFinal_ex(ctx, plaintext + len, &len);
	plaintextLen += len;

	// Clean up the context
	EVP_CIPHER_CTX_free(ctx);
	free(binaryData);  // Free the dynamically allocated memory

	// Null-terminate the decrypted data
	plaintext[plaintextLen] = '\0';

	// Assign the decrypted data to the output buffer
	*decryptedOutput = (char*)plaintext;
}
