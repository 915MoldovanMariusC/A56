#include <iostream>
#include "UI.h"

int main() {

    Repository repository(2);
    Services services(repository);
    UI ui(services);
    Movie m("Terminator", "Horror", 1990, 5, "https://www.twitch.tv/robeertiv");
    Movie m2("Terminator 2", "Thriller", 2000, 3, "https://www.twitch.tv/robeertiv");
    repository.add(m);
    repository.add(m2);
    ui.run();
    return 0;
}
