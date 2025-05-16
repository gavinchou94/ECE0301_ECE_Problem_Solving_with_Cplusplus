#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Agent.hpp"
#include "Acorn.hpp"
#include "Squirrel.hpp"
#include "Fox.hpp"
#include "Grid.hpp"
#include "Simulator.hpp"

/*
=======================================================================
    Provided test cases
=======================================================================
*/

/* Acorn unit tests */
TEST_CASE("Simulator: Test Acorn energy", "[simulator]"){
    Acorn a;
    REQUIRE(a.get_type() == ACORN);
    REQUIRE(a.get_energy() == Acorn::PHOTO_ENERGY);
    REQUIRE_FALSE(a.can_act());

    a.energize(0);
    REQUIRE(a.get_energy() == 2*Acorn::PHOTO_ENERGY);
    a.energize(0);
    REQUIRE(a.get_energy() == 3*Acorn::PHOTO_ENERGY);
    a.energize(0);
    REQUIRE(a.get_energy() == 4*Acorn::PHOTO_ENERGY);
    a.energize(0);
    REQUIRE(a.get_energy() == 5*Acorn::PHOTO_ENERGY);
}

TEST_CASE("Simulator: Test Acorn energy constructor", "[simulator]"){

    int start = 5*Acorn::PHOTO_ENERGY;
    Acorn a(start);
    REQUIRE(a.get_type() == ACORN);
    REQUIRE(a.get_energy() == start);
    REQUIRE(a.action() == LEFT);
    REQUIRE(a.act());
    REQUIRE(a.get_energy() == start-Acorn::GROW_ENERGY);
    REQUIRE(a.action() == UP);
    a.energize(0);
    REQUIRE(a.get_energy() == start-Acorn::GROW_ENERGY+Acorn::PHOTO_ENERGY);
}

TEST_CASE("Simulator: Test Acorn actions", "[simulator]"){
    Acorn a;
    a.energize(4*Acorn::GROW_ENERGY);
    // test actions
    REQUIRE(a.action() == LEFT);
    REQUIRE(a.can_act());
    REQUIRE(a.act());
    a.energize(Acorn::GROW_ENERGY);
    REQUIRE(a.action() == UP);
    REQUIRE(a.can_act());
    REQUIRE(a.act());
    a.energize(Acorn::GROW_ENERGY);
    REQUIRE(a.action() == RIGHT);
    REQUIRE(a.can_act());
    REQUIRE(a.act());
    a.energize(Acorn::GROW_ENERGY);
    REQUIRE(a.action() == DOWN);
    REQUIRE(a.can_act());
    REQUIRE(a.act());
    a.energize(Acorn::GROW_ENERGY);
    REQUIRE(a.action() == LEFT);

    // test next_action
    REQUIRE(a.next_action() == UP);
    REQUIRE(a.action() == UP);
    REQUIRE(a.next_action() == RIGHT);
    REQUIRE(a.action() == RIGHT);
    REQUIRE(a.next_action() == DOWN);
    REQUIRE(a.action() == DOWN);
    REQUIRE(a.next_action() == LEFT);
    REQUIRE(a.action() == LEFT);

}

/* Squirrel unit tests */
TEST_CASE("Simulator: Test Squirrel actions", "[simulator]"){
    Squirrel s;
    int start = 4*Squirrel::MOVE_ENERGY;
    REQUIRE(s.get_type() == SQUL);
    REQUIRE(s.get_energy() == start);
    REQUIRE(s.action() == UP);
    REQUIRE(s.act());
    REQUIRE(s.get_energy() == start-Squirrel::MOVE_ENERGY);
    REQUIRE(s.action() == LEFT);
    REQUIRE(s.act());
    REQUIRE(s.get_energy() == start-2*Squirrel::MOVE_ENERGY);
    REQUIRE(s.action() == UP);
    REQUIRE(s.act());
    REQUIRE(s.get_energy() == start-3*Squirrel::MOVE_ENERGY);
    REQUIRE(s.action() == LEFT);
    REQUIRE(s.act());
    REQUIRE(s.get_energy() == 0);

    // test next action
    REQUIRE(s.action() == UP);
    REQUIRE(s.next_action() == LEFT);
    REQUIRE(s.action() == LEFT);
    REQUIRE(s.next_action() == UP);

}

