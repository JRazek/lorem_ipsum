#pragma once
#include <iostream>
#include <map>
class Configurable{
protected:
	bool isOK = 1;


/////////////////////////////////Config Config///////////////////////////////////////////
	const static int config_config_count = 2;
	std::string possible_config_settings[config_config_count]{
		"maps_directory", "default_map"
	};


/////////////////////////////////Maps Config////////////////////////////////////////////
	const static int maps_config_count = 2;
	std::string possible_maps_settings[maps_config_count]{
		"sizex", "sizey"
	};//w ten sposob ukladaj dla nastepnej klasy wymagane wartosci do konfiguracji



	Configurable();//not usable
	~Configurable();//not usable
	public:
	std::string* get_config_var(std::string);//getting variable from config, for example: maps_directory "./gamefiles/maps" [returns] ./gamefiles/maps
	bool good();//checking if object is not corrupted
	bool arr_str_found(std::string*, std::string, int);//return 1 if string is found in array
};