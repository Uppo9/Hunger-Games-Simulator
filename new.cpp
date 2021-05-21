#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <random>
#include <ctime>
#include <algorithm>
#include <fstream>
#include <regex>
std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };

void numsToEqual(int howManyToEqual, int numberToEqual, std::vector<int> &arr)
{

      // Create an array of size m where
      // every element is initialized to 0
      std::uniform_int_distribution<> rand_num;
      // To make the sum of the final list as ni
      for (int i = 0; i != numberToEqual; i++) {

          // Increment any random element
          // from the array by 1
          arr.at(rand_num(mersenne) % howManyToEqual)++;
          //std::cout << arr.at(i) << '\n';
      }
      // Print the generated list
}

int main()
{
	int b = 10;
	std::vector<int> a(b);

	numsToEqual(b, 25, a);
	for(size_t i = 0; i != a.size(); i++)
	{
		std::cout << a.at(i) << '\n';
	}
}
