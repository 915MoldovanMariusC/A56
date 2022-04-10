//
// Created by Radu on 3/25/2022.
//

#include "Repository.h"

//
//Repository::Repository(int capacity) {
//    //this->data = DynamicVector<Movie>(capacity);
//
//}

int Repository::add(Movie movie) {
    if(find(movie.getTitle()) != -1)
        return 1;
    this->data.push_back(movie);
    return 0;
}

int Repository::find(std::string title) {
    for(int i =0 ;i < this->data.size(); i++){
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
    //this->data.pop_back(movieIndex);
    Movie aux = this->data[movieIndex];
    this->data[movieIndex] = this->data[this->size() - 1];
    this->data[this->size() - 1];
    this->data.pop_back();
    return 0;
}

int Repository::size() const {
    return this->data.size();
}

int Repository::replace(std::string title, Movie newMovie) {
    int movieIndex = find(title);
    if(movieIndex == -1)
        return 1;

    this->data[movieIndex] = newMovie;
    return 0;
}

vector<Movie> Repository::getAll() {
    return this->data;
}

Movie Repository::getElement(std::string title) {
    return this->data[find(title)];
}

void Repository::increaseLikes(std::string title) {
    this->data[find(title)].increaseLikes(1);
}






