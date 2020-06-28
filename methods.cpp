#include <string>
#include <iostream>

char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ' };

int getCharIndex(char letter) // returns the index of the respective letter
{
	for (unsigned int i = 0; i < sizeof(letters); i++)
	{
		if (letters[i] == letter)
		{
			return i;
		}
	}

	return sizeof(letters); // not found or space
}

int adjustBounds(int index, int key, bool decrypt = false) // wraps index around if it exceeds length and returns new index
{
	if (decrypt)
	{
		if ((index - key) < 0)
		{
			return (sizeof(letters) + index) - key;
		}

		return index - key;
	}
	else
	{
		if ((index + key) >= sizeof(letters))
		{
			return (index + key) - sizeof(letters);
		}

		return index + key;
	}
}

std::string caesar_encrypt(std::string message, int key = 1)
{
	for (unsigned int i = 0; i < message.length(); i++)
	{
		int index = getCharIndex(message[i]); // the index of the character in letters array

		message[i] = letters[adjustBounds(index, key)];
	}

	return message;
}

std::string caesar_decrypt(std::string message, int key = 1)
{
	for (unsigned int i = 0; i < message.length(); i++)
	{
		int index = getCharIndex(message[i]);

		message[i] = letters[adjustBounds(index, key, true)];
	}

	return message;
}