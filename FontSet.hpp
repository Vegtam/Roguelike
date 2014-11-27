#ifndef FONTSET_HPP_
#define FONTSET_HPP_

#include <string>
#include <map>
#include "Font.hpp"

class FontSet
{
private:
	ALLEGRO_PATH* directory;
	std::map<std::string, Font> fonts;
public:
	FontSet() = delete;
	FontSet(std::string);
	virtual ~FontSet();
	Font& getFont(std::string);
};

#endif