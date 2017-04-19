#include <iostream>
#include <stdlib.h> 
#include <time.h>
#include <vector>

int size = 3;
int checkCount = 0;

unsigned long long sq(unsigned long long n){
	return n*n;
}

void printSquare(std::vector<unsigned long long> square){
	std::cout << square[0] << "² | " << square[1] << "² | " << square[2] << "²\n";
	std::cout << square[size] << "² | " << square[size+1] << "² | " << square[size+2] << "²\n";
	std::cout << square[2*size] << "² | " << square[2*size+1] << "² | " << square[2*size+2] << "²\n";
	
	std::cout << "Sum = " << sq(square[0]) + sq(square[1]) + sq(square[2]) << "\n";
}


bool verify(std::vector<unsigned long long > square, bool verbose = false){
	bool horizontal = false, vertical = false, diagonal = false;
	int sum = sq(square[0]) + sq(square[1]) + sq(square[2]);
	
	if(sq(square[size]) + sq(square[size+1]) + sq(square[size+2]) == sum){//horizontal
		if(sq(square[2*size]) + sq(square[2*size+1]) + sq(square[2*size+2]) == sum){
			horizontal = true;
		}
	}
	
	if(sq(square[0]) + sq(square[size]) + sq(square[size*2]) == sum){//vertical
		if(sq(square[1]) + sq(square[size+1]) + sq(square[size*2+1]) == sum){
			if(sq(square[2]) + sq(square[size+2]) + sq(square[size*2+2]) == sum){
				vertical = true;
			}
		}
	}
	
	if(sq(square[0]) + sq(square[size+1]) + sq(square[2*size+2]) == sum){//diagonal
		if(sq(square[size-1]) + sq(square[size+1]) + sq(square[size*2]) == sum){
			diagonal = true;
		}
	}
	
	if(verbose){
		std::cout << "vertical: " << vertical;
		std::cout << " horizontal: " << horizontal;
		std::cout << " diagonal: " << diagonal;
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
	
	std::vector<unsigned long long> square;
	for(int i = 0; i < 9; i++){
		square.push_back(rand()%10+1);
	}
	std::cout << "Thinking..." << std::endl;
	while(verify(square) == 0){
		square.clear();
		while(square.size() < 9){
			int num = rand() % 100000 + 1;
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
