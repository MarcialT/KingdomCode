# WELCOME TO THE KINGDOM CODE

This repository is focused in a university project for the course of Dinamic Data Structure

## Code Description

A family from a kingdom has been keeping track of the descendants of the first king for years. Each king has only generated a maximum of two heirs throughout his reign, always being the firstborn to inherit the throne, with cases where if the entire branch of the current king disappears then the first firstborn of the branch of his brother.

## Requirements

1. Convert the data from a .csv into a binary tree
2. Show the current line of succession (only to the living).
3. Assign a node as king automatically in case the current king dies, the allocation conditions are:
    If the king died and has children, the king is the first living firstborn found from his tree.
    If the king died and has no children, the king is the first living firstborn found from his brother's tree.
    If the king died and has no brothers or children, the king is the first living firstborn found from his uncle's tree.
    If the king died and neither his uncle nor his brother can be found, look for the first ancestor with two sons and choose as king the first living firstborn from the ancestor's tree.
    If all the firstborn are dead, follow the same rules for the second children, starting from the first found from the first king.
    If a king passed the age of 70, the crown is passed to the first living firstborn of his tree.
4. Change the data of any node in the tree, except the id and id of the parent.

## Getting started

To get a local copy up and running follow these simple steps:

1. Clone the repo `https://github.com/MarcialT/KingdomCode.git`
2. Open the project in your preferred C++ IDE
3. Copy and paste this command in the terminal for compile "g++ main.cpp -o ../bin/main.exe"
4. Copy and paste this command in the terminal for run "../bin/main.exe".


