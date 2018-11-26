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

		/// Default constructor
		Cipher () = default;
		/// Copy constructor
		Cipher (const Cipher& rhs) = default;
		/// Move constructor
		Cipher (Cipher&& rhs) = default;
		/// Copy-assignement operator
		Cipher& operator=(const Cipher& rhs) = default;
		/// Move-assignement operator
		Cipher& operator=(Cipher&& rhs) = default;
		/// Destructor
		virtual ~Cipher() = default;

		/**
 		 * Apply a generic Cipher
 		 *
 		 * \return the ciphered text
 		 */
		virtual std::string applyCipher( const std::string& input, const CipherMode mode) const = 0;
};

#endif
