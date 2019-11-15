#pragma once
#include <iostream>
class Configurable{
	std::string possible_config_settings[2]{
		"maps_directory", "default_map"
	};
	std::string possible_map_settings[2]{
		"sizex", "sizey"
	};
	public:
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
	bool isOK(){
		//kurwa nie mam pomyslu jak sprawdzac czy wszystkie podano wartosci i zeby to dzialalo dla kazdej klasy dziedzicznej japierdole
	}
};