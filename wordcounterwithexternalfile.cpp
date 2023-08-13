#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

int main()
{
    std::ifstream fileToParse("ExternalTextToParse.txt"); 
    if (!fileToParse.is_open()) 
    {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    std::map<std::string, int> word_count; 

    std::string words;
    while (fileToParse >> words) 
    {
        words.erase(std::remove_if(words.begin(), words.end(), ::ispunct), words.end());
        std::transform(words.begin(), words.end(), words.begin(), ::tolower);
        ++word_count[words];
    }
    for (const auto& pair : word_count) 
    {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}

