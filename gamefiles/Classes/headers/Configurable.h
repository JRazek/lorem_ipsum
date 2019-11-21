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
	Configurable(){
	}
	~Configurable(){
	}
	std::string* get_config_var(std::string str){
		bool open = 0;
		std::string *var = new std::string[2];
		for(int i = 0; i < str.size(); i++){
			if(str[i] == ' '){
				i++;
			}
			if(str[i] == '"'){
				open = !open;
				i++;
			}
			if(!open){
				var[0]+=str[i];
			}
			if(open){
				var[1]+=str[i];
			}
		}
		return var;
	}
	bool good(){
		return isOK;
	}
	bool arr_str_found(std::string *tab, std::string str, int tab_size){
		for(int i = 0; i < tab_size; i++){
			if(tab[i] == str){
				return 1;
			}
		}
		return 0;
	}
};