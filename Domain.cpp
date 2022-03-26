//
// Created by Radu on 3/25/2022.
//

#include "Domain.h"


Movie::Movie(std::string title, std::string genre, int releaseYear, long long likeCount, std::string trailerLink) {
    this->title = title;
    this->genre = genre;
    this->releaseYear = releaseYear;
    this-> likeCount = likeCount;
    this->trailerLink = trailerLink;
}

Movie::Movie(const Movie &movie) {
    this->title = movie.title;
    this->genre = movie.genre;
    this->likeCount = movie.likeCount;
    this->releaseYear = movie.releaseYear;

}

std::string Movie::getTitle() {
    return this->title;
}

std::string Movie::toString() {
    return "Title: " + this->title + "Genre: " + this->genre + "Release year: " + std::to_string(this->releaseYear) +
            "Likes: " + std::to_string(this->likeCount) + "Link: " + this->trailerLink;
}

std::string Movie::getGenre() {
    return this->genre;
}

Movie::~Movie() = default;

