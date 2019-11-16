#pragma once
#include "./../headers/Map.h"
Map::Map(std::string directory){
	std::fstream file(directory+map_name_pattern);
	std::string line;
	if(file.good()){
		while(getline(file, line)){

		}
		size_x = 2;
		size_y = 3;
		map = new int*[size_x];
		for(int i = 0;i < size_x;i++){
			map[i] = new int[size_y];
		}
	}
	else{
		Configurable::isOK = false;
	}
}
int Map::sizex(){
	return size_x;
}
int Map::sizey(){
	return size_y;
}