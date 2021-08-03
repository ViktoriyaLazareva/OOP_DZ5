#include <iostream>
#include <vector>
using namespace std;

class Card {
public:
    enum rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};
    enum suit {CLUBS, DIAMONDS, HEARTS, SPADES};

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    int GetValue() const;
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu)
{}

int Card::GetValue() const {
    int value = 0;
    if (m_IsFaceUp) {
        value = m_Rank;
        if (value > 10) {
            value = 10;
        }
    }
    return value;
}

void Card::Flip() {
    m_IsFaceUp = !(m_IsFaceUp);
}


class Hand {
protected:
    vector<Card*> m_Cards;
public:
    Hand();
    virtual ~Hand(); // виртуальный деструктор
    void Clear(); // добавляет карту в руку очищает руку от карт
    int GetTotal() const; //получает сумму очков карт в руке, присваивая тузу значение 1 или 11 в зависимости от ситуации
    void addCard(Card* pCard) {
    m_Cards.push_back(pCard);
}

};

Hand::Hand()
{
    m_Cards.reserve(7);
}
Hand::~Hand()//деструктор по-прежнему виртуальный это уже можно не обозначать
{
    Clear();
}

void Hand::Clear() {
    vector<Card*>::iterator iter = m_Cards.begin();// проходит по вектору, освобождая всю память в куче
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        delete *iter;
        *iter = 0;
    }
    m_Cards.clear();// очищает вектор указателей
}

int Hand::GetTotal() const {
    if (m_Cards.empty()) {
        return 0;// если карт в руке нет, возвращает значение 0
    } //если первая карта имеет значение 0, то она лежит рубашкой вверх: вернуть значение 0
    if (m_Cards[0]->GetValue() == 0) {
        return 0;
    } // находит сумму очков всех карт, каждый туз дает 1 очко
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        total += (*iter)->GetValue();
    } // определяет, держит ли рука туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
    if (containsAce && total <= 11) { // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
        total += 10;//добавляем только 10 очков, поскольку мы уже добавили за каждый туз по одному очку
    }

    return total;
}







int main()
{
cout << "\t\tWelcome to Blackjack!\n\n";

    int numPlayers = 0;
    while (numPlayers < 1 || numPlayers > 7)
    {
        cout << "How many players? (1 - 7): ";
        cin >> numPlayers;
    }

    vector<string> names;
    string name;
    for (int i = 0; i < numPlayers; ++i)
    {
        cout << "Enter player name: ";
        cin >> name;
        names.push_back(name);
    }
    cout << endl;

    // игровой цикл
  /*  Game aGame(names);
    char again = 'y';
    while (again != 'n' && again != 'N')
    {
        aGame.Play();
        cout << "\nDo you want to play again? (Y/N): ";
        cin >> again;
    }*/

    return 0;
}
