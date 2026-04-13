#include "src/hello.hpp"
#include <vector>
#include <iostream>

int main() {
  TodoList list;
  std::vector<std::string> milkTags = { "food" };
  list.add("Buy milk", milkTags);

  std::vector<std::string> eggTags = { "food" };
  list.add("Buy eggs", eggTags);

  // No tags for this item!
  list.add("Prepare a lesson for CSC 122");

  std::vector<std::string> beetTags = { "food", "garden", "spring" };
  list.add("Sow beet seeds", beetTags);

  list.complete("Buy eggs");

  // Pretty prints "Buy milk", "Buy eggs",
  // and "Sow beet seeds"
  list.taggedWith("food");

  // Pretty prints a message saying that this list is empty
  list.taggedWith("music");

  // Pretty prints a list of each of the four tasks above
  list.all();

  // Pretty prints the task "Buy eggs"
  list.complete();

  // Pretty prints the tasks "Buy milk",
  // "Prepare a lesson for CSC 122", and "Sow beet seeds"
  list.incomplete();

  // Clears the to-do list
  list.clear();

  // Pretty prints a message saying that the list is empty
  list.all();
}