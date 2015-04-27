#ifndef RESOURCESET_HPP_
#define RESOURCESET_HPP_

#include <string>
#include <map>
#include <allegro5/allegro.h>

template <class T>
class ResourceSet
{
private:
	ALLEGRO_PATH* directory;
	std::map<std::string, T> resources;
public:
	ResourceSet() = delete;
	ResourceSet(std::string);
	virtual ~ResourceSet();
	T& get(std::string);
};

template <class T>
ResourceSet<T>::ResourceSet(std::string dir)
{
	directory = al_create_path_for_directory(dir.c_str());
}

template <class T>
ResourceSet<T>::~ResourceSet()
{
	al_destroy_path(directory);
}

template <class T>
T& ResourceSet<T>::get(std::string name)
{
	if(resources.find(name) == resources.end())
	{
		ALLEGRO_PATH* fullpath = al_create_path(name.c_str());
		if(al_rebase_path(directory, fullpath))
		{
			resources.emplace(name,fullpath);
		}
		//@todo figure out what to do for else case
	}
	return resources[name];
}

#endif