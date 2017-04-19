#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <vector>

int size = 3;
int checkCount = 0;

void printSquare(std::vector<int> square){
	std::cout << square[0] << " | " << square[1] << " | " << square[2] << "\n";
	std::cout << square[size] << " | " << square[size+1] << " | " << square[size+2] << "\n";
	std::cout << square[2*size] << " | " << square[2*size+1] << " | " << square[2*size+2] << "\n";
	
	std::cout << "Sum = " << square[0] + square[1] + square[2] << "\n";
}

bool verify(std::vector<int> square){
	bool horizontal = false, vertical = false, diagonal = false;
	int sum = square[0] + square[1] + square[2];
	
	if(square[size] + square[size+1] + square[size+2] == sum){//horizontal
		if(square[2*size] + square[2*size+1] + square[2*size+2] == sum){
			horizontal = true;
		}
	}
	
	if(square[0] + square[size] + square[size*2] == sum){//vertical
		if(square[1] + square[size+1] + square[size*2+1] == sum){
			if(square[2] + square[size+2] + square[size*2+2] == sum){
				vertical = true;
			}
		}
	}
	
	if(square[0] + square[size+1] + square[2*size+2] == sum){//diagonal
		if(square[size-1] + square[size+1] + square[size*2] == sum){
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
	srand (time(NULL));
	
	std::vector<int> square;
	for(int i = 0; i < 9; i++){
		square.push_back(rand()%10+1);
	}
	while(verify(square) == 0){
		square.clear();
		while(square.size() < 9){
			int num = rand() % 10 + 1;
			bool inSquare = false;
			for(int n = 0; n < square.size(); n++){
				if(square[n] == num){
					inSquare = true;
				}
			}
			if(!inSquare){
				square.push_back(num);
			}
		}
	}
	
	printSquare(square);
	
	return 0;
}