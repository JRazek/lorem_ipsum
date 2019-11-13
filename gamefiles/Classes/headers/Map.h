#include <iostream>
class Map{
private:
	std::string directory;
	int size_x;
	int size_y;
public:
	Map(std::string);
	int sizex();
	int sizey();
};