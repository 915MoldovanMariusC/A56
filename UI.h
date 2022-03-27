//
// Created by Radu on 3/26/2022.
//
#pragma once
#include "Services.h"

#ifndef MOVIES_UI_H
#define MOVIES_UI_H

#endif //MOVIES_UI_H


class UI{
private:
    Services &services;
    DynamicVector<Movie> watchList;
public:

    UI(Services &services);

    void run();

    void printAdminMenu();

    void addToWatchlist();

    void adminMenu();

    void printOperationResult(int result);

    int addMovieUI();

    int removeMovieUI();

    int changeMovieUI();

    void printAllMovies();

    void printUserMenu();

    void userMenu();

    void removeFromWatchlist();

    void printWatchlist();
};