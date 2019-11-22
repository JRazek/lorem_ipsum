#pragma once
#include <iostream>
#include <map>
class Configurable{
protected:
	bool isOK = 1;

	const static int config_config_count = 2;
	std::string possible_config_settings[config_config_count]{
		"maps_directory", "default_map"
	};

	const static int maps_config_count = 2;
	std::string possible_maps_settings[maps_config_count]{
		"sizex", "sizey"
	};

	public:
	Configurable();
	~Configurable();
	std::string* get_config_var(std::string);
	bool good();
	bool arr_str_found(std::string*, std::string, int);
};