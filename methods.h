#pragma once
#include <string>

std::string caesar_encrypt(std::string message, int key = 1, bool negative = false);

std::string caesar_decrypt(std::string message, int key = 1, bool negative = false);

int getCharIndex(char letter);

int adjustBounds(int index, int key, bool decrypt = false);