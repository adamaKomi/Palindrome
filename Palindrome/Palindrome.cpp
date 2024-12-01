// Palindrome.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <iostream>
#include "Stack.h"

int main()
{ 
    std::string menu = "\n******* PALINDROME *******\n\n1-Verifier une chaine\n0-Quitter\n";
    std::string exp;
    int choix;

    do
    {
        std::cout << menu << std::endl;
        std::cout << ">>";
        std::cin >> choix;
        std::cout << std::endl;

        if (choix == 1)
        {
            std::cout << "Entrer une chaine : " ;
            std::cin >> exp;
            std::cout << std::endl;
            try
            {
                Stack<char> stack;

                if (stack.isPalindrome(exp))
                {
                    std::cout << "La chaine \"" << exp << "\" est un palindrome !!!" << std::endl;
                }
                else
                {
                    std::cout << "La chaine \"" << exp << "\" n'est pas un palindrome !!!" << std::endl;
                }
            }
            catch (const std::exception& e)
            {
                std::cout << "Erreur : " << e.what() << std::endl;
            }
        }
        std::cout << std::endl;

    } while (choix != 0);
    
}
