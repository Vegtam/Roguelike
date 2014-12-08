#ifndef CREDITSVIEW_HPP_
#define CREDITSVIEW_HPP_

#include <vector>
#include <string>
#include <allegro5/allegro.h>

#include "Displayable.hpp"
#include "View.hpp"
#include "Font.hpp"
#include "TextPane.hpp"
#include "ResourceSet.hpp"
#include "Model.hpp"

class CreditsView : public View
{
private:
	TextPane credits;
	std::vector<Displayable*> drawList;
	DefinedViews handleKeyPress(ALLEGRO_EVENT* ev);
public:
	CreditsView():drawList(){};
	CreditsView(Model* md, ResourceSet<Font>* fs):View(md, fs, NULL, NULL),drawList(){};
	bool init();
	virtual ~CreditsView(){/*drawlist and parent destructor get called automatically*/};
	virtual DefinedViews handleEvent(ALLEGRO_EVENT* ev);
	virtual std::vector<Displayable*>& draw();
};

#endif