#include "./../headers/Config.h"
Config::Config(std::string setup_file){
	settings["maps_directory"] = "0";
	settings["default_map"] = "0";

	std::fstream file(setup_file, std::ios::in);
	std::string line;
	if(!file.good()){
		std::cout<<"\nError while reading file!";
		this->~Config();
	}
	while(getline(file, line)){
		std::string* str = this->get_config_var(line);
	//	std::cout<<settings.find("maps_directory")<<std::endl;
		settings[str[0].c_str()] = str[1];
	}
}

Config::~Config(){
	std::cout<<"\nObject destructed.";
}

void Config::foreach_settings(){
	for (const auto& op : settings) {
    	std::cout << op.first << " is set to " << op.second << std::endl;
	}
}

std::string* Config::get_config_var(std::string str){
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