#ifndef CIPHER_FACTORY_HPP
#define CIPHER_FACTORY_HPP

#include <memory>
#include "Cipher.hpp"
#include "CipherType.hpp"

/**
 * \file CipherFactory.hpp
 * \brief A factory for making smart pointers to pABC
 */

/**
 * \brief A factory function to make any cipher
 * \return A smart pointer to a cipher
 */
std::unique_ptr<Cipher> cipherFactory( const CipherType cipher, const std::string key );

#endif
