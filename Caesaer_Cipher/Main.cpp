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
	char alphabet_arr[52] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
	for (int t = 0; t < message.size(); t++) {
		for (int i = 0; i < 52; i++) {

			if (message[t] == alphabet_arr[i]) {
				if (decrypt)
					message[t] = alphabet_arr[i - setting];
				else if (!decrypt)
					message[t] = alphabet_arr[i + setting];
				/*else 
					message[t] = message[t];*/
				break;
			}
			if (i == 51) i = 0;
		}
	}
	return message;
}

bool is_decrypt(int choice) {
	// 
	if (choice == 1) {
		return true;
	}
	else {
		return false;
	}
}

string convertToString(char* a, int size)
{
	int i;
	string s = "";
	for (i = 0; i < size; i++) {
		s = s + a[i];
	}
	return s;
}

void start() {

	int choice = 0;
	int setting = 1;
	string message;
	cout << "Do you want to encrypt or decrypt a message? (0 = Encrypt, 1 = Decrypt)" << endl;
	cin >> choice;
	
	bool decrypt = is_decrypt(choice);

	if (decrypt){
		cout << "Enter a message to decrypt" << endl;
	}
	else {
		cout << "Enter a message to encrypt" << endl;
	}

	cin >> message;

	cout << "Choose an integer setting" << endl;

	cin >> setting;

	string result = Caesaer_Cipher(message, setting, decrypt);

	cout <<  result << endl;

}

int Test() {
	
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

int main() {

	start();
	
	char run_again;

	cout << "Would you like to encrypt or decrypt another message? (y/n)" << endl;
	cin >> run_again;

	if (run_again == 'y') {
		start();
	}
	
	return 0;
}