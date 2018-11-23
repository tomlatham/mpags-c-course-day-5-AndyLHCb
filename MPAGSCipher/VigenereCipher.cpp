#include"VigenereCipher.hpp"

VigenereCipher::VigenereCipher ( const std::string& key ){
	// Set the given key
	setKey(key);
}

void VigenereCipher::setKey( const std::string& key )
{
	// default key set in the hpp file
	if(key.empty()){return;}
	
  // Store the key
	std::string tempKey;

	// Make sure the key is uppercase
	std::transform(key.begin(),
								 key.end(),
								 std::back_inserter(tempKey),
								 ::toupper
  );

	// Remove non-alphabet characters
	auto iter = std::copy_if(tempKey.begin(),
											 		 tempKey.end(),
													 tempKey.begin(),
													 ::isalpha
	);

	tempKey.erase( iter, tempKey.end() );

	// loop over the key
	for(char c : tempKey)
	{

		// Find the letter position in the alphabet
		size_t letterPos = Alphabet::alphabet.find(c);

		// Create a CaesarCipher using this position as a key
		CaesarCipher cipher( letterPos );
		auto pair{ std::make_pair( c, cipher) };

		// Insert a std::pair of the letter and CaesarCipher into the lookup
		charLookup_.insert( pair );
	}
	std::cout << "KEY:" << tempKey << std::endl;
	key_ = tempKey;
  return;
}

std::string VigenereCipher::applyCipher(const std::string& inputText,
					const CipherMode cipherMode ) const
{
	// For each letter in input:
	std::string outputText{""};
	for(size_t i{0}; i < inputText.length(); ++i)	
	{
		// Find the corresponding letter in the key, 
		// repeating/truncating as required
		char keyLetter = key_[ i % key_.length() ];

		// Find the Caesar cipher from the lookup
		auto cipherIter = charLookup_.find( keyLetter );

		CaesarCipher cipher = cipherIter->second;
		std::string cryptLetter(1,inputText[i]);

		// Run the (de)encryption
		outputText += cipher.applyCipher( cryptLetter, cipherMode );
	}
	return outputText;
}
