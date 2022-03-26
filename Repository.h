//
// Created by Radu on 3/25/2022.
//

#include "DynamicVector.h"
#include "Domain.h"

#ifndef MOVIES_REPOSITORY_H
#define MOVIES_REPOSITORY_H

#endif //MOVIES_REPOSITORY_H

#pragma once

class Repository{
private:
    DynamicVector<Movie> data;

public:

    Repository(int capacity);

    int add(Movie movie);

    int remove(std::string title);

    int size() const;

    int replace(std::string title, Movie newMovie);

    int find(std::string title);

    DynamicVector<Movie> getAll();



};


