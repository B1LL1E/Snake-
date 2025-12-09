#include <iostream>

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

    fruitX = 6; // pozycja owocu
    fruitY = 6;

    score = 0; // resetowanie wyniku

}

int main(){

    Setup();
    while(!gameOver){

    }
    return 0;
    
}