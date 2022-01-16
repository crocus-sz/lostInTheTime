#!/bin/bash

g++ start_game.cpp main_hero.cpp artefact.cpp game.cpp -o start_game -lsfml-graphics -lsfml-window -lsfml-system  && ./start_game

