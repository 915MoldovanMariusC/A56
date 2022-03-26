//
// Created by Radu on 3/26/2022.
//

#include "UI.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

UI::UI(Services services) {
    this->services = services;
}

void UI::run() {
    int option;
    while(true) {
        cout << "1.Admin mode" << endl;
        cout << "2.User mode" << endl;
        cout << "3.Exit";
        cin >> option;
        if (option == 1)
            adminMenu();
        else if(option == 2)
            addToWatchlist();
        else if(option == 3)
            break;
    }
}

void UI::printAdminMenu() {
    cout<<"1.Add a new movie"<<endl;
    cout<<"2.Remove a movie from the database"<<endl;
    cout<<"3.Edit a movie";
    cout<<"4.Print all movies";
}

void UI::adminMenu() {
    int option;
    while(true) {
        printAdminMenu();
        cin >> option;
        if(option == 1){
            printOperationResult(addMovieUI());
        }
        else if(option == 0)
            break;
        else if(option == 2)
            printOperationResult(removeMovieUI());
        else if(option == 3)
            printOperationResult((changeMovieUI()));
    }

}

void UI::printOperationResult(int result) {
    if(result == 0)
        cout<<"Successful";
    else if(result == 1)
        cout<<"Not successful";
    else if(result == 2)
        cout<<"Invalid input data";

}

int UI::addMovieUI() {
    std::string title, genre, trailerLink;
    int likeCount, releaseYear;
    cout<<"Title ";
    getline(cin, title);
    cout<<"Genre: ";
    getline(cin, genre);
    cout<<"Link to the trailer: ";
    getline(cin, trailerLink);
    cout<<"Number of likes: ";
    cin>>likeCount;
    cout<<"Year of release: ";
    cin>>releaseYear;
    return this->services.addToDatabase(title, genre, likeCount, releaseYear, trailerLink);
}

int UI::removeMovieUI(){
    std::string title;
    cout<<"Movie title: ";
    getline(cin, title);
    return this->services.removeFromDatabase(title);
}

int UI::changeMovieUI(){
    std::string initialTitle, newTitle, newGenre, newLink;
    int likeCount, releaseYear;
    cout<<"Movie title: ";
    getline(cin, initialTitle);
    cout<<"New title: ";
    getline(cin, newTitle);
    cout<<"New genre: ";
    getline(cin, newGenre);
    cout<<"New link: ";
    getline(cin, newLink);
    cout<<"Number of likes: ";
    cin>>likeCount;
    cout<<"Year of release: ";
    cin>>releaseYear;
    return this->services.changeMovie(initialTitle,newTitle,newGenre, likeCount, releaseYear, newLink);


}

void UI::printAllMovies() {
    DynamicVector<Movie> movieList;
    movieList = this->services.getMoviesByGenre("");
    for(int i = 0; i< movieList.getSize(); i++){
        cout<<movieList[i].toString()<<endl;
    }
}

void UI::addToWatchlist() {
    DynamicVector<Movie> allMovies;
    std::string genre;
    std::getline(cin, genre);
    allMovies = this->services.getMoviesByGenre(genre);
    int option;
    int counter = 0;
    while(true){
        cout<<allMovies[counter].toString()<<endl;
        // open trailer
        cout<<"1. Save movie"<<endl<<"2. Next movie"<<endl<<"3. Stop cycling";
        cin>>option;
        if(option == 1)
            this->watchList.add(allMovies[counter]);
        else if(option == 3)
            break;
        if(counter < allMovies.getSize() - 1)
            counter++;
        else
            counter = 0;
    }
}

void UI::userMenu() {
    int option;
    while(true){
        printUserMenu();
        cin>>option;
        if(option == 0)
            break;
        else if(option == 1){
            addToWatchlist();
        }
        else if(option == 2)
            removeFromWatchlist();
        else if(option == 3)
            printWatchlist();
    }
}

void UI::removeFromWatchlist() {
    std::string title;
    cout<<"Title: ";
    std::getline(cin, title);
    printOperationResult(this->services.removeFromList(this->watchList, title));
}

void UI::printWatchlist() {
    for(int i = 0; i < this->watchList.getSize(); i++){
        cout<<this->watchList[i].toString()<<endl;
    }
}

void UI::printUserMenu() {
    cout<<"0. Quit";
    cout<<"1. Add movies to watchlist"<<endl;
    cout<<"2. Remove movie from watchlist"<<endl;
    cout<<"3. Print the watch list"<<endl;
}



