//sg
#include <map>
#include <iostream>
#include <algorithm>
#include <cstdio>
typedef std::map<std::string, int> Str2Int;
typedef std::map<std::string, std::string> Str2Str;
Str2Int chef2Count, country2Count;
Str2Str chef2Country;
int main()
{
    int numChefs, numMails;
    char buff[11], buff2[11];
    scanf("%d%d", &numChefs, &numMails);
    std::string chefName, countryName;
    while(numChefs--) {
        //std::cin >> chefName;
        //std::cin >> countryName;
        scanf("%s%s", buff, buff2);
        chefName = buff;
        countryName = buff2;
        chef2Country[chefName] = countryName;
        country2Count[countryName] = 0;
        chef2Count[chefName] = 0;
    }
    while(numMails--) {
        //std::cin >> chefName;
        scanf("%s", buff);
        chefName = buff;
        chef2Count[chefName]++;
        country2Count[chef2Country[chefName]]++;
    }

    int maxCount = -1;
    std::string maxCountChef;
    for(Str2Int::iterator x= chef2Count.begin(); x != chef2Count.end(); x++) {
        if(x->second > maxCount) {
            maxCount = x->second;
            maxCountChef = x->first;
        }
    }

    maxCount = -1;
    std::string maxCountCountry;
    for(Str2Int::iterator x= country2Count.begin(); x != country2Count.end(); x++) {
        if(x->second > maxCount) {
            maxCount = x->second;
            maxCountCountry = x->first;
        }
    }
    //Str2Int:: iterator maxChef = std::max_element(chef2Count.begin(), chef2Count.end());
    //Str2Int::iterator maxCountry = std::max_element(country2Count.begin(), country2Count.end());
    //std::cout << maxCountCountry.c_str() << "\n";
    //std::cout << maxCountChef.c_str() << "\n";
    printf("%s\n%s\n", maxCountCountry.c_str(), maxCountChef.c_str());
    return 0;
}
