#include <iostream>
#include <fstream>
#include <map>
#pragma once
class Config{
	std::string maps_directory;
	std::string default_map;
	std::map <std::string, std::string> settings;
public:
	Config(std::string);
	~Config();
	std::string *get_config_var(std::string);	//Disconnects one string to two with following syntax: input -> [sample_text "some_value"] output -> [0] = "sample_text"; [1] = "some_value"
	void foreach_settings();
};