#include <iostream>
#include <string>
#include "List.hpp"

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    
    short option;
    unsigned long position;
    std::string word;
    List<std::string> BiList;
    cout << "Program testujący listę dwukierunkową.\n";
    do
    {
        cout << "1 - wyczyść listę\n";
        cout << "2 - sprawdź czy lista jest pusta\n";
        cout << "3 - sprawdź ilość elementów\n";
        cout << "4 - dodaj element na początek\n";
        cout << "5 - dodaj element na koniec\n";
        cout << "6 - dodaj element na pozycję n\n";
        cout << "7 - zwróć element z początku\n";
        cout << "8 - zwróć element z końca\n";
        cout << "9 - zwróć element z pozycji n\n";
        cout << "10 - usuń element z początku\n";
        cout << "11 - usuń element z końca\n";
        cout << "12 - usuń element na pozycji n\n";
        cout << "13 - znajdź element\n";
        cout << "14 - wydrukuj listę od początku\n";
        cout << "15 - wydrukuj listę od końca\n";
        cout << "16 - zakończ\n";
        cin >> option;
        switch (option)
        {
            case 1:
                BiList.clear();
                break;
            case 2:
                cout << (BiList.is_empty() ? "Jest pusta." : "Nie jest pusta.") << endl;
                break;
            case 3:
                cout << BiList.size() << " elementów.\n";
                break;
            case 4:
                cout << "Słowo: ";
                cin >> word;
                BiList.push_front(word);
                break;
            case 5:
                cout << "Słowo: ";
                cin >> word;
                BiList.push_back(word);
                break;
            case 6:
                cout << "Słowo: ";
                cin >> word;
                cout << "Pozycja: ";
                cin >> position;
                try
                {
                    BiList.insert(word, position);
                }
                catch (List<std::string>::BadPosition)
                {
                    cout << "Niewłaściwa pozycja.\n";
                }
                break;
            case 7:
                try
                {
                    word = BiList.front();
                }
                catch (List<std::string>::NoElement)
                {
                    cout << "Lista jest pusta.\n";
                    break;
                }
                cout << word << endl;
                break;
            case 8:
                try
                {
                    word = BiList.back();
                }
                catch (List<std::string>::NoElement)
                {
                    cout << "Lista jest pusta.\n";
                    break;
                }
                cout << word << endl;
                break;
            case 9:
                cout << "Pozycja: ";
                cin >> position;
                try
                {
                    word = BiList.retrieve(position);
                }
                catch (List<std::string>::NoElement)
                {
                    cout << "Lista jest pusta.\n";
                    break;
                }
                catch (List<std::string>::BadPosition)
                {
                    cout << "Niewłaściwa pozycja.\n";
                    break;
                }
                cout << word << endl;
                break;
            case 10:
                try
                {
                    BiList.pop_front();
                }
                catch (List<std::string>::NoElement)
                {
                    cout << "Lista jest pusta.\n";
                }
                break;
            case 11:
                try
                {
                    BiList.pop_back();
                }
                catch (List<std::string>::NoElement)
                {
                    cout << "Lista jest pusta.\n";
                }
                break;
            case 12:
                cout << "Pozycja: ";
                cin >> position;
                try
                {
                    BiList.remove(position);
                }
                catch (List<std::string>::NoElement)
                {
                    cout << "Lista jest pusta.\n";
                }
                catch (List<std::string>::BadPosition)
                {
                    cout << "Niewłaściwa pozycja.\n";
                }
                break;
            case 13:
                cout << "Słowo: ";
                cin >> word;
                try
                {
                    position = BiList.locate(word);
                }
                catch (List<std::string>::NoElement)
                {
                    cout << "Nie znaleziono.\n";
                    break;
                }
                cout << "Na pozycji " << position << endl;
                break;
            case 14:
                BiList.print_forwards();
                break;
            case 15:
                BiList.print_backwards();
                break;
            case 16:
                return 0;
            default:
                cout << "Niewłaściwa opcja.\n";
        }
    }
    while (true);
}
