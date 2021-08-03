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
    virtual ~Hand(); // ����������� ����������
    void Clear(); // ��������� ����� � ���� ������� ���� �� ����
    int GetTotal() const; //�������� ����� ����� ���� � ����, ���������� ���� �������� 1 ��� 11 � ����������� �� ��������
    void addCard(Card* pCard) {
    m_Cards.push_back(pCard);
}

};

Hand::Hand()
{
    m_Cards.reserve(7);
}
Hand::~Hand()//���������� ��-�������� ����������� ��� ��� ����� �� ����������
{
    Clear();
}

void Hand::Clear() {
    vector<Card*>::iterator iter = m_Cards.begin();// �������� �� �������, ���������� ��� ������ � ����
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        delete *iter;
        *iter = 0;
    }
    m_Cards.clear();// ������� ������ ����������
}

int Hand::GetTotal() const {
    if (m_Cards.empty()) {
        return 0;// ���� ���� � ���� ���, ���������� �������� 0
    } //���� ������ ����� ����� �������� 0, �� ��� ����� �������� �����: ������� �������� 0
    if (m_Cards[0]->GetValue() == 0) {
        return 0;
    } // ������� ����� ����� ���� ����, ������ ��� ���� 1 ����
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        total += (*iter)->GetValue();
    } // ����������, ������ �� ���� ���
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter) {
        if ((*iter)->GetValue() == Card::ACE)
        {
            containsAce = true;
        }
    }
    if (containsAce && total <= 11) { // ���� ���� ������ ��� � ����� �������� ���������, ��� ���� 11 �����
        total += 10;//��������� ������ 10 �����, ��������� �� ��� �������� �� ������ ��� �� ������ ����
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

    // ������� ����
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
