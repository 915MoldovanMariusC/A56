//
// Created by Radu on 3/25/2022.
//

#include "Domain.h"
#include <Windows.h>


Movie::Movie(std::string title, std::string genre, int releaseYear, long long likeCount, std::string trailerLink) {
    this->title = title;
    this->genre = genre;
    this->releaseYear = releaseYear;
    this->likeCount = likeCount;
    this->trailerLink = trailerLink;
}

Movie::Movie(const Movie &movie) {
    this->title = movie.title;
    this->genre = movie.genre;
    this->likeCount = movie.likeCount;
    this->releaseYear = movie.releaseYear;
    this->trailerLink = movie.trailerLink;

}

std::string Movie::getTitle() {
    return this->title;
}

std::string Movie::toString() {
    return "Title: " + this->title + " Genre: " + this->genre + " Release year: " + std::to_string(this->releaseYear) +
            " Likes: " + std::to_string(this->likeCount) + " Link: " + this->getLink();
}

std::string Movie::getGenre() {
    return this->genre;
}

Movie::Movie() {
    this->genre = "";
    this->title = "";
    this->trailerLink = "";
    this->likeCount = 0;
    this->releaseYear = 0;
}

void Movie::increaseLikes(int quantity) {
    this->likeCount += quantity;
}

std::string Movie::getLink() {
    return this->trailerLink;
}

void Movie::playTrailer() {
    ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);

}

Movie::~Movie() = default;

