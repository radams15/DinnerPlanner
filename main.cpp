#include "DB.h"
#include "Recipe_View.h"

int main(int argc, char** argv) {

    DB db("../recipes.sqlite");

    Recipe_View recipe_view(argc, argv);

    return recipe_view.run();
}