TEST_CASE("Simulator: Test more Squirrel actions", "[simulator]"){
    // test energy constructor and movement below MOVE_ENERGY
    Squirrel s(Squirrel::MOVE_ENERGY-1);
    REQUIRE(s.get_type() == SQUL);
    REQUIRE(s.get_energy() == Squirrel::MOVE_ENERGY-1);
    REQUIRE(s.action() == UP);
    REQUIRE(s.act());
    REQUIRE(s.get_energy() == 0);

    // test energize
    s.energize(2*Squirrel::MOVE_ENERGY);
    REQUIRE(s.action() == LEFT);
    REQUIRE(s.act());
    REQUIRE(s.get_energy() == Squirrel::MOVE_ENERGY);
    REQUIRE(s.action() == UP);
}

/* Grid tests */
TEST_CASE("Simulator: Test Grid with ints", "[simulator]"){
    Grid<int> g;
    REQUIRE(g.get_size() == Grid<int>::DEFAULT_SIZE);
    bool check = true;
    for (int r=0; r<Grid<int>::DEFAULT_SIZE; r++) {
        for (int c=0; c<Grid<int>::DEFAULT_SIZE; c++) {
            check = g.get_cell(Location{r,c}) == nullptr;
            if (!check) {
                break;
            }
        }
        if (!check) {
            break;
        }
    }
    REQUIRE(check);

    Location loc{5,7};
    g.set_cell(loc, new int(5));
    REQUIRE(g.get_cell(Location{0,0}) == nullptr);
    REQUIRE(*g.get_cell(loc) == 5);
}

TEST_CASE("Simulator: Test Grid with Agents", "[simulator]"){
    Grid<Agent> g;
    REQUIRE(g.get_size() == Grid<Agent>::DEFAULT_SIZE);
    bool check = true;
    for (int r=0; r<Grid<Agent>::DEFAULT_SIZE; r++) {
        for (int c=0; c<Grid<Agent>::DEFAULT_SIZE; c++) {
            check = g.get_cell(Location{r,c}) == nullptr;
            if (!check) {
                break;
            }
        }
        if (!check) {
            break;
        }
    }
    REQUIRE(check);

    // test get out of bounds
    REQUIRE_THROWS_AS(g.get_cell(Location{Grid<Agent>::DEFAULT_SIZE, 0}), std::out_of_range);
    REQUIRE_THROWS_AS(g.get_cell(Location{0, Grid<Agent>::DEFAULT_SIZE}), std::out_of_range);

    // test size constructor
    int size = 20;
    Grid<Agent> g2(size);
    REQUIRE(g2.get_size() == size);
    for (int r=0; r<size; r++) {
        for (int c=0; c<size; c++) {
            check = g2.get_cell(Location{r,c}) == nullptr;
            if (!check) {
                break;
            }
        }
        if (!check) {
            break;
        }
    }
    REQUIRE(check);
    // test get out of bounds
    REQUIRE_THROWS_AS(g2.get_cell(Location{size, 0}), std::out_of_range);
    REQUIRE_THROWS_AS(g2.get_cell(Location{0, size}), std::out_of_range);

    // test set_cell
    Acorn* f = new Acorn();
    Location loc{10,15};
    g2.set_cell(loc, f);
    REQUIRE(g2.get_cell(loc) == f);
    REQUIRE(g2.get_cell(loc)->action() == LEFT);

    // test set out of bounds
    REQUIRE_THROWS_AS(g2.set_cell(Location{size, 0}, f), std::out_of_range);
    REQUIRE_THROWS_AS(g2.set_cell(Location{0, size}, f), std::out_of_range);

    // test move
    Location mov{11,15};
    REQUIRE(g2.move(loc, mov));
    REQUIRE(g2.get_cell(mov) == f);
    // place a new acorn at the "from" location, test that it can't move onto f
    Acorn* f2 = new Acorn();
    g2.set_cell(loc, f2);
    REQUIRE_FALSE(g2.move(loc, mov));

    // test clear
    g2.clear();
    for (int r=0; r<size; r++) {
        for (int c=0; c<size; c++) {
            check = g2.get_cell(Location{r,c}) == nullptr;
            if (!check) {
                break;
            }
        }
        if (!check) {
            break;
        }
    }
    REQUIRE(check);

    // test resize
    int new_size = 30;
    g2.resize(new_size);
    for (int r=0; r<new_size; r++) {
        for (int c=0; c<new_size; c++) {
            check = g2.get_cell(Location{r,c}) == nullptr;
            if (!check) {
                break;
            }
        }
        if (!check) {
            break;
        }
    }
    REQUIRE(check);

    // acorn ptrs are deallocated with the clear/resize
}

