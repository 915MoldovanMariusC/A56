//
// Created by Radu on 3/25/2022.
//

#include <string>

#ifndef MOVIES_DOMAIN_H
#define MOVIES_DOMAIN_H

#endif //MOVIES_DOMAIN_H
#pragma once



class Movie{
private:
    std::string title;
    std::string genre;
    int releaseYear;
    long long likeCount;
    std::string trailerLink;

public:
    Movie();
    Movie(std::string title, std::string genre, int releaseYear, long long likeCount, std::string trailerLink);
    Movie(const Movie& movie);
    std::string getTitle();
    std::string getGenre();
    std::string getLink();
    ~Movie();
    void increaseLikes(int quantity);
    std::string toString();
    void playTrailer();


};
