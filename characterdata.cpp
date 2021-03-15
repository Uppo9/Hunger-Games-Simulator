#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <ctime>
std::mt19937 mersenne{ static_cast<std::mt19937::result_type>(std::time(nullptr)) };
  class Person//holds all npc data
  {
  public:
  std::string name;
  std::string gender;
  bool dead_or_alive = true;
  int how_many_kills = 0;
  };
  int isPersonDeadOrAlive(std::vector<Person> &peoples, int &how_many_names, int &how_many_dead)
  {
  std::uniform_int_distribution<> rand_index{0, how_many_names-1};//how many names-1 because its a index and indexes start 0
  int capture_rand = rand_index(mersenne);//gives random number to int capture_rand
  while(peoples.at(capture_rand).dead_or_alive != true)//if peoples.at(5).dead_or_alive != true execute bottom statement if index 2.70 = true execute return capture_rand
  {
  capture_rand = rand_index(mersenne);//this reassigns a random number to capture_rand2 for example 2.70
  }
  return capture_rand;
  }
void checkIfNpcEqualsSelf(int &a, int &b, int &c, std::vector<Person> &peoples, int &how_many_names, int how_many_dead)
{
/*
while((a == b) && (b == c))
{
if(how_many_dead == how_many_names)
{
break;
}
else
{
a = isPersonDeadOrAlive(peoples, how_many_names, how_many_dead);
c = isPersonDeadOrAlive(peoples, how_many_names, how_many_dead);
b = isPersonDeadOrAlive(peoples, how_many_names, how_many_dead);
}

}
*/
}
void checkIfNpcEqualsSelf(int &a, int &b, std::vector<Person> &peoples, int &how_many_names, int &how_many_dead)
{
//while(a == b) // do the below until
//{
//if(how_many_dead == 4)
//{
//break;
//}
//else
//{
//a = isPersonDeadOrAlive(peoples, how_many_names, how_many_dead);
//b = isPersonDeadOrAlive(peoples, how_many_names, how_many_dead);
//}
//}
//}
}