/* Simulator tests */
TEST_CASE("Simulator: Test Simulator empty grid", "[simulator]"){
    // default construction
    Simulator si;
    REQUIRE(si.size() == Grid<Agent>::DEFAULT_SIZE);

    // test done state, should be done if empty
    REQUIRE(si.done());

    // invalid size should throw due to grid
    REQUIRE_THROWS_AS(Simulator(-1), std::invalid_argument);
}

TEST_CASE("Simulator: Test Simulator set Acorn", "[simulator]"){
    Simulator si;
    // add acorn
    Location acorn_loc = Location{1,1};
    REQUIRE(si.set(acorn_loc, ACORN));
    REQUIRE(si.get_type(acorn_loc) == ACORN);

    // cannot stack agents
    REQUIRE_FALSE(si.set(acorn_loc, ACORN));
    // cannot add invalid agent type
    REQUIRE_FALSE(si.set(Location{0,0}, NONE));

    // test done - should be done if only acorn
    REQUIRE(si.done());

    // example of exporting an image of the simulation grid state
    si.export_image("output.bmp");
}

TEST_CASE("Simulator: Test Simulator Acorn actions", "[simulator]"){
    Simulator si;
    Location acorn_loc = Location{5,5};
    REQUIRE(si.set(acorn_loc, ACORN));
    si.export_image("acorn0.bmp"); // initial state
    // test energize and update(grow), should generate acorn in adjacent cell
    si.energize(acorn_loc, 4*Acorn::GROW_ENERGY);
    si.update(); // grow left
    si.export_image("acorn1.bmp");
    REQUIRE(si.get_type(acorn_loc) == ACORN); // original stays
    Location left_cell {acorn_loc.row, acorn_loc.col-1};
    REQUIRE(si.get_type(left_cell) == ACORN); // new growth
    si.update(); // grow up
    si.export_image("acorn2.bmp");
    REQUIRE(si.get_type(acorn_loc) == ACORN); // original stays
    Location up_cell {acorn_loc.row-1, acorn_loc.col};
    REQUIRE(si.get_type(up_cell) == ACORN); // new growth
    si.update(); // grow right
    si.export_image("acorn3.bmp");
    REQUIRE(si.get_type(acorn_loc) == ACORN); // original stays
    Location right_cell {acorn_loc.row, acorn_loc.col+1};
    REQUIRE(si.get_type(up_cell) == ACORN); // new growth
    si.update(); // grow down
    si.export_image("acorn4.bmp");
    REQUIRE(si.get_type(acorn_loc) == ACORN); // original stays
    Location down_cell {acorn_loc.row+1, acorn_loc.col};
    REQUIRE(si.get_type(down_cell) == ACORN); // new growth

    Simulator si_cp;
    Location acorn_loc_cp = Location{5,5};
    REQUIRE(si_cp.set(acorn_loc_cp, ACORN));
    si_cp.energize(acorn_loc_cp, 4*Acorn::GROW_ENERGY);
    si_cp.export_animation("acorn_animation", 5); // doing the same 5 steps and exporting as a gif

}

