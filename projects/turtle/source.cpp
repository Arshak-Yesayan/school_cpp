#include <iostream>
#include <string>

#include "turtle.hpp"

using namespace std;

int main() {
    int screen_width = 1600, screen_height = 900;

    string axiom = "F-G-G", new_axiom = "";
    int gens = 8, angle = 120;
    double step = 3.5;

    for(int i = 0; i < gens; i++) {
        for(int q = 0; q < axiom.length(); q++) {
            switch(axiom[q]) {
                case 'F':
                    new_axiom += "F-G+F+G-F";
                    break;
                case 'G':
                    new_axiom += "GG";
                    break;
                case '+':
                    new_axiom += '+';
                    break;
                case '-':
                    new_axiom += '-';
                    break;
                default:
                    break;
            }
        }
        axiom = new_axiom;
        new_axiom = "";
    }

    Turtle turtle(screen_width, screen_height, 0, 0, 0, 2550, 255, 0);

    turtle.pendown();
    // turtle.show_draw(false);
    turtle.set_x(352);
    turtle.set_y(screen_height - 50);

    for(int n = 0; n < axiom.length(); n++) {
        switch(axiom[n]) {
            case 'F':
                turtle.forward(step);
                break;
            case 'G':
                turtle.forward(step);
                break;
            case '+':
                turtle.right(angle);
                break;
            case '-':
                turtle.left(angle);
                break;
            default:
                break;
        }
    }
    // turtle.update();

    turtle.wait();

    return 0;
}