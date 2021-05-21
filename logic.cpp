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
void printArr(std::vector<int> arr)
{
	for (size_t i = 0; i < arr.size(); i++)
        {
		std::cout << arr[i];
        }
}

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

void loadFile(std::string fileName, std::vector<std::string> &sentences)
{
        std::ifstream fileSentences;
        fileSentences.open (fileName);
        std::string buffer;
        fileSentences.seekg(0, std::ios::beg);
        while(std::getline(fileSentences, buffer))//do until the end of the file
        {
                if(buffer.size() > 0)
                {
                sentences.push_back(buffer);
                }
        }
        fileSentences.close();
}//works

int getFileWords(std::string fileName, std::vector<std::string> &sentences)
{
	std::ifstream fileSentences;
        fileSentences.open (fileName);
        std::string buffer;
        fileSentences.seekg(0, std::ios::beg);
        std::string words;
        int how_many_sentences;
        while(fileSentences >> words)//do until the end of the file
        {
                sentences.push_back(words);
                ++how_many_sentences;
        }
        fileSentences.close();
        return how_many_sentences;
}

class Person {
        public:
                std::string name;
                char gender;
                bool alive;//flag
                int killcount;
                auto getName(std::vector<Person> mPeople, int mHow_many_people)
                {
                        std::uniform_int_distribution<> rand_index{0, mHow_many_people-1};
                        int index = rand_index(mersenne);

                        while(mPeople.at(index).alive == false)
                        {
                                index = rand_index(mersenne);
                        }
                        return index;
                }//works
};

class Game
{
	public:
		std::string mSentence;
		std::vector<Person> mPeople;
		int mHow_many_dead = 0;
		int mHow_many_people = 0;
		struct Event
		{
    			std::string event_name;
			int rand_event;
    			std::string path;
    			int id;
		};
		std::vector<std::string> eventInfo;
		std::vector<Event> events;
		std::vector<int> m;
		Game()
		{
			system("clear");
			std::vector<std::string> eventInfo;
        		events.resize(getFileWords("events.txt", eventInfo)/4);
			
			int a = 0;
        		for(size_t i = 0; i != eventInfo.size()/4; i++) //eventInfo.size(); i++)
        		{
				events.at(i).rand_event = std::stoi(eventInfo.at(a));
                        	events.at(i).id = i;//std::stoi(eventInfo.at(a+1));
                        	events.at(i).path = eventInfo.at(a+2);
                        	events.at(i).event_name = eventInfo.at(a+3);
                        	a += 4;
        		}

        		std::cout << "How many names do you want? You have to put 25 or more:\n";
			while(true)
			{

				if(!(std::cin >> mHow_many_people))
				{
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Please type in a number.\n";	
				}
				else if(mHow_many_people < 25)
				{
					std::cerr << "Please type a 25 or greater number.\n";
				
				}
				else
				{
					break;
				}

			}

			mPeople.resize(mHow_many_people);
        		char answer = 'n';
        		do
        		{
                		std::cout << "What are the names of the people?\n";
                		
				for(int i = 0; i != mHow_many_people; i++)
                		{
                        		std::cin >> mPeople.at(i).name;
					
					while(mPeople.at(i).name.size() >= 24)
					{
						std::cerr << "Error: You can only have up to 24 characters.\n";
						std::cin >> mPeople.at(i).name;
					}

                        		mPeople.at(i).alive = true;
                		}

                		std::cout << "Are the names what you wanted? (y)es or (n)o\n";
                		std::cin >> answer;

        		} while(answer == 'n');

        		std::cout << "What are the genders of the people?\n";
        		for(int i = 0; i != mHow_many_people; i++)
        		{
                		std::cin >> mPeople.at(i).gender;
        		}
			--mHow_many_people;
		}
		std::string placeholderReplace(std::string sentence)//mHow_many_people
		{
			size_t found = 0;
			int sizeOfName = 0;
			int index = 0;
			std::string name;
			std::vector<int> positions;
			char a;
			while(true)//equals 31
			{
				found = std::distance(sentence.begin(), std::find_if (sentence.begin()+found, sentence.end(), [](auto a) {return a == 'K' || a == 'D' || a == 'N';}));//returns number of characters in a string

				if(found == sentence.size())//works+1
				{
                        		break;
				}
				positions.push_back(found);
				a = sentence.at(found+sizeOfName);
				//if killer
				if(a == 'K')
				{
					index = mPeople.at(0).getName(mPeople, mHow_many_people);
					name = mPeople.at(index).name;
					sentence.replace(found + sizeOfName, 1, name);//-1
                        		++mPeople.at(index).killcount;
                		}
				//if dead
                		else if(a == 'D')
                		{
                        		index = mPeople.at(0).getName(mPeople, mHow_many_people);
                        		name = mPeople.at(index).name;
                        		sentence.replace(found + sizeOfName, 1, name);//sizeOfName*2
                        		mPeople.at(index).alive = false;
                        		++mHow_many_dead;
                		}
				//if nothing
                		else if(a == 'N')
                		{
                        		index = mPeople.at(0).getName(mPeople, mHow_many_people);
                        		name = mPeople.at(index).name;
                        		sentence.replace(found + sizeOfName, 1, name);
                		}
			}
			return sentence;
		}

