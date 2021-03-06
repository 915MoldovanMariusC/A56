//
// Created by Radu on 3/26/2022.
//

#include "Services.h"

Services::Services(Repository &repository) : repository{repository} {}

int Services::addToDatabase(std::string title, std::string genre, long long likeCount, int releaseYear,
                            std::string trailerLink) {
    if(releaseYear < 0)
        return 2;
    Movie movie(title, genre, releaseYear, likeCount, trailerLink);
    return this->repository.add(movie);
}

int Services::removeFromDatabase(std::string title) {
    return this->repository.remove(title);
}

int Services::changeMovie(std::string initialTitle, std::string newTitle, std::string genre, long long int likeCount,
                          int releaseYear, std::string trailerLink) {
    Movie movie(newTitle, genre, releaseYear, likeCount, trailerLink);
    return this->repository.replace(initialTitle, movie);
}

vector<Movie> Services::getMoviesByGenre(std::string genre) {
    vector<Movie> movieList, allMovies = this->repository.getAll();
    if(genre == "*")
        return allMovies;
    for(int i = 0; i < allMovies.getSize(); i++){
        if(allMovies[i].getGenre() == genre){
            movieList.add(allMovies[i]);
        }
    }
    return movieList;
}

int Services::removeFromList(vector<Movie> &list, std::string title) {
    for(int i = 0; i < list.getSize(); i++){
        if(list[i].getTitle() == title){
            list.remove(i);
            return 0;
        }
    }

    return 1;
}

void Services::likeMovie(std::string title) {
    this->repository.increaseLikes(title);
}






