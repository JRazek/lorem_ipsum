#include "./../headers/Config.h"
Config::Config(std::string setup_file){
	std::fstream file(setup_file, std::ios::in);
	std::string line;
	if(!file.good()){
		std::cout<<"\nError while reading file!";
		this->~Config();
	}
	int conf_count = 0;
	while(getline(file, line)){
		std::string* str = Configurable::get_config_var(line);
		if(arr_str_found(possible_config_settings, str[0].c_str(), config_config_count)){
			conf_count++;
		}
		settings[str[0].c_str()] = str[1];
	}
	if(conf_count != config_config_count){
		isOK = 0;
	}
	//sprawdz czy ustawienia oczekiwane sa w setup.txt
}

Config::~Config(){

}

void Config::foreach_settings(){
	for (const auto& op : settings) {
    	std::cout << op.first << " is set to " << op.second << std::endl;
	}
}
std::string Config::maps_directory(){
	return settings["maps_directory"];
}

std::string Config::defualt_map(){
	return settings["defualt_map"];
}

bool Config::key_exists(std::map <std::string, std::string> map, std::string key){
	for (const auto& op : map) {
		if(op.first == key){
			return 1;
		}
	}
	return 0;
}

int Config::strpos(std::string pattern, std::string str){
	int i = 0;
	int patt_count = 0;
	while(i < str.size()){
		int count = 0;
		if(pattern[0] == str[i]){
		int j = 0;
			while(pattern[j] == str[i+j] && j < pattern.size()){
				count ++;
				j++;
			}
			if(count == pattern.size()){
				patt_count++;
			}
			i += j;
		}
		else{
			i++;
		}
	}
	return patt_count;
}