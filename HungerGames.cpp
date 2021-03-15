#include <iostream>
#include <iomanip>
#include <vector>
#include <array>
#include <random>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include "characterdata.h"
int main()
{
int how_many_names;
std::cout << "\033[1;37m" << "How many names do you want? Also I suggest at least 25\n";
std::cin >> how_many_names;
std::vector<Person> peoples(how_many_names);
std::cout << "What are the names of the characters?\n";
for(int count = 0; count != how_many_names; count++)
{
std::cin >> peoples.at(count).name;
}
std::cout << "What are the genders of the characters?(f)emale or (m)ale:\n";
for(int count = 0; count != how_many_names; count++)
{
std::cout << peoples.at(count).name << ": ";
std::getline(std::cin, peoples.at(count).gender);
}
double a;//probability for characters to kill each other
double b;//probability for characters to get killed from some outside force or themselves
std::string a_string;
std::cout << "Would you want the game small, medium, or large\n";
//this changes probability that a certain sentence will execute
while((a_string != "small") ^ (a_string != "medium") ^ (a_string != "large"))
{
std::cout << "Please enter a valid game size: \n";
std::cin >> a_string;
}
if(a_string == "small")
{
a = 1.0;
}
else if(a_string == "medium")
{
a = 0.5;
}
else if(a_string == "large")
{
a = 0.01;//change to 0.1 if problems
}
std::discrete_distribution<int> BloodBathProb {2.7,2.7,a,2.7,2.7,2.7,2.7,2.7,2.7,2.7,2.7,2.7,2.7,2.7,2.7,2.7,2.7,2.7,a,a,2.7,2.7,2.7,2.7,2.7,2.7,2.7,a,a,a,2.7,a,2.7,2.7,a,a,2.7,a};//this is proabaility for each event to happen
std::discrete_distribution<int> DayTimeProb {2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7, 2.7};
//std::uniform_int_distribution<> how_many_deaths_per_event{ 0, how_many_names};
int how_many_dead = 0;
std::cout << "\033[1;31m" << R"(╭━━━━┳╮╱╱╱╱╱╭━━╮╭╮╱╱╱╱╱╱╱╱╭┳╮╱╱╱╱╭╮╭╮
┃╭╮╭╮┃┃╱╱╱╱╱┃╭╮┃┃┃╱╱╱╱╱╱╱╱┃┃┃╱╱╱╭╯╰┫┃
╰╯┃┃╰┫╰━┳━━╮┃╰╯╰┫┃╭━━┳━━┳━╯┃╰━┳━┻╮╭┫╰━╮   
╱╱┃┃╱┃╭╮┃┃━┫┃╭━╮┃┃┃╭╮┃╭╮┃╭╮┃╭╮┃╭╮┃┃┃╭╮┃   
╱╱┃┃╱┃┃┃┃┃━┫┃╰━╯┃╰┫╰╯┃╰╯┃╰╯┃╰╯┃╭╮┃╰┫┃┃┃ 
╱╱╰╯╱╰╯╰┻━━╯╰━━━┻━┻━━┻━━┻━━┻━━┻╯╰┻━┻╯╰╯
)" << "\033[1;37m";
std::cout << "As the tributes stand on their podiums, the horn sounds.\n";
while(how_many_dead != how_many_names/2)
{
switch(BloodBathProb(mersenne))
{
case 0:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << "\033[1;37m runs away from the cornucopia.\n";	
}
break;
case 1:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << "\033[1;37m finds a backpack full of camping equipment.\n";
}
break;
case 2:
{
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << "\033[1;37m scares " << "\033[1;31m" << peoples[capture_rand2].name << "\033[1;37m from the cornucopia.\n";
}
break;
case 3:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
//this checks if they are killing themself
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << "\033[1;37m shoots an arrow into " << "\033[1;31m" << peoples[capture_rand2].name << "\033[1;37m's head.\n";
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
++how_many_dead;
}
break;
case 4:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mclutches a first aid kit and runs away.\n";
}
break;
case 5:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mgrabs a backpack, not realizing its empty.\n";
}
break;
case 6:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name <<  " \033[1;37mfinds a bow, some arrows, and a quiver.\n";
}
break;
case 7:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mgrabs a shield leaning on the cornucopia.\n";
}
break;
case 8:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mgrabs a shovel.\n";
}
break;
case 9:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mbreaks \033[1;31m" << peoples[capture_rand2].name << "\033[1;37m's nose for a basket of bread.\n";
}
break;
case 10:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mreceives a trident from inside the cornucopia.\n";
}
break;
case 11:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mgrabs a jar of fishing bait while \033[1;31m" << peoples[capture_rand2].name << " \033[1;37mgets fishing gear.\n";
}
break;
case 12:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37msnaches a pair of sais.\n";
}
break;
case 13:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mfinds a canteen full of water.\n";
}
break;
case 14:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mgrabs a sword.\n";
}
break;
case 15:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mand\033[1;31m " << peoples[capture_rand2].name << " \033[1;37mfight for a bag \033[1;31m" << peoples[capture_rand2].name << " \033[1;37mgives up and retreats.\n";
}
break;
case 16:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mgathers as much food as ";
if(peoples[capture_rand].gender == "f")
{
std::cout << "she can\n";
}
else if(peoples[capture_rand].gender == "m")
{
std::cout << "he can\n";
}
}
break;
case 17:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mstays at the cornucopia for resources.\n";
}
break;
case 18:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mfinds a bag full of explosives.\n";
}
break;
case 19:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mstabs\033[1;31m " << peoples[capture_rand2].name << " \033[1;37mwith a tree branch.\n";
peoples[capture_rand].how_many_kills += 1;
++how_many_dead;
}
break;
case 20:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mcaches\033[1;31m " << peoples[capture_rand2].name << " \033[1;37moff guard and kills ";
if(peoples[capture_rand2].gender == "f")
  {
  std::cout << "her\n";
  }
  else if(peoples[capture_rand].gender == "m")
  {
  std::cout << "him\n";
  }
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
++how_many_dead;
}
break;
case 21:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mruns away with a lighter and some rope.\n";
}
break;
case 22:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mand\033[1;31m " << peoples[capture_rand2].name << " \033[1;37mfight for a bag.\033[1;31m" << peoples[capture_rand2].name << " \033[1;37mstrangles\033[1;31m " << peoples[capture_rand].name << " \033[1;37mwith the straps and runs.\n";
}
break;
case 23:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37msnaches a bottle of alcohol and a rag.\n";  
}
break;
case 24:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mruns away with a lighter and some rope.\n";
}
break;
case 25:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mtakes a sickle from inside the cornucopia.\n";
}
break;
case 26:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mgrabs a backpack and retreats.\n";
}
break;
case 27:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mdecapitates\033[1;31m " << peoples[capture_rand2].name << "\033[1;37m with a sword.\n";
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
++how_many_dead;
}
break;
case 28:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mstrangles\033[1;31m " << peoples[capture_rand2].name << "\033[1;37m after engaging in a fist fight.\n";
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
++how_many_dead;
}
break;
case 29:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mstabs\033[1;31m " << peoples[capture_rand2].name << " \033[1;37min the back with a trident.\n";
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
++how_many_dead;
}
break;
case 30:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mtakes a spear from inside the cornucopia.\n";
}
break;
case 31:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mstrangles\033[1;31m " << peoples[capture_rand2].name << " \033[1;37mwith a rope.\n";
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
++how_many_dead;
}
break;
case 32:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << "\033[1;37m, \033[1;31m" << peoples[capture_rand2].name << "\033[1;37m and\033[1;31m " << peoples[capture_rand3].name << "\033[1;37m work together to get as many supplies as possible.\n";
}
break;
case 33:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mruns into the cornucopia and hides.\n";
}
break;
case 34:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mseverely injures\033[1;31m " << peoples[capture_rand2].name << " \033[1;37mand leaves ";
if(peoples[capture_rand2].gender == "f")
    {
    std::cout << "her to die\n";
    }
    else if(peoples[capture_rand].gender == "m")
    {
    std::cout << "him to die\n";
    }
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
++how_many_dead;  
}
break;
case 35:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
 int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
 checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37moverpowers\033[1;31m " << peoples[capture_rand2].name << "\033[1;37m killing";
if(peoples[capture_rand2].gender == "f")
      {
      std::cout << "her\n";
      }
      else if(peoples[capture_rand].gender == "m")
      {
      std::cout << "him\n";
      }
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
++how_many_dead;    
}
break;
case 36:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand4{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << "\033[1;31m" << peoples[capture_rand].name << "\033[1;37m, \033[1;31m" << peoples[capture_rand2].name << "\033[1;37m, \033[1;31m" << peoples[capture_rand3].name << "\033[1;37m, and \033[1;31m" << peoples[capture_rand4].name << " \033[1;37mshare everything they gathered before running.\n";
}
break;
case 37:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << "\033[1;31m" << peoples[capture_rand].name << " \033[1;37mand \033[1;31m" << peoples[capture_rand2].name << " \033[1;37mwork together to drown \033[1;31m" << peoples[capture_rand3].name << '\n';
//put break statements for this switch statement or fallthrough
peoples.at(capture_rand3).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
peoples.at(capture_rand2).how_many_kills += 1;
++how_many_dead;
}
}
}
std::cout << "\033[1;31m" << R"(╭━━━╮╱╱╱╱╱╱╱╭━━━╮
╰╮╭╮┃╱╱╱╱╱╱╱┃╭━╮┃
╱┃┃┃┣━━┳╮╱╭╮┃┃╱┃┣━╮╭━━╮
╱┃┃┃┃╭╮┃┃╱┃┃┃┃╱┃┃╭╮┫┃━┫
╭╯╰╯┃╭╮┃╰━╯┃┃╰━╯┃┃┃┃┃━┫
╰━━━┻╯╰┻━╮╭╯╰━━━┻╯╰┻━━╯
╱╱╱╱╱╱╱╭━╯┃
╱╱╱╱╱╱╱╰━━╯ 
)" << "\033[1;37m";
while(how_many_dead != how_many_names)
{
switch(DayTimeProb(mersenne))
{
case 0:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples[capture_rand].name << " and " << peoples[capture_rand2].name << " pair up to hunt down " << peoples[capture_rand3].name << " but they cannot find them.\n";
}
break;
case 1:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples[capture_rand].name << " and " << peoples[capture_rand2].name << " pair up to hunt down " << peoples[capture_rand3].name
<< " who they successfully find and kill.\n";
peoples.at(capture_rand3).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 1;
peoples.at(capture_rand2).how_many_kills += 1;
++how_many_dead;
}
break;
case 2:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " hunts down and kills " << peoples.at(capture_rand2).name << " and " << peoples.at(capture_rand3).name << " at the same time.\n";
peoples.at(capture_rand2).dead_or_alive = false;
peoples.at(capture_rand3).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 2;
++how_many_dead;
}
break;
case 3:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " hides from " << peoples.at(capture_rand2).name << " and " << peoples.at(capture_rand3).name << " in a river.\n";
}
break;
case 4:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << peoples.at(capture_rand).name << " picks berries.\n";
}
break;
case 5:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " picks berries and gives some to " << peoples.at(capture_rand2).name << "." << '\n';
}
break;
case 6:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << peoples.at(capture_rand).name << " hides in a tree, waiting to ambush someone.\n";
}
break;
case 7:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " and " << peoples.at(capture_rand2).name << " pair up to hunt down " << peoples.at(capture_rand3).name << " but " << peoples.at(capture_rand3).name << " ambushes and kills both of them\n";
peoples.at(capture_rand).dead_or_alive = false;
peoples.at(capture_rand2).dead_or_alive;
how_many_dead += 2;
peoples.at(capture_rand3).how_many_kills += 2;
}
break;
case 8:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << peoples.at(capture_rand).name << " tries to rig a bomb to go off, but is unsuccessful.\n";
}
break;
case 9:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << peoples.at(capture_rand).name << " accidentally detonates a bomb that they were trying to arm.\n";
peoples.at(capture_rand).dead_or_alive = false;
++how_many_dead;
}
break;
case 10:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " hides from " << peoples.at(capture_rand2).name << " and " << peoples.at(capture_rand3).name << " in a river, but is found out and killed\n";
peoples.at(capture_rand).dead_or_alive = false;
peoples.at(capture_rand2).how_many_kills += 1;
peoples.at(capture_rand3).how_many_kills += 1;
++how_many_dead;
}
break;
case 11:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " tries to ambush " << peoples.at(capture_rand2).name << " from a tree, but they slip and break their neck instead.\n";
peoples.at(capture_rand).dead_or_alive = false;
++how_many_dead;
}
break;
case 12:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand4{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << peoples.at(capture_rand).name << ", " << peoples.at(capture_rand2).name << ", and " << peoples.at(capture_rand3).name << " all hide from " << peoples.at(capture_rand4).name << " who is trying to hunt all of them down.\n";
}
break;
case 13:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " and " << peoples.at(capture_rand2).name << " pair up to hunt down " << peoples.at(capture_rand3).name << ", but " << peoples.at(capture_rand2).name << " turns on " << peoples.at(capture_rand).name << " and kills them instead. " << peoples.at(capture_rand3).name << " escapes in the mayhem.\n";
peoples.at(capture_rand).dead_or_alive = false;
peoples.at(capture_rand2).how_many_kills += 1;
++how_many_dead;
}
break;
case 14:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " sets of a bomb in " << peoples.at(capture_rand2).name << " and " << peoples.at(capture_rand3).name << "'s camp, killing the two of them\n";
peoples.at(capture_rand2).dead_or_alive = false;	
peoples.at(capture_rand3).dead_or_alive = false;
peoples.at(capture_rand).how_many_kills += 2;
++how_many_dead;
}
break;
case 15:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " hides from " << peoples.at(capture_rand2).name << " in a river, but they die of hypothemia afterwards.\n";
peoples.at(capture_rand).dead_or_alive = false;
++how_many_dead;
}
break;
case 16:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand4{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
std::cout << peoples.at(capture_rand).name << ", " << peoples.at(capture_rand2).name << ", and " << peoples.at(capture_rand3).name << " team up and ambush " << peoples.at(capture_rand4).name << ", who was trying to hunt them all down\n";
peoples.at(capture_rand4).dead_or_alive = false;
++how_many_dead;
peoples.at(capture_rand).how_many_kills += 1;
peoples.at(capture_rand2).how_many_kills += 1;
peoples.at(capture_rand3).how_many_kills += 1;
}
break;
case 17:
{
int capture_rand{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand2{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
int capture_rand3{isPersonDeadOrAlive(peoples, how_many_names, how_many_dead)};
checkIfNpcEqualsSelf(capture_rand, capture_rand2, capture_rand3, peoples, how_many_names, how_many_dead);
std::cout << peoples.at(capture_rand).name << " sets of a bomb in " << peoples.at(capture_rand2).name << " and " << peoples.at(capture_rand3).name << ",s camp but , " << peoples.at(capture_rand2).name << " falls on the bomb, saving " << peoples.at(capture_rand3).name;
}
}
}
for(int count = 0; count < how_many_names; count++)
  {
  std::cout << "\033[1;31m" << peoples.at(count).name << "\033[1;37m: " << peoples.at(count).how_many_kills << "\033[1;37m\n";
  }
//this sort the elements in vector so we can find the winner
std::sort(peoples.begin(), peoples.end(), [](const Person& lhs, const Person& rhs)
{
return lhs.how_many_kills < rhs.how_many_kills;
});
//find who was alive last
//just do how_many_names-1 != how_many_dead for when all the events are done
for(int count = 0; count < how_many_dead; count++)
{
if(peoples.at(count).dead_or_alive == true)
{
std::cout << "The winner is *drum roll, please*, " << peoples.at(count).name << '\n';
}
}
std::cout << "The Npc with the most kills is: \033[1;31m" << peoples.at(how_many_names-1).name << "\033[1;37m And they should be honored for it\n";
}//end of main function
