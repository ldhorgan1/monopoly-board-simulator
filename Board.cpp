#include "Board.h"


Space::Space() : name(""), color(""), value(0), rent(0) {}

Space::Space(string name, string color, int value, int rent)
    : name(name), color(color), value(value), rent(rent) {}

bool Space::isEqual(const Space& other) const {
    return name == other.name;
}

void Space::print() const {
    cout << name << " | " << color
         << " | $" << value << " | Rent " << rent;
}

Board::Board()
    : head(nullptr), tail(nullptr), player(nullptr), size(0), goPasses(0){}

Board::~Board() {
    if (!head) return;

    tail->next = nullptr;

    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        delete cur;
        cur = next;
    }
}
bool Board::addSpace(const Space& s) {
        if (size >= MAX_SPACES) return false;

        Node* n = new Node(s);

        if (!head) {
            head = tail = n;
            n->next = n;
            player = head;
        } else {
            tail->next = n;
            n->next = head;
            tail = n;
        }

    size++;
    return true;
}

int Board::addMany(const std::vector<Space>& spaces) {
    int added = 0;
    for (const auto& s : spaces) {
        if (!addSpace(s)) break;
        added++;
    }
    return added;
}

void Board::printFromCurrent(int count) const {
    if (!player){
        std::cout << "Board empty\n";
        return;
    }

    Node* cur = player;
    for (int i = 0; i < count; i++) {
        std::cout << cur->data.name
        << " | Value: " << cur->data.value
        << " |Rent: " << cur->data.rent
        << " [" << cur->data.color << "]\n";
        cur = cur->next;
    }
}
   int Board::getGoPasses() const {
    return goPasses;
}

Space Board::getCurrentSpace() const {
    if (!player) return Space{"","", 0, 0};
    return player->data;
}
void Board::move(int steps) {
    if (!player || size == 0) return;

    for (int i = 0; i < steps; i++) {
        player = player->next;
        if (player == head) {
            goPasses++;
        }
    }
}

int Board::getSize() const {
    return size;
}
bool Board::removeByName(const std::string& name) {
    if (!head) return false;

    Node* cur = head;
    Node* prev = tail;

    do {
        if (cur->data.name == name) {
            if (head == tail) {
                delete cur;
                head = tail = player = nullptr;
                size = 0;
                goPasses = 0;
                return true;
            }

            prev->next = cur->next;

            if (cur == head) {
                head = cur->next;
                tail->next = head;
            }

            if (cur == tail) {
                tail = prev;
                tail->next = head;
            }

            if (player == cur) {
                player = cur->next;
            }

            delete cur;
            size--;
            return true;
        }

        prev = cur;
        cur = cur->next;

    } while (cur != head);
    return false;

}
std::vector<std::string> Board::findByColor(const std::string& color) const {
    std::vector<std::string> matches;

    if (!head) return matches;

    Node* cur = head;
    do {
        if (cur->data.color == color) {
            matches.push_back(cur->data.name);
        }
        cur = cur->next;
    } while (cur != head);

    return matches;
}