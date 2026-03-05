#include "Board.h"

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
        std::cout << cur->data.name << " (" << cur->data.type << ")\n";
        cur = cur->next;
    }
}
   int Board::getGoPasses() const {
    return goPasses;
}

Space Board::getCurrentSpace() const {
    if (!player) return Space{"","",""};
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
