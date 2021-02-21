#include <iostream>
#include <string>
#include "Stack.hpp"

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    
    short option;
    std::string word;
    Stack<std::string> stack;
    cout << "Program testujący stos.\n";
    do
    {
        cout << "1 - wyczyść stos\n";
        cout << "2 - sprawdź czy stos jest pusty\n";
        cout << "3 - sprawdź ilość elementów\n";
        cout << "4 - dodaj element\n";
        cout << "5 - zwróć element ze szczytu\n";
        cout << "6 - usuń element\n";
        cout << "7 - wydrukuj stos\n";
        cout << "8 - zakończ\n";
        cin >> option;
        switch (option)
        {
            case 1:
                stack.clear();
                break;
            case 2:
                cout << (stack.is_empty() ? "Jest pusty." : "Nie jest pusty.") << endl;
                break;
            case 3:
                cout << stack.size() << " elementów.\n";
                break;
            case 4:
                cout << "Słowo: ";
                cin >> word;
                stack.push(word);
                break;
            case 5:
                try
                {
                    word = stack.top();
                }
                catch (Stack<std::string>::NoElement)
                {
                    cout << "Stos jest pusty.\n";
                    break;
                }
                cout << word << endl;
                break;
            case 6:
                try
                {
                    stack.pop();
                }
                catch (Stack<std::string>::NoElement)
                {
                    cout << "Stos jest pusty.\n";
                }
                break;
            case 7:
                stack.print();
                break;
            case 8:
                return 0;
            default:
                cout << "Niewłaściwa opcja.\n";
        }
    }
    while (true);
}
