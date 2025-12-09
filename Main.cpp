#include <iostream>//  io stream
#include <cstdlib> //  c std lib
#include <conio.h> //  con io

using namespace std;

int x , y;  //pozycja glowy weza
int fruitX, fruitY; // pozycja owocu
int score; // wynik
const int heightP = 10; //wysokosc planszy
const int widthP = 10; // szerokosc planszy

bool gameOver = true; // informacja o przegranej w grze czy to prawda czy falsz 

//zawartosc biblioteki conio.h
enum eDirection { // napisanie wlasnych zmiennych do sterowania za pomoca enum
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir; // zmienna trzymajac konkretny kiernek, poniewaz waz sie nigdy nie zatrzymuje

void Setup(){
    gameOver = false;
    x = 3; //ustawienie pozycji startowej glowy weza
    y = 3;

    fruitX = rand() % heightP; // losowa pozycja owocu od 0 do 9
    fruitY = rand() % widthP;

    score = 0; // resetowanie wyniku

}

//rysowanie w konsoli
void Draw(){
    //rysowanie gornej scianki, dodalem 2 dlatego ze 10 to jest srodek planszy, bez scian
    for(size_t i = 0; i < widthP + 2; ++i){
        cout << "#";
    }

    //rysowanie srodka
    cout << endl;
    for(size_t i = 0; i < heightP; ++i){  //size_t jest usigned czyli posiada wartosc tylko dodatnia, jendka wraca on do maksymalne wartosci gdy odejmiemy wartosc 0 - 1 = 99999
        cout <<  "#";
        for(size_t j = 0; j < widthP; ++j){
            if(j == x && i == y){
                cout << "O";
            }
            else if(j == fruitX && i == fruitY){
                cout << "F";
            }
            else{
                cout << ".";
            }
        }
        cout << "#" << endl;
    }

    //dolna sciana
    for(size_t i = 0; i < widthP + 2; ++i){
        cout << "#";
    }
}

//funckja wyczytuje klawisze wsad z klawiatury
void Input(){
    if(_kbhit()){ // _kb hit() (keyboard) funkcja sprawdza czy jakikolwiek klawisz jest wcisniety [TRUE/FALSE]
        switch (_getch())    // _get ch() funckja ktora odczytuje pojedynczy znak z konsoli
        {
        case 'a':
            dir = LEFT;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        default:
            break;
        }
    }    
}

//oblsuga ruchu glowy weza
void Logic(){
    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case DOWN:
        y++;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    default:
        break;
    }
}

int main(){

    Setup();
    while(!gameOver){
        Draw();
    }
    return 0;

}