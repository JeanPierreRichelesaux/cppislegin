#include<iostream>
#include<string>

class Animal {
    friend class Vet;

    private:
        int health = 0;

    public:
        unsigned age;
        std::string name;
        std::string breed;

        void data()
        {
            std::cout << "Age: " << age << "\nName: " << name << "\nBreed: " << breed << "\n";
        }

        virtual void makeSound(){}

        Animal(unsigned page, std::string pname, std::string pbreed) {
            name = pname;
            age = page;
            breed = pbreed;
        }
};

class Dog: public Animal {
    public:
        void makeSound() override{
            std::cout << "borf\n";
        }

        Dog(unsigned page, std::string pname, std::string pbreed): Animal(page, pname, pbreed){}
};

class Cat: public Animal {
    public:
        void makeSound() override{
            std::cout << "You betrayed Christ.\n";
        }

        Cat(unsigned page, std::string pname, std::string pbreed): Animal(page, pname, pbreed){}
};

class Owner {
    public:
        unsigned age;
        std::string fio;
        unsigned n_pets;
        Animal* pets;

        Owner(unsigned page, std::string pfio, unsigned pn_pets, Animal* ppets) {
            age = page;
            fio = pfio;
            n_pets = pn_pets;
            this->pets = ppets;
        }

        void data()
        {
            std::cout << "Age: " << age << "\nFio: " << fio << "\nNumber of pets: " << n_pets << "\n";
        }
};

class Vet {
    public:
        std::string fio;
    
        void talk(Owner subject) {
            std::cout << fio << " talks with " << subject.fio << ".\n";
        }

        void healthCheck(Animal subject) {
            std::cout << subject.name << "'s health is " << subject.health << ". (Diagnosed by " << fio << ").\n";
        }

        void heal(Animal &subject) {
            std::cout << fio << " heals " << subject.name << " for 3!\n";
            subject.health += 3;
        }

        Vet(std::string pfio) {
            fio = pfio;
        }
};

int main()
{
    Dog subject1{3, "Johny", "Samoyed"};
    Cat subject2{0, "Orion", "Derevensky"};
    subject1.data();
    subject1.makeSound();
    subject2.data();
    subject2.makeSound();
    Animal pets[]{subject1, subject2};
    Owner human{19, "Vasilevskii Alexander Alexeevich", 2, pets};
    Vet doctor{"Vasileva Tatiana Ivanovna"};
    doctor.healthCheck(subject2);
    doctor.heal(subject2);
    doctor.healthCheck(subject2);
    doctor.talk(human);
}