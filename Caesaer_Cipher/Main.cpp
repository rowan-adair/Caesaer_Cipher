#include "Cipher.cpp"
#include <iostream>
#include <string>

using namespace std;


bool valid_message(string message, int setting) {
	if (message.empty() == true) {
		return false;
	}
	else if (setting == 0) {
		return false;
	}
	return true;
}


string Caesaer_Cipher(string message, int setting, bool decrypt) {
	if (!valid_message(message, setting)) return "Invalid Parameters";
	char alphabet_arr[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
	for (int t = 0; t < message.size(); t++) {
		for (int i = 0; i < 26; i++) {

			if (isspace(message[t])) break;

			if (message[t] == alphabet_arr[i]) {
				if(decrypt)
					message[t] = alphabet_arr[i - setting];
				else					
					message[t] = alphabet_arr[i + setting];
				break;
			}
			if (i == 25) i = 0;
		}
	}
	return message;
}



// Test
int main() {
	
	string test_encrypt_message = "attack";
	string test_encrypted_message = Caesaer_Cipher(test_encrypt_message, 5, false);
	cout << "Before encryption : " << test_encrypt_message << endl; // Expected output attack
	cout << "After encryption :" << test_encrypted_message << endl; // Expected output fyyfhp

	cout << "------------------------------" << endl;

	string test_decrypt = Caesaer_Cipher(test_encrypted_message, 5, true);

	cout << "Before decryption :" << test_encrypted_message << endl; // Expected output fyyfhp
	cout << "After decryption :" << test_decrypt << endl; // Expected output attack


	return 0;
}