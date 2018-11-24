#ifndef CYPHER_ABSTRACT_BASE_CLASS
#define CYPHER_ABSTRACT_BASE_CLASS

#include<string>
#include"CipherMode.hpp"

/**
 * \file Cipher.hpp
 * \brief Contains the declarations of a purely abstract base class for use on general ciphers
 */

/**
 * \class Cipher
 * \brief pABC for a generic cipher
 */ 
class Cipher{
	public:
		//Default stuff requried for the pABC
		Cipher () = default;
		Cipher (const Cipher& rhs) = default;
		Cipher (Cipher&& rhs) = default;
		Cipher& operator=(const Cipher& rhs) = default;
		Cipher& operator=(Cipher&& rhs) = default;
		virtual ~Cipher() = default;

		/**
 		 * Apply a generic Cipher
 		 *
 		 * \return the ciphered text
 		 */
		virtual std::string applyCipher( const std::string& input, const CipherMode mode) const = 0;
};

#endif
