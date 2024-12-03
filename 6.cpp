#include<iostream>
#include<string>
#include<map>
#include<typeinfo>

class SpellBook;

class Spell{
public:
    std::string name;
    std::string description;
    virtual void readSpell(){}
    Spell(std::string pname, std::string desc) : name(pname), description(desc) {}
};

class Wizard;
class Warlock;
class Herbalist;
class Domovoy;

class WaterSpell : public Spell{
    WaterSpell(std::string pname, std::string desc) : Spell(pname, desc) {}
    void readSpell() override{
        std::cout << "Water spell '" << name << "': " << description << "\n";
    }
    friend Warlock;
    friend Herbalist;
    friend Domovoy;
};

class EarthSpell : public Spell{
    EarthSpell(std::string pname, std::string desc) : Spell(pname, desc) {}
    void readSpell() override{
        std::cout << "Earth spell '" << name << "': " << description << "\n";
    }
    friend Warlock;
    friend Herbalist;
    friend Domovoy;
};

class FireSpell : public Spell{
    FireSpell(std::string pname, std::string desc) : Spell(pname, desc) {}
    void readSpell() override{
        std::cout << "Fire spell '" << name << "': " << description << "\n";
    }
    friend Warlock;
    friend Herbalist;
    friend Domovoy;
};

class AirSpell : public Spell{
    AirSpell(std::string pname, std::string desc) : Spell(pname, desc) {}
    void readSpell() override{
        std::cout << "Air spell '" << name << "': " << description << "\n";
    }
    friend Warlock;
    friend Herbalist;
    friend Domovoy;
};

class SpellBook{
    std::map<std::string, Spell*> spells;
    public:
    void writeSpell(Spell& sp){
        if(spells.contains(sp.name)){
            throw std::out_of_range("SpellAlreadyWritten");
        }
        spells[sp.name] = &sp;
    }
    void eraseSpell(std::string nam){
        if(!spells.contains(nam)){
            throw std::out_of_range("SpellNotFound");
        }
        spells.erase(nam);
    }
    void readSpell(std::string nam){
        if(!spells.contains(nam)){
            throw std::out_of_range("SpellNotFound");
        }
        (*spells[nam]).readSpell();
    }
    friend Wizard;
};

class Wizard{
    public:
    virtual WaterSpell createWaterSpell() = 0;
    virtual EarthSpell createEarthSpell() = 0;
    virtual FireSpell createFireSpell() = 0;
    virtual AirSpell createAirSpell() = 0;
};

class Warlock : public Wizard{
    public:
    const std::string type = "Warlock";
    virtual WaterSpell createWaterSpell() override{
        return WaterSpell("Evaporation", "Thy enemy's eyes shalt be lacking humidity.");
    }
    virtual EarthSpell createEarthSpell() override {
        return EarthSpell("Quicksand", "Maketh the ground tremble beneath vile folk.");
    }
    virtual FireSpell createFireSpell() override {
        return FireSpell("Fire arrow", "Launcheth a swift missile of flames.");
    }
    virtual AirSpell createAirSpell() override {
        return AirSpell("Whirlwind", "A fierce storm appears at thy will.");
    }
    template<typename T>
    friend T callWizard();
};

class Herbalist : public Wizard{
    public:
    const std::string type = "Herbalist";
    virtual WaterSpell createWaterSpell() override{
        return WaterSpell("Summon: water", "A mighty water elemental shalt be thoust guard.");
    }
    virtual EarthSpell createEarthSpell() override {
        return EarthSpell("Skin Petrification", "Your flesh becomes resilient to any harm.");
    }
    virtual FireSpell createFireSpell() override {
        return FireSpell("Firewall", "None treacherous vermin shalt pass through!");
    }
    virtual AirSpell createAirSpell() override {
        return AirSpell("Discombobulate", "Striketh enemy's ears with a shockwave to stun them.");
    }
    template<typename T>
    friend T callWizard();
};

class Domovoy : public Wizard{
    public:
    const std::string type = "Domovoy";
    virtual WaterSpell createWaterSpell() override{
        return WaterSpell("Aquatic creation", "Fill a small vial with pure water.");
    }
    virtual EarthSpell createEarthSpell() override {
        return EarthSpell("Pottery", "An intricate clay vessel is brought into existence.");
    }
    virtual FireSpell createFireSpell() override {
        return FireSpell("Bonfire", "Light a piece of wood on fire.");
    }
    virtual AirSpell createAirSpell() override {
        return AirSpell("Aerial affinity","A light breeze enhances thoust swiftness and dexterity.");
    }
    template<typename T>
    friend T callWizard();
};

template<typename T>
T callWizard(){
    std::cout << "A " << T().type << " is called to arms!\n";
    return T();
}

int main(){
    Warlock Merlin = callWizard<Warlock>();
    EarthSpell spell1 = Merlin.createEarthSpell();
    AirSpell spell2 = Merlin.createAirSpell();
    Domovoy Kuzya = callWizard<Domovoy>();
    AirSpell spell3 = Kuzya.createAirSpell();
    SpellBook book;
    try{
        book.writeSpell(spell1);
        book.readSpell("Quicksand");
        book.writeSpell(spell2);
        //book.writeSpell(spell2);
        book.readSpell("Whirlwind");
        book.writeSpell(spell3);
        book.readSpell("Aerial affinity");
        book.eraseSpell("Aerial affinity");
        //book.readSpell("Aerial Affinity");
    }
    catch(std::out_of_range& s) {
        std::cout << "Exception: " << s.what() << "!\n";
    }
}