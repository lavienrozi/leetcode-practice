#include <iostream>
#include <vector>


bool isPalindrome(int x) {
	std::vector<int> intvect;
	int j;
	if (x < 0) {
		return false;
	}
	else {
		for (int i = 0; x > 0; i++) {
			intvect.push_back(x % 10);
			x = x / 10;
			j = i;
			int tmp = intvect[i];
			std::cout << tmp << std::endl;

		}
		for (int i = 0; i <= j; i++) {
			if (intvect[i] != intvect[j]) {
				return false;

			}
			else {
				j--;
			}

		}
		return true;
	}
}

int main() {
	int x = 123443210;
	// bool isPalindrome(x);


	// std::vector<int> intvect;
	// int j;
	// for (int i = 0; x > 0; i++) {
	// 	intvect.push_back(x % 10);
	// 	x = x / 10;
	// 	j = i;
	// 	int tmp = intvect[i];
	// 	std::cout << tmp << std::endl;
	// 	std::cout << "x: " <<x<< std::endl;

	// }
	// for (int i = 0; i <= j; i++) {
	// 	if (intvect[i] != intvect[j]) {
	// 		std::cout << "Non, cheré." << std::endl;
	// 		return 0;

	// 	}
	// 	else {
	// 		j--;
	// 	}

	// }

	// std::cout << "Come on, baby." << std::endl;

	bool foo = isPalindrome(x);
	std::cout << foo << std::endl;

	return 0;

}