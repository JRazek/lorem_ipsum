#include <iostream>
#include "includes.cpp"
const std::string setup_file = "./setup.txt";
int main(){
	Config config(setup_file);
	//config.foreach_settings();
	if(config.good()){
		Map map(config.maps_directory(), 1);
		//config.foreach_settings();
		std::cout<<map.sizex()<<std::endl;
		//map.foreach_settings();
		std::cout<<"config works!!!\n";
	}
	else
		std::cout<<"Error";
	return 0;
}