		void proceed()
		{
			char choice;
          		std::cout << "(P)roceed. or (S)tatus";
          		std::cin >> choice;

			if(choice == 'p')
			{
                		system("clear");
        		}
        		if(choice == 's')
        		{
                	
				system("clear");
				std::cout << "Name                  " << "Kills                  " << "Dead Or Alive";
				for(size_t i = 0; i != mPeople.size(); i++)
                		{
					std::cout << "   \n" << mPeople.at(i).name;

					for(size_t j = 0; j != 24-mPeople.at(i).name.size(); j++)//24 is the character limit in a persons name
                                        {
                                                std::cout << " ";
                                        }
                        		
					std::cout << mPeople.at(i).killcount;
					std::cout << "                        " << ((mPeople.at(i).alive) ? "Alive" : "Dead");
                		}
				std::cout << '\n';
				proceed();
			}
		}

void simulate_game(std::string fileName)
{

        std::vector<std::string> sentences;
        std::string a = "hello D";
        loadFile(fileName, sentences);

        if(sentences.size()-1 < 0)
        {
                std::cerr << "Error: There arent any sentences in the file or the path is invalid.\n";
                exit (EXIT_FAILURE);
        }
	std::uniform_int_distribution<> rand_index{0, static_cast<int>(sentences.size()-1)};
        
	static size_t c = 0;
        static int b = 0;
	b += m.at(c);
	std::cout << b << '\n';
	if(m.at(c) != 0)
        {
        	while(b != mHow_many_dead) //b|| how_many_dead != c)//how_many_people)
        	{
                	std::cout << placeholderReplace(sentences.at(rand_index(mersenne)))<< '\n';
        	}
		proceed();
	}
	if (c != m.size()-2)//-1 because 0 indexed
	{
		++c;
	}
}
void winnerAndKills()
{
	std::sort(mPeople.begin(), mPeople.end(), [](const Person& lhs, const Person& rhs){return lhs.killcount > rhs.killcount;});
        std::cout << "The person with the most kills is: " << mPeople.at(0).name << '\n'
        << "Kills: " << mPeople.at(0).killcount << '\n';

        //outputs the winner.
        for(size_t i = 0; i != mPeople.size(); i++)
        {
                if(mPeople.at(i).alive == true)
                {
                        std::cout << "The winner is: " << mPeople.at(i).name << '\n';
                }
        }

}
void run()
{
	mHow_many_dead = 0;
	std::uniform_int_distribution<> a{10, 20};//how many rounds
	int index = a(mersenne);
     
	m.resize(index);

        numsToEqual(index, mHow_many_people, m);

	while(mHow_many_dead != mHow_many_people)//-1 because we need one alive
	{
	for(size_t i = 0; i != events.size(); i++)
        {
		for(size_t j = 0; j != events.size(); j++)
                {
			if(events.at(i).id == static_cast<int>(j))
                        {
				std::cout << events.at(i).event_name << '\n';
				std::cout << "How_many_people: " << mHow_many_dead << '\n';
				simulate_game(events.at(i).path);//i
                        }
                }
        }

	}
	winnerAndKills();
}
};
