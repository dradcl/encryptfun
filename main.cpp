#include <iostream>
#include "methods.h"

int main()
{
	int end;

	std::cout << caesar_encrypt("karma the kitten", 20) << std::endl;
	std::cout << caesar_decrypt(caesar_encrypt("karma the kitten", 20), 20);

	std::cin >> end;
	return 0;
}