#pragma once
#ifndef ALT_TEXT2_H_INCLUDED 
#define ALT_TEXT2_H_INCLUDED
#include <string>
// The kinds of text objects supported (added Bounded) 
enum class TextType { Plain, Fancy, Fixed, Bounded };
class AltText2 {
	TextType type;
	std::string text;
	std::string left_bracket;
	std::string right_bracket;
	std::string connector;
	size_t length_limit;// Maximum number of characters in the text 
public:
	AltText2(TextType type, const std::string& t);
	AltText2(TextType type, const std::string& t, const std::string& left,
		const std::string& right, const std::string& conn);
	AltText2(TextType type);
	// Constructor for a length-bounded text object
	AltText2(TextType type, const std::string& t, size_t limit);
	std::string get() const;
	void append(const std::string& extra);
};
#endif