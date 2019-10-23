#include "Cipher.cpp"
#include <iostream>
#include <string>

using namespace std;



string encrypt_message(string message, int setting)
{
	char alphabet_arr[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	char* alphabet = alphabet_arr;
	
	

	if (message.empty() == true) {
		return "Invalid message!";
	}
	else if (setting == 0) {
		return "You haven't selected a setting";
	}

	for (int t = 0; t < message.size(); t++) {
		for (int i = 0; i < 26; i++) {

			if (isspace(message[t])) break;

			if (message[t] == alphabet[i]) {
				message[t] = alphabet[i + setting];
				break;
			}
			if (i == 25) i = 0;
		}
	}

	return message;
}

// Test
int main() {
	
	string test_message = "attack";

	cout <<encrypt_message(test_message,5) << endl; // Expected output fyyfhp
	return 0;
}