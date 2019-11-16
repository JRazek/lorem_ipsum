#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "Configurable.h"
#pragma once
class Config :public Configurable{
	std::map <std::string, std::string> settings;
	std::string *get_config_var(std::string);	//Disconnects one string to two with following syntax: input -> [sample_text "some_value"] output -> [0] = "sample_text"; [1] = "some_value"
public:
	Config(std::string);//constructor, as argument location of setupfile makes isOK to false if error occured
	~Config();//desctructor
	std::string maps_directory();//returning all maps directory
	std::string defualt_map();//returning default map file name without directory
	bool key_exists(std::map <std::string, std::string>, std::string); //checking if key exists in map
	int strpos(std::string, std::string); //checking if string is included in another
	void foreach_settings();//foreaching all settings
};