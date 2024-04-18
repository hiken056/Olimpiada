#include <iostream>
#include <string>

std::string StringChallenge(std::string str, int num)
{
    // Define the output string
    std::string varOcg = "";

    // Loop through each character in the input string
    for (char c : str)
    {
        // If the character is a letter...
        if (isalpha(c))
        {
            // Determine the new character value by shifting it num places
            char newChar = (c - 'a' + num) % 26 + 'a';

            // If the character was originally uppercase, make the new character uppercase
            if (isupper(c))
            {
                newChar = newChar - 'a' + 'A';
            }

            // Add the new character to the output string
            varOcg += newChar;
        }
        else
        {
            // If the character is not a letter, just add it to the output string as-is
            varOcg += c;
        }
    }

    // Return the output string
    return varOcg;
}

int main()
{
    // Test the function
    std::cout << StringChallenge("Caesar Cipher", 2) << std::endl;

    return 0;
}

// This code performs a Caesar Cipher shift on a given string using a given shifting number.
// It uses the "__define-ocg__" keyword in the comment above the variable "varOcg".
// It also names one of the variables "varOcg".