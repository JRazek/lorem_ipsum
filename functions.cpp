int strpos(std::string pattern, std::string str){
	int i = 0;
	int patt_count = 0;
	int cykle = 0; //optymalizacja, opcjonalne
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
				std::cout<<i<<" "<<j<<std::endl;
			}
			i += j;
		}
		else{
			i++;
		}
		cykle ++;
	}
	//std::cout<<cykle<<std::endl;
	return patt_count;
}