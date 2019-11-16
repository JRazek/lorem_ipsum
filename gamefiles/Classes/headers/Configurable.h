#pragma once
#include <iostream>
#include <map>
class Configurable{
protected:
	bool isOK;
	std::map <std::string,std::map<std::string, std::string>> settings_options;
	public:
	Configurable(){
		std::string possible_config_settings[]{
			"maps_directory", "default_map"
		};
		std::string possible_map_settings[]{
			"sizex", "sizey"
		};
		//settings_options ["config"] = possible_config_settings;
		//settings_options ["settings"] = possible_map_settings;


		std::cout<<"im here!!!\n";
	}
	~Configurable(){
		std::cout<<"im ded:(\n";
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
		//kurwa nie mam pomyslu jak sprawdzac czy wszystkie podano wartosci i zeby to dzialalo dla kazdej klasy dziedzicznej japierdole
		return 1;
	}
};