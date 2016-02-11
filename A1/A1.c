#include <stdio.h>
#include <string.h>

#define MAX_BUF 256

unsigned char getBit(unsigned char, int);
unsigned char setBit(unsigned char, int);
unsigned char clearBit(unsigned char, int);
unsigned char skipx(unsigned char, unsigned char);
unsigned char rotr(unsigned char);

unsigned char getBit(unsigned char c, int n) {

	return (c & (1<<n))>>n;

}
	
unsigned char setBit(unsigned char c, int n) {

	return c|(1<<n); 
	
}

unsigned char clearBit(unsigned char c, int n) {
	
	return c & (~(1<<n));

}

// the function skipx  

unsigned char skipx(unsigned char source, unsigned char key){
	int i;//CHANGED
	unsigned char result = source;
	
	for(i = 7; i > 0; i-=2){
		if( (getBit(source, i) ^ getBit(key, i-1)) == 0){
			result = clearBit(result, i);
		}else{
			result = setBit(result, i);	
    }
	}
	return result;

}

// the rotr function performs a right circular shift of the bits in the provided byte c 

unsigned char rotr(unsigned char c){ 
	unsigned char a = getBit(c, 0) << 7; //gets the bit at position 0 and persorms a shift 
	unsigned char b = c >> 1;

	return a ^ b;

}


int main(){

	//printf("%d \n", skipx(49, 12));

	char str[8];
	char userMessage[MAX_BUF];
	unsigned char tempResult;

	unsigned int choice;
	unsigned int input;
	unsigned int encryptedArray[MAX_BUF];
	int i = 0;
	int size = 0;
	int key;
	int updatedKey;



	printf("\nYou have the following options:\n");
    printf("  (1) Encrypt a message \n");
    printf("  (2) Decrypt a message \n");
    printf("\n  what is your selection: ");

    fgets(str, sizeof(str), stdin);
    str[strlen(str)-1] = '\0';
    sscanf(str, "%d", &choice);
	switch (choice) {

		case 1:
			printf("Enter a plaintext message to be encrypted: \n");
			fgets(userMessage, sizeof userMessage, stdin); // reads in plaintext
      		userMessage[strlen(userMessage)-1] = '\0';
			printf("this is the message: %s\n", userMessage);
			
			printf("Enter an integer key for your message to be encrypted: \n");
			scanf("%d", &key); //reads in key
			printf("this is the key: %d\n",key );

			printf("This is your ciphertext: \n");
			for(i = 0 ; i <= strlen(userMessage) -1; i++){ // loops over every byte in plaintext

			// calls skipx to encrypt the byte, calls rotr to update key, prints resulting ciphertext
				updatedKey = rotr(key);
				tempResult = skipx(userMessage[i], updatedKey); 
				printf("%d ",tempResult);
			}
			printf("\nEND");
			break;

		case 2:
			printf("Enter ciphertext to be Decrypted: \n");

			while(scanf("%d",&input) != -1 && input != -1){ //reads in ciphertext until -1 is input
				encryptedArray[size++] = input;
			}
			printf("Enter an integer key for your message to be decrypted: \n");
			scanf("%d", &key); //reads in key

			printf("This is your plaintext: \n");

			for (i = 0 ; i < size ; i++ ){ //loops over every byte in ciphertext
				// %c prints the corresponding ASCII value of the decrypted value ofter skipx returns
				updatedKey = rotr(key);
				printf("%c",skipx(encryptedArray[i],updatedKey)); // calls skipx to decrypt the byte, calls rotr to update the key
				printf("\n");
			}

			break;

		default: // if user selected neither 1 or 2, this case is called and the function just breaks

			break;
}

  return 0;

}
