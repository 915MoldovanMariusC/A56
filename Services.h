//
// Created by Radu on 3/26/2022.
//

#include "Repository.h"

#ifndef MOVIES_SERVICES_H
#define MOVIES_SERVICES_H

#endif //MOVIES_SERVICES_H
#pragma once


class Services{
private:
    Repository &repository;
public:

    Services(Repository &repository);

    int addToDatabase(std::string title, std::string genre, long long likeCount, int releaseYear, std::string trailerLink);

    int removeFromDatabase(std::string title);

    int changeMovie(std::string initialTitle, std::string newTitle, std::string genre, long long likeCount, int releaseYear, std::string trailerLink);

    DynamicVector<Movie> getMoviesByGenre(std::string genre);

    int removeFromList(DynamicVector<Movie> &list, std::string title);

    void likeMovie(std::string title);


};