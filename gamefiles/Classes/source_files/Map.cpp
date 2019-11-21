#include "./../headers/Map.h"
Map::Map(std::string directory, int id){
	
	map_id = id;
	files_directory = directory+"/"+map_directory_pattern+std::to_string(map_id);
	map_directory = files_directory+"/"+map_name_pattern;
	config_directory = files_directory+"/"+map_config_pattern;

	std::fstream file(config_directory);
	std::string line;
	if(file.good()){
		int conf_count = 0;
	while(getline(file, line)){
		std::string* str = Configurable::get_config_var(line);
		if(arr_str_found(possible_maps_settings, str[0].c_str(), maps_config_count)){
			conf_count++;
		}
		settings[str[0].c_str()] = str[1];
	}
	if(conf_count != maps_config_count){
		isOK = 0;
	}
		if(settings.count("sizex")){
			size_x = stoi(settings["sizex"]);
		}
		if(settings.count("sizey")){
			size_y = stoi(settings["sizey"]);
		}
		map = new int*[size_x];
		for(int i = 0;i < size_x;i++){
			map[i] = new int[size_y];
		}
	}
	else{
		isOK = 0;
	}
}
Map::~Map(){
	//rozjeb za pomocą delete zmienną map
}
int Map::sizex(){
	return size_x;
}
int Map::sizey(){
	return size_y;
}
void Map::foreach_settings(){
	for (const auto& op : settings) {
    	std::cout << op.first << " is set to " << op.second << std::endl;
	}
}