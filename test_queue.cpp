#include <iostream>
#include <string>
#include "Queue.hpp"

int main()
{
    using std::cout;
    using std::endl;
    using std::cin;
    
    short option;
    std::string word;
    Queue<std::string> queue;
    cout << "Program testujący kolejkę.\n";
    do
    {
        cout << "1 - wyczyść kolejkę\n";
        cout << "2 - sprawdź czy kolejka jest pusta\n";
        cout << "3 - sprawdź ilość elementów\n";
        cout << "4 - dodaj element\n";
        cout << "5 - zwróć element z początku\n";
        cout << "6 - usuń element\n";
        cout << "7 - wydrukuj kolejkę\n";
        cout << "8 - zakończ\n";
        cin >> option;
        switch (option)
        {
            case 1:
                queue.clear();
                break;
            case 2:
                cout << (queue.is_empty() ? "Jest pusta." : "Nie jest pusta.") << endl;
                break;
            case 3:
                cout << queue.size() << " elementów.\n";
                break;
            case 4:
                cout << "Słowo: ";
                cin >> word;
                queue.enqueue(word);
                break;
            case 5:
                try
                {
                    word = queue.front();
                }
                catch (Queue<std::string>::NoElement)
                {
                    cout << "Kolejka jest pusta.\n";
                    break;
                }
                cout << word << endl;
                break;
            case 6:
                try
                {
                    queue.dequeue();
                }
                catch (Queue<std::string>::NoElement)
                {
                    cout << "Kolejka jest pusta.\n";
                }
                break;
            case 7:
                queue.print();
                break;
            case 8:
                return 0;
            default:
                cout << "Niewłaściwa opcja.\n";
        }
    }
    while (true);
}
