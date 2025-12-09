#include <iostream>
#include <cstdlib>

using namespace std;

int x , y;  //pozycja glowy weza
int fruitX, fruitY; // pozycja owocu
int score; // wynik
const int heightP = 10; //wysokosc planszy
const int widthP = 10; // szerokosc planszy

bool gameOver = true; // informacja o przegranej w grze czy to prawda czy falsz 

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

int main(){

    Setup();
    while(!gameOver){
        Draw();
    }
    return 0;

}