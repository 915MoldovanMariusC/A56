#include <iostream>
#include "UI.h"

int main() {

    Repository repository(2);
    Services services(repository);
    UI ui(services);
    Movie m("Terminator", "Horror", 1990, 5, "https://www.youtube.com/watch?v=k64P4l2Wmeg");
    Movie m2("Terminator-2", "Thriller", 2000, 3, "https://www.youtube.com/watch?v=lwSysg9o7wE");
    Movie m3("Spider-man", "Action", 2005, 200, "https://www.youtube.com/watch?v=JfVOs4VSpmA");
    Movie m4("Avengers", "Action", 2010, 200, "https://www.youtube.com/watch?v=eOrNdBpGMv8");
    Movie m5("Infinity-War", "Thriller", 2011, 200, "https://www.youtube.com/watch?v=JfVOs4VSpmA");
    Movie m6("Iron-Man", "Action", 2001, 200, "https://www.youtube.com/watch?v=8ugaeA-nMTc");
    Movie m7("Hulk", "Action", 2017, 200, "https://www.youtube.com/watch?v=xbqNb2PFKKA");
    Movie m8("Matrix", "Action", 2014, 200, "https://www.youtube.com/watch?v=9ix7TUGVYIo");
    Movie m9("Forrest-gump", "Love", 2004, 200, "https://www.youtube.com/watch?v=uPIEn0M8su0");
    Movie m10("In-time", "Action", 2008, 200, "https://www.youtube.com/watch?v=YRSBiTF3wNw");
    repository.add(m);
    repository.add(m2);
    repository.add(m3);
    repository.add(m4);
    repository.add(m5);
    repository.add(m6);
    repository.add(m7);
    repository.add(m8);
    repository.add(m9);
    repository.add(m10);
    ui.run();
    return 0;
}
