#include <iostream>
#include <string>
#include <vector>

class Spell {
  private:
    std::string scrollName;

  public:
    Spell() : scrollName("") {}
    Spell(std::string name) : scrollName(name) {}
    virtual ~Spell() {}
    std::string revealScrollName() {
        return scrollName;
    }
};

class Fireball : public Spell {
  private:
    int power;

  public:
    Fireball(int power) : power(power) {}
    void revealFirepower() {
        std::cout << "Fireball: " << power << '\n';
    }
};

class Frostbite : public Spell {
  private:
    int power;

  public:
    Frostbite(int power) : power(power) {}
    void revealFrostpower() {
        std::cout << "Frostbite: " << power << '\n';
    }
};

class Thunderstorm : public Spell {
  private:
    int power;

  public:
    Thunderstorm(int power) : power(power) {}
    void revealThunderpower() {
        std::cout << "Thunderstorm: " << power << '\n';
    }
};

class Waterbolt : public Spell {
  private:
    int power;

  public:
    Waterbolt(int power) : power(power) {}
    void revealWaterpower() {
        std::cout << "Waterbolt: " << power << '\n';
    }
};

class SpellJournal {
  public:
    static std::string journal;
    static std::string read() {
        return journal;
    }
};
std::string SpellJournal::journal = "";

// My Code
void counterspell(Spell *spell) {
    if (dynamic_cast<Fireball *>(spell)) {
        dynamic_cast<Fireball *>(spell)->revealFirepower();
    } else if (dynamic_cast<Frostbite *>(spell)) {
        dynamic_cast<Frostbite *>(spell)->revealFrostpower();
    } else if (dynamic_cast<Waterbolt *>(spell)) {
        dynamic_cast<Waterbolt *>(spell)->revealWaterpower();
    } else if (dynamic_cast<Thunderstorm *>(spell)) {
        dynamic_cast<Thunderstorm *>(spell)->revealThunderpower();
    } else {
        std::string X = spell->revealScrollName();
        std::string Y = SpellJournal::journal;
        int m = X.size();
        int n = Y.size();
        int L[m + 1][n + 1];
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (!i || !j)
                    L[i][j] = 0;
                else if (X[i - 1] == Y[j - 1])
                    L[i][j] = L[i - 1][j - 1] + 1;
                else
                    L[i][j] = std::max(L[i - 1][j], L[i][j - 1]);
            }
        }
        std::cout << L[m][n] << '\n';
    }
}
// End My Code

class Wizard {
  public:
    Spell *cast() {
        Spell *spell;
        std::string s;
        std::cin >> s;
        int power;
        std::cin >> power;
        if (s == "fire") {
            spell = new Fireball(power);
        } else if (s == "frost") {
            spell = new Frostbite(power);
        } else if (s == "water") {
            spell = new Waterbolt(power);
        } else if (s == "thunder") {
            spell = new Thunderstorm(power);
        } else {
            spell = new Spell(s);
            std::cin >> SpellJournal::journal;
        }
        return spell;
    }
};

int main() {
    int T;
    std::cin >> T;
    Wizard Arawn;
    while (T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}