TEST_CASE("Simulator: Test Simulator Acorn set and remove", "[simulator]"){
    Simulator si;
    Location acorn_loc = Location{1,1};
    Location left_cell {acorn_loc.row, acorn_loc.col-1};
    Location up_cell {acorn_loc.row-1, acorn_loc.col};
    REQUIRE(si.set(acorn_loc, ACORN));
    si.energize(acorn_loc, 2*Acorn::GROW_ENERGY);
    si.update(); // grow left
    si.update(); // grow up
    // test remove
    REQUIRE_FALSE(si.remove(Location{0,0})); // no agent here
    REQUIRE(si.remove(acorn_loc));
    REQUIRE(si.get_type(acorn_loc) == NONE);
    REQUIRE(si.remove(left_cell));
    REQUIRE(si.get_type(left_cell) == NONE);
    REQUIRE(si.remove(up_cell));
    REQUIRE(si.get_type(up_cell) == NONE);
}

TEST_CASE("Simulator: Test Simulator Squirrel movement", "[simulator]"){
    // test update (squirrel movement)
    Simulator si;
    Location squirrel_start = Location{4,5};
    REQUIRE(si.set(squirrel_start, SQUL));
    REQUIRE(si.get_type(squirrel_start) == SQUL);

    // simulation is not done because there is squirrel
    REQUIRE_FALSE(si.done());
    si.export_image("squl0.bmp"); // initial state

    // test that squirrel moves and previous cell is cleared on move
    si.update(); // squirrel moves up
    si.export_image("squl1.bmp");
    Location squirrel_move_1 {squirrel_start.row-1, squirrel_start.col};
    REQUIRE(si.get_type(squirrel_move_1) == SQUL);
    REQUIRE(si.get_type(squirrel_start) == NONE);

    si.update(); // squirrel moves left
    si.export_image("squl2.bmp");
    Location squirrel_move_2 {squirrel_start.row-1, squirrel_start.col-1};
    REQUIRE(si.get_type(squirrel_move_2) == SQUL);
    REQUIRE(si.get_type(squirrel_move_1) == NONE);
    REQUIRE(si.get_type(squirrel_start) == NONE);

    si.update(); // squirrel moves up
    si.export_image("squl3.bmp");
    Location squirrel_move_3 {squirrel_start.row-2, squirrel_start.col-1};
    REQUIRE(si.get_type(squirrel_move_3) == SQUL);
    REQUIRE(si.get_type(squirrel_move_2) == NONE);
    REQUIRE(si.get_type(squirrel_move_1) == NONE);
    REQUIRE(si.get_type(squirrel_start) == NONE);

    si.update(); // squirrel moves left
    si.export_image("squl4.bmp");
    Location squirrel_move_4 {squirrel_start.row-2, squirrel_start.col-2};
    REQUIRE(si.get_type(squirrel_move_4) == SQUL);
    REQUIRE(si.get_type(squirrel_move_3) == NONE);
    REQUIRE(si.get_type(squirrel_move_2) == NONE);
    REQUIRE(si.get_type(squirrel_move_1) == NONE);
    REQUIRE(si.get_type(squirrel_start) == NONE);
    si.update(); // squirrel "dies"
    si.export_image("squl5.bmp");

    Simulator si_cp;
    Location squirrel_start_cp = Location{4,5};
    REQUIRE(si_cp.set(squirrel_start_cp, SQUL));
    si_cp.export_animation("squl_animation", 6); // doing the same 6 steps and exporting as a gif
}

/*
=======================================================================
    TODO: Your test cases here
=======================================================================
*/