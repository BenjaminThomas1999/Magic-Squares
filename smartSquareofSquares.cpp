#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

void printSquare(std::vector<int> square){
	std::cout << square[0] << " | " << square[1] << " | " << square[2] << "\n";
	std::cout << square[3] << " | " << square[4] << " | " << square[5] << "\n";
	std::cout << square[6] << " | " << square[7] << " | " << square[8] << "\n";
	
	std::cout << "Sum = " << square[0] + square[1] + square[2] << "\n";
}
int uniqueAndNoZeros(std::string str){
	char duplicate = '!';
	std::string unsorted = str;
	std::sort(str.begin(), str.end());
	for(int i = 0; i < str.length()-1; i++){
		if(str[i] == str[i+1])
			duplicate = str[i];
	}
	for(int i = str.length()-1; i > 0; i--){
		if(unsorted[i] == '0') return i;
	}
	for(int i = str.length()-1; i > 0; i--){
		if(unsorted[i] == duplicate) return i;
	}
	return -1;
}
bool verify(std::vector<int> square){
	bool horizontal = false, vertical = false, diagonal = false;
	
	for(int i = 0; i < square.size(); i++)
		square[i] = square[i]*square[i];
	
	int sum = square[0] + square[1] + square[2];
	
	if(square[3] + square[3+1] + square[3+2] == sum){//horizontal
		if(square[2*3] + square[2*3+1] + square[2*3+2] == sum){
			horizontal = true;
		}
	}
	
	if(square[0] + square[3] + square[3*2] == sum){//vertical
		if(square[1] + square[3+1] + square[3*2+1] == sum){
			if(square[2] + square[3+2] + square[3*2+2] == sum){
				vertical = true;
			}
		}
	}
	
	if(square[0] + square[3+1] + square[2*3+2] == sum){//diagonal
		if(square[3-1] + square[3+1] + square[3*2] == sum){
			diagonal = true;
		}
	}
	
	if(vertical && horizontal && diagonal){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	std::vector<int> square;
	for(int i = 0; i < 9; i++){
		square.push_back(-1);
	}
	
	for(int i = 123456789; i <= 999999999; i++){
		std::string str = std::to_string(i);
		int errorIndex = uniqueAndNoZeros(str);
		
		if(errorIndex != -1){
			i += pow(10, str.length()-errorIndex-1)-1;
		}else{
			for(int i = 0; i < 9; i++){
				square[i] = str[i] - '0';
			}
			if(verify(square)){
				printSquare(square);
			}
		}
	}
	
	return 0;
}
