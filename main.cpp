#include <iostream>
#include "includes.cpp"
const std::string setup_file = "./setup.txt";
int main(){
	Config config(setup_file);
	config.foreach_settings();
	Map map("chuj");
	return 0;
}