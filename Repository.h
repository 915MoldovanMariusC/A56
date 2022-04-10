//
// Created by Radu on 3/25/2022.
//

#include "DynamicVector.h"
#include "Domain.h"
#include <vector>

#ifndef MOVIES_REPOSITORY_H
#define MOVIES_REPOSITORY_H

#endif //MOVIES_REPOSITORY_H

#pragma once

using std::vector;

class Repository{
private:
    //DynamicVector<Movie> data;
    vector<Movie> data;

public:

    //Repository(int capacity);

    int add(Movie movie);

    int remove(std::string title);

    int size() const;

    int replace(std::string title, Movie newMovie);

    int find(std::string title);

    vector<Movie> getAll();

    Movie getElement(std::string title);

    void increaseLikes(std::string title);
};


