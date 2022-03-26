//
// Created by Radu on 3/25/2022.
//

#include "Repository.h"


Repository::Repository(int capacity) {
    this->data = DynamicVector<Movie>(capacity);
}

int Repository::add(Movie movie) {
    if(find(movie.getTitle()) != -1)
        return 1;
    this->data.add(movie);
    return 0;
}

int Repository::find(std::string title) {
    for(int i =0 ;i < this->data.getSize(); i++){
        if(this->data[i].getTitle() == title){
            return i;
        }
    }
    return -1;
}

int Repository::remove(std::string title) {
    int movieIndex = find(title);
    if(movieIndex == -1)
        return 1;
    this->data.remove(movieIndex);
    return 0;
}

int Repository::size() const {
    return this->data.getSize();
}

int Repository::replace(std::string title, Movie newMovie) {
    int movieIndex = find(title);
    if(movieIndex == -1)
        return 1;

    this->data[movieIndex] = newMovie;
    return 0;
}

DynamicVector<Movie> Repository::getAll() {
    return this->data;
}






