#include "./../headers/Map.h"
Map::Map(std::string directory, std::string id){

	map_id = id;
	files_directory = directory+"/"+map_id;
	map_directory = files_directory+"/"+map_name_pattern;
	config_directory = files_directory+"/"+map_config_pattern;
	std::string line;

	std::fstream config_file(config_directory);
	if(config_file.good()){
		int conf_count = 0;
	while(getline(config_file, line)){
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
		mapa = new char*[size_x];
		for(int i = 0;i < size_x;i++){
			mapa[i] = new char[size_y];
		}
		config_file.close();

	}
	else{
		isOK = 0;
	}
	if(isOK){
		std::fstream map_contains(map_directory);
		int x = 0;
		int y = 0;
		if(map_contains.good()){
			while(getline(map_contains, line)){
				if(line.size() != size_x){
					isOK = 0;
				}
				else{
					for(x = 0; x < line.size(); x++){
						mapa[x][y] = line[x];
					}
					y++;
				}
			}
			if(y != size_y){
				isOK = 0;
			}
		}
		else{
			isOK = 0;
		}
	}
}
Map::~Map(){
	delete mapa;
	mapa = nullptr;
}
int Map::sizex(){
	return size_x;
}
void Map::show_map_debugging(){
	std::cout<<std::endl;
	for(int y = 0; y < size_y; y++){
		for(int x = 0; x < size_x; x++){
			std::cout<<mapa[x][y];
		}
		std::cout<<std::endl;
	}
}
int Map::sizey(){
	return size_y;
}
char **Map::display(){
	return mapa;
}
void Map::foreach_settings(){
	for (const auto& op : settings) {
    	std::cout << op.first << " is set to " << op.second << std::endl;
	}
}