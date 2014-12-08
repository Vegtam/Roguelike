#ifndef TITLEVIEW_HPP_
#define TITLEVIEW_HPP_

#include <vector>
#include <string>
#include <allegro5/allegro.h>

#include "Displayable.hpp"
#include "View.hpp"
#include "Image.hpp"
#include "ResourceSet.hpp"
#include "Model.hpp"

class TitleView : public View
{
private:
	std::string titlescreen = "title.png";
	std::vector<Displayable*> drawList;
	DefinedViews handleKeyPress(ALLEGRO_EVENT* ev);
public:
	TitleView():drawList(){};
	TitleView(Model* md, ResourceSet<Image>* is):View(md, NULL, NULL, is),drawList(){};
	bool init();
	virtual ~TitleView(){/*drawlist and parent destructor get called automatically*/};
	virtual DefinedViews handleEvent(ALLEGRO_EVENT* ev);
	virtual std::vector<Displayable*>& draw();
};

#endif