#include <iostream>
#include <string>

int main()
{
    std::string sentence, searchedLetters = "aeiou";
    int numOfSearchedLetters = 0;
    getline(std::cin, sentence);
    for(int i = 0; i < sentence.length(); i++)//felbontom a mondatot karakterjeire
        for(int j=0; j <= searchedLetters.length(); j++)//a mag�nhangz�kat is veszem bet�nk�nt
            if(tolower(sentence[i]) == searchedLetters[j])//a mondat minden bet�j�t �sszehasonl�tom minden mag�nhangz�val
            {
                numOfSearchedLetters++;
                break; //ha egyez�st tal�ltunk akkor kit�rhet�nk a m�sodik ciklusb�l mert a searchedLetters elemei nem ism�tl�dnek
            }
    std::cout << numOfSearchedLetters;
    return 0;
}
