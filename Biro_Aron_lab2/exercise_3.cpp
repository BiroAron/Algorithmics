#include <iostream>
#include <string>

int main()
{
    std::string sentence, searchedLetters = "aeiou";
    int numOfSearchedLetters = 0;
    getline(std::cin, sentence);
    for(int i = 0; i < sentence.length(); i++)//felbontom a mondatot karakterjeire
        for(int j=0; j <= searchedLetters.length(); j++)//a magánhangzókat is veszem betûnként
            if(tolower(sentence[i]) == searchedLetters[j])//a mondat minden betûjét összehasonlítom minden magénhangzóval
            {
                numOfSearchedLetters++;
                break; //ha egyezést találtunk akkor kitörhetünk a második ciklusból mert a searchedLetters elemei nem ismétlõdnek
            }
    std::cout << numOfSearchedLetters;
    return 0;
}
