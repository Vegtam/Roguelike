#ifndef CHARACTERCREATIONNAMEVIEW_HPP_
#define CHARACTERCREATIONNAMEVIEW_HPP_

#include <vector>
#include <allegro5/allegro.h>

#include "Displayable.hpp"
#include "View.hpp"
#include "Font.hpp"
#include "TextPane.hpp"
#include "TextEntry.hpp"
#include "ResourceSet.hpp"
#include "Model.hpp"

class CharacterCreationNameView: public View 
{
private:
	std::vector<Displayable*> drawList;
	TextPane title;
	TextEntry name;
	TextPane nameLabel;
	/* Only has name label and entry section but may to add more*/
	DefinedViews handleKeyPress(ALLEGRO_EVENT* ev);
public:
	CharacterCreationNameView(){};
	CharacterCreationNameView(Model* md, 
		      ResourceSet<Font>* fs):View(md, fs, NULL, NULL){};
	bool init();
	virtual ~CharacterCreationNameView(){};
	virtual DefinedViews handleEvent(ALLEGRO_EVENT* ev);
	virtual std::vector<Displayable*>& draw();
};
#endif