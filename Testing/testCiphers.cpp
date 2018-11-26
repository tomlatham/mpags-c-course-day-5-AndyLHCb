//! Unit Tests for MPAGSCipher Cipher pABC
#define CATCH_CONFIG_MAIN
#include <iostream>
#include <memory>
#include <vector>
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

TEST_CASE("Cipher Inheritance Caesar","[Caesar]"){
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

TEST_CASE("Cipher Inheritance Playfair","[Playfair]"){
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

TEST_CASE("Cipher Inheritance Vigenere","[Vigenere]"){
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

TEST_CASE("Cipher collections","[Cipher]"){

  std::vector<std::unique_ptr<Cipher>> ciphers;
  ciphers.push_back( cipherFactory(CipherType::Caesar,  "1") );
  ciphers.push_back( cipherFactory(CipherType::Playfair,"TEST") );
  ciphers.push_back( cipherFactory(CipherType::Vigenere,"SOMELOOP") );

  std::vector<std::string> plainText;
  plainText.push_back("ABCDWXYZ");
  plainText.push_back("THISISATESTOFTHEPLAYFAIRCIPHER");
  plainText.push_back("WAFFLEMEISTERISBACKOPEN");

  std::vector<std::string> cipherText;
  cipherText.push_back("BCDEXYZA");
  cipherText.push_back("BCLTLTBESACVCSDBQKGAGSMOIOUDAP");
  cipherText.push_back("OORJWSATAGFICWGQSQWSASB");

  for ( size_t i{0}; i < ciphers.size(); ++i ) {
    REQUIRE( ciphers[i] );
    REQUIRE( testCipher( *ciphers[i], CipherMode::Encrypt, plainText[i], cipherText[i]) );
    REQUIRE( testCipher( *ciphers[i], CipherMode::Decrypt, cipherText[i], plainText[i]) );
  }
}
