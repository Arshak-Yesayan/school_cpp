#include <iostream>
#include <math.h>
#include <SDL2/SDL.h>

#ifndef TURTLE

using namespace std;

class Turtle {
    public:
        Turtle(int width = 1280, int height = 720, int background_red = 255, int background_green = 255, int background_blue = 255, int red = 0, int green = 0, int blue = 0) {
            screen_width = width; screen_heigt = height;
            pen_red = red; pen_green = green; pen_blue = blue;

            SDL_Init(SDL_INIT_VIDEO);

            win = SDL_CreateWindow("Turtle", 
                                       SDL_WINDOWPOS_CENTERED, 
                                       SDL_WINDOWPOS_CENTERED, 
                                       screen_width, screen_heigt, SDL_WINDOW_SHOWN);

            renderer = SDL_CreateRenderer(win, -1, 0);
            SDL_SetRenderDrawColor(renderer, background_red, background_green, background_blue, 255);
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }

        ~Turtle() {
            SDL_DestroyWindow(win);
            SDL_Quit();
        }

        void quit() {
            SDL_PollEvent(&event);
            if(event.type == SDL_QUIT) {
                atexit(SDL_Quit);
                delete this;
            }
        }

        void wait() {
            while(not_exit) {
                SDL_PollEvent(&event);
                if (event.type == SDL_QUIT) {
                    not_exit = false;
                    break;
                }
            }
        }

        void update() {
            SDL_RenderPresent(renderer);
            quit();
        }

        void show_draw(bool show) {
            show_pen = show;
            quit();
        }

        void forward(double length) {
            double radian = (double)angle / 180 * 3.141592654;
            double new_x = cos(radian) * length + x_pos;
            double new_y = -sin(radian) * length + y_pos;
            if(pen_down) {
                SDL_SetRenderDrawColor(renderer, pen_red, pen_green, pen_blue, 255);
                SDL_RenderDrawLine(renderer, x_pos, y_pos, new_x, new_y);
                if(show_pen) {
                    SDL_RenderPresent(renderer);
                }
            }
            x_pos = new_x;
            y_pos = new_y;
            quit();
        }

        void penup() {
            pen_down = false;
            quit();
        }

        void pendown() {
            pen_down = true;
            quit();
        }

        void left(int l_angle) {
            angle += l_angle;
            angle = (360 + angle % 360) % 360;
            quit();
        }

        void right(int r_angle) {
            angle -= r_angle;
            angle = (360 + angle % 360) % 360;
            quit();
        }

        int get_x() {
            return x_pos;
            quit();
        }

        int get_y() {
            return y_pos;
            quit();
        }

        void set_y(int y) {
            y_pos = y;
            quit();
        }

        void set_x(int x) {
            x_pos = x;
            quit();
        }

        int get_angle() {
            return angle;
            quit();
        }

        void set_angle(int new_angle) {
            angle = new_angle;
            quit();
        }
    private:
        int screen_width = 1280, screen_heigt = 720;
        double x_pos = 0, y_pos = 0;
        int angle = 0;
        int pen_red = 0, pen_green = 0, pen_blue = 0;
        bool pen_down = false, not_exit = true, show_pen = true;
        SDL_Window* win;
        SDL_Event event;
        SDL_Renderer* renderer;
};

#endif