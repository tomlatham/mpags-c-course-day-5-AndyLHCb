//! Unit Tests for MPAGSCipher Cipher pABC
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"

#include "CipherMode.hpp"
#include "Cipher.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include "PlayfairCipher.hpp"
#include "CipherFactory.hpp"

bool testCipher( const Cipher& cipher,
								 const CipherMode mode,
								 const std::string& inputText,
								 const std::string& expectedOutput)
{	
	std::string output = cipher.applyCipher(inputText, mode);
	return output == expectedOutput;
}

TEST_CASE("Cipher Inheretance Caesar","[Caesar]"){
	auto caesar = cipherFactory( CipherType::Caesar , "1" );
	
	REQUIRE(testCipher( *caesar,
										CipherMode::Encrypt,
										"ABCDWXYZ",
										"BCDEXYZA"));

  REQUIRE(testCipher( *caesar,
										CipherMode::Decrypt,
										"BCDEXYZA",
										"ABCDWXYZ"));
}

TEST_CASE("Cipher Inheretance Playfair","[Playfair]"){
	auto playfair = cipherFactory( CipherType::Playfair, "TEST" );

	REQUIRE(testCipher(*playfair,
										CipherMode::Encrypt,
										"THISISATESTOFTHEPLAYFAIRCIPHER",
										"BCLTLTBESACVCSDBQKGAGSMOIOUDAP"));

	REQUIRE(testCipher(*playfair,
										CipherMode::Decrypt,
										"BCLTLTBESACVCSDBQKGAGSMOIOUDAP",
										"THISISATESTOFTHEPLAYFAIRCIPHER"));
}

TEST_CASE("Cipher Inheretance Vigenere","[Vigenere]"){
	auto vigenere = cipherFactory( CipherType::Vigenere , "SOMELOOP" );

	REQUIRE(testCipher(*vigenere,
										CipherMode::Encrypt,
										"WAFFLEMEISTERISBACKOPEN",
										"OORJWSATAGFICWGQSQWSASB"));

	REQUIRE(testCipher(*vigenere,
										CipherMode::Decrypt,
										"OORJWSATAGFICWGQSQWSASB",
										"WAFFLEMEISTERISBACKOPEN"));
}
