//! Unit Tests for MPAGSCipher Cipher pABC
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

#include "CipherMode.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"

bool testCipher( const Cipher& cipher,
								 const CipherMode mode,
								 const std::string& inputText,
								 const std::string& expectedOutput)
{	
	std::string output = cipher.applyCipher(inputText, mode);
	return output == expectedOutput;
}

TEST_CASE("Cipher Inheretance Caesar","[Caesar]"){
	CaesarCipher caesar(1);
	
	REQUIRE(testCipher(caesar,
										CipherMode::Encrypt,
										"ABCDWXYZ",
										"BCDEXYZA"));
}

TEST_CASE("Cipher Inheretance Playfair","[Playfair]"){
	PlayfairCipher playfair("THEQUICKBROWNFOXJUMPSOVERTHELAZYDOG");

	REQUIRE(testCipher(playfair,
										CipherMode::Encrypt,
										"WAFFLEMEISTERISCLOSED",
										"OZXOXVTSTKMEUKKMRPNMQY"));
}

TEST_CASE("Cipher Inheretance Vigenere","[Vigenere]"){
	VigenereCipher vigenere("SOMELOOP");

	REQUIRE(testCipher(vigenere,
										CipherMode::Encrypt,
										"WAFFLEMEISTERISBACKOPEN",
										"OORJWSATAGFICWGQSQWSASB"));
}
