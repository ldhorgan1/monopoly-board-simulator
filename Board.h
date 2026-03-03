//
// Created by Liam Horgan on 3/1/26.
//

#ifndef MONOPOLY_BOARD_SIMULATOR_BOARD_H
#define MONOPOLY_BOARD_SIMULATOR_BOARD_H

#include <iostream>
#include <vector>
#include <string>

struct Space {
    std::string name;
    std::string color;
    std::string type;
};

struct Node {
    Space data;
    Node* next;
    Node(const Space& s) : data(s), next(nullptr) {}
};

class Board {
private:
    Node* head;
    Node* tail;
    Node* player;
    int size;
    int goPasses;
    static const int MAX_SPACES = 40;

public:
    bool removeByName(const std::string& name);
    std::vector<std::string> findByColor(const std::string& color) const;

    Board();
    ~Board();

    bool addSpace(const Space& s);
    int addMany(const std::vector<Space>& spaces);
    void move(int steps);
    void printFromCurrent(int count) const;

    int getGoPasses() const;
    int getSize() const;
    Space getCurrentSpace() const;
};
#endif //MONOPOLY_BOARD_SIMULATOR_BOARD_H
