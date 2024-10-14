#include <iostream>
#include <string>
#include <cctype> 

using namespace std;


string checkPasswordStrength(const string& password) {
    int lengthCriteria = 0;
    int upperCaseCount = 0;
    int lowerCaseCount = 0;
    int digitCount = 0;
    int specialCharCount = 0;


    if (password.length() >= 8) {
        lengthCriteria++;
    }

   
    for (char c : password) {
        if (isupper(c)) upperCaseCount++;
        else if (islower(c)) lowerCaseCount++;
        else if (isdigit(c)) digitCount++;
        else if (ispunct(c)) specialCharCount++;
    }


    if (lengthCriteria && upperCaseCount > 0 && lowerCaseCount > 0 && digitCount > 0 && specialCharCount > 0) {
        return "Strong Password";
    } else if (lengthCriteria && (upperCaseCount > 0 || lowerCaseCount > 0) && (digitCount > 0 || specialCharCount > 0)) {
        return "Moderate Password";
    } else {
        return "Weak Password";
    }
}


int main() {
    string password;

    cout << "Enter a password to check its strength: ";
    getline(cin, password); 

    string strength = checkPasswordStrength(password);
    cout << "Password Strength: " << strength << endl;

    return 0;
}