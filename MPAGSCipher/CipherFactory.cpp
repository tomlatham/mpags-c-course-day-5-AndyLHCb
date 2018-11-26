#include"CipherFactory.hpp"
#include"CaesarCipher.hpp"
#include"PlayfairCipher.hpp"
#include"VigenereCipher.hpp"

std::unique_ptr<Cipher> cipherFactory(const CipherType cipher, const std::string key )
{
	switch(cipher)
	{
		case CipherType::Caesar:
			return std::make_unique<CaesarCipher>( key );

		case CipherType::Playfair:
			return std::make_unique<PlayfairCipher>( key );

		case CipherType::Vigenere:
			return std::make_unique<VigenereCipher>( key );
	}

	//This should never be used and is just a return to make the compiler happy
	return std::unique_ptr<Cipher>();
}

