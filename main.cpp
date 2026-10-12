#include <iostream>
#include "List.h"
#include "Player.h"

int main() {
    // ---- Part 1: required test harness, do not modify ----
    std::cout << "== List<int>: addAnywhere / deleteAnywhere / reverse =="
              << std::endl;
    std::unique_ptr<List<int>> nums = makeList<int>();
    nums->addFront(new int(10));
    nums->addFront(new int(20));
    nums->addFront(new int(30));
    nums->print();
    nums->addAnywhere(1, new int(99));
    nums->print();
    nums->deleteAnywhere(2);
    nums->print();
    nums->reverse();
    nums->print();

    std::cout << std::endl << "== List<int>: concat ==" << std::endl;
    std::unique_ptr<List<int>> more = makeList<int>();
    more->addFront(new int(2));
    more->addFront(new int(1));
    more->print();
    nums->concat(more.get());
    nums->print();
    more->print();

    // ---- Part 2: your Uno scene goes below ----

    // 1. A table forms, three or four players join the turn order.
    std::unique_ptr<List<Player>> table1 = makeList<Player>();
    table1->addFront(new Player(3, "Drake"));
    table1->addFront(new Player(2, "John"));
    table1->addFront(new Player(1, "Pranav"));
    std::cout << "Initial table:" << std::endl;
    table1->print();

    // 2. A new player pulls up a chair and joins mid-order, not at the front, using addAnywhere
    table1->addAnywhere(1, new Player(4, "Manju"));
    std::cout << "After new join:" << std::endl;
    table1->print();

    /* 3. Someone plays a Reverse card, using reverse, and you print the turn order before and after so
    the change is visible */
    std::cout << "Before reverse:" << std::endl;
    table1->print();
    table1->reverse();
    std::cout << "After reverse:" << std::endl;
    table1->print();

    /* 4. A player runs out of cards and steps away from a position that isn’t the front, using
    deleteAnywhere. */
    table1->deleteAnywhere(2);
    std::cout << "After exit:" << std::endl;
    table1->print();

    // 5.  A second table, built separately, merges into the first using concat
    std::unique_ptr<List<Player>> table2 = makeList<Player>();
    table2->addFront(new Player(6, "Levi"));
    table2->addFront(new Player(5, "Zeke"));

    std::cout << "Table 1 before concat:" << std::endl;
    table1->print();

    std::cout << "Table 2 before concat:" << std::endl;
    table2->print();

    table1->concat(table2.get());

    std::cout << "Table 1 after concat:" << std::endl;
    table1->print();

    std::cout << "Table 2 after concat:" << std::endl;
    table2->print();

    return 0;
}
