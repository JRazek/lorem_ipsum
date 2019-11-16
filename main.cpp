#pragma once
#include <iostream>
#include "includes.cpp"
const std::string setup_file = "./setup.txt";
int main(){
	Config config(setup_file);
	//config.foreach_settings();
	if(config.good()){
		Map map(config.maps_directory());
		//config.foreach_settings();
	}
	else
		std::cout<<"Error";
	return 0;
}