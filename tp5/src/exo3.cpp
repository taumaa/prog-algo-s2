#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <unordered_map>

enum class CardKind {
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue {
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card {
    CardKind kind;
    CardValue value;

    bool operator==(Card const& other) const {
        return kind == other.kind && value == other.value;
    }

    int hash() const {
        return static_cast<int>(kind) * 13 + static_cast<int>(value);
    }

};

namespace std {
    template<>
    struct hash<Card> {
        size_t operator()(Card const& card) const {
            return card.hash();
        }
    };
}

#include <vector>
std::vector<Card> get_cards(size_t const size) {
    std::vector<Card> cards {};
    cards.reserve(size);
    for (size_t i {0}; i < size; ++i) {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

int main() {

    std::vector<Card> cards {get_cards(100)};
    std::unordered_map<Card, size_t> card_counts {};

    for (Card const& card : cards) {
        card_counts[card]++;
    }

    return 0;
}