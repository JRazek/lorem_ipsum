#include "./../headers/Configurable.h"
#include <iostream>
#include <map>

	Configurable::Configurable(){
		
	}
	Configurable::~Configurable(){

	}
	std::string* Configurable::get_config_var(std::string str){
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
	bool Configurable::good(){
		return isOK;
	}
	bool Configurable::arr_str_found(std::string *tab, std::string str, int tab_size){
		for(int i = 0; i < tab_size; i++){
			if(tab[i] == str){
				return 1;
			}
		}
		return 0;
	}