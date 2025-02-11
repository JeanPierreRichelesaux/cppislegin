#include<iostream>
#include<string>
#include<vector>

class Vet;

class Animal {
    friend Vet;

    int health = 100;
public:
    unsigned age;
    std::string name;
    std::string breed;
    virtual void makeSound() = 0;
    void info() {
        std::cout << "Name: " << name << "\nBreed: " << breed << "\nAge: " << age <<"\n";
    }

    Animal(unsigned page, std::string pname, std::string pbreed){
        age = page;
        name = pname;
        breed = pbreed;
    }
};

class Dog : public Animal {
    friend Vet;
public:
    void makeSound() override {
        std::cout << name << " says: Borf.\n";
    }

    Dog(unsigned page, std::string pname, std::string pbreed) : Animal(page, pname, pbreed) {}
};

class Cat : public Animal {
    friend Vet;
public:
    void makeSound() override {
        std::cout << name << " says: You betrayed Christ.\n";
    }

    Cat(unsigned page, std::string pname, std::string pbreed) : Animal(page, pname, pbreed) {}
};

struct Fio {
    std::string surname;
    std::string name;
    std::string patronymic;

    Fio(std::string psurname, std::string pname, std::string ppatron) {
        surname = psurname;
        name = pname;
        patronymic = ppatron;
    }

    std::string person() {
        return surname + " " + name + " " + patronymic;
    }
};

class Owner {
public:
    Fio fio;
    unsigned age;
    unsigned n_pets = 0;
    std::vector<Animal*> pets;

    void adopt(Animal* stray) {
        pets.push_back(stray);
        n_pets++;
        std::cout << fio.person() << " adopts " << stray->name << "!\n";
    }

    Owner(std::string psurname, std::string pname, std::string ppatron, unsigned page) : fio(psurname, pname, ppatron) {
        age = page;
    }
};

class Vet {
    Fio fio;
public:
    void inspect(Animal* pet) {
        std::cout << fio.person() << " concluded that " << pet->name << " is at " << pet->health << " health!\n";
    }

    void heal(Animal* pet) {
        pet->health += 10;
        std::cout << fio.person() << " heals " << pet->name << " for 10!\n";
    }

    void talkTo(Owner man) {
        std::cout << fio.person() << " talks with " << man.fio.person() << "!\n";
    }

    Vet(std::string psurname, std::string pname, std::string ppatron) : fio(psurname, pname, ppatron) {}
};

int main() {
    Dog pet1 = Dog(3, "Bob", "Samoyed");
    Cat pet2 = Cat(1, "Orion", "Derevensky");
    pet1.info();
    pet1.makeSound();
    pet2.info();
    pet2.makeSound();
    Owner owner1 = Owner("Vasilievskii", "Alexander", "Alexeevich", 19);
    owner1.adopt(&pet1);
    owner1.adopt(&pet2);
    Vet vet1 = Vet("Vasilieva", "Tatiana", "Ivanovna");
    vet1.inspect(&pet2);
    vet1.heal(&pet2);
    vet1.inspect(&pet2);
    vet1.talkTo(owner1);
}
