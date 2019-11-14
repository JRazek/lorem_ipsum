#include <iostream>
#include "includes.cpp"
const std::string setup_file = "./setup.txt";
int main(){
	Config config(setup_file);
	//config.foreach_settings();
	if(config.good()){
		Map map(config.maps_directory());
	}
	else
		std::cout<<"Error";
	//std::cout<<config.maps_directory();
	return 0;
}