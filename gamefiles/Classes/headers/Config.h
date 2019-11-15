#include <iostream>
#include <fstream>
#include <map>
#pragma once
class Config{
	std::string possible_settings[3]{
		"maps_directory", "default_map", "test"
	};
	bool isOK;
	std::map <std::string, std::string> settings;
public:
	Config(std::string);//constructor, as argument location of setupfile makes isOK to false if error occured
	~Config();//desctructor
	std::string maps_directory();//returning all maps directory
	std::string defualt_map();//returning default map file name without directory
	std::string *get_config_var(std::string);	//Disconnects one string to two with following syntax: input -> [sample_text "some_value"] output -> [0] = "sample_text"; [1] = "some_value"
	bool key_exists(std::map <std::string, std::string>, std::string); //checking if key exists in map
	int strpos(std::string, std::string); //checking if string is included in another
	bool good();//returnig status of the config *in progress*
	void foreach_settings();//foreaching all settings
};