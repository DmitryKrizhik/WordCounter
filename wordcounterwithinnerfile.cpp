#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>

int main()
{
    std::ofstream fileToParse("innerTextToParse.txt", std::ios::out);
    if (!fileToParse.is_open())
    {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    fileToParse << "The quick brown fox jumps over the lazy dog. This is a test sentence to check the word count. How many words are in this sentence? Let's find out!.\n";
    fileToParse.close();

    std::ifstream infile("innerTextToParse.txt");

    if (!infile.is_open())
    {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    std::map<std::string, int> word_count;
    std::string word;

    while (infile >> word)
    {
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
        ++word_count[word];
    }

    for (const auto& pair : word_count)
    {
        std::cout << pair.first << ": " << pair.second << '\n';
    }

    return 0;
}
