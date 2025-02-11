#include<iostream>
#include<string>
using namespace std;

class Student
{
    private:
    const string name;
    const string surname;
    unsigned group;
    unsigned age;
    int hp;
    int money;
    int time;
    int stud_time;

    public:
    unsigned score;

    Student(string p_name, string p_surname, unsigned p_group, unsigned p_age) : name(p_name), surname(p_surname)
    {
        group = p_group;
        age = p_age;
        money = 1000;
        hp = 90;
        time = 16;
        stud_time = 10;
        score = 10;
        cout << "A hero was born.\n";
    }

    Student(string p_name, string p_surname, unsigned p_group, unsigned p_age, unsigned p_score) : name(p_name), surname(p_surname)
    {
        group = p_group;
        age = p_age;
        money = 800;
        hp = 100;
        time = 16;
        stud_time = 10;
        score = p_score;
    }

    void food()
    {
        if(money <= 0)
        {
            cout << "Come back when you're a little, mmmm, richer!\n";
        }
        else
        {
            hp += 10;
            money -= 300;
            time -= 1;
        }
    }

    void shawarma()
    {
        if(money <= 0)
        {
            cout << "In terms of money... You have no money.\n";
        }
        else
        {
            hp += 10;
            money -= 300;
            time -= 1;
            if(time <= 1)
            {
                hp -= 15;
            }
        }
    }

    void botay(unsigned hours)
    {
        time -= hours;
        hp -= 2 * hours;
        if(stud_time >= 24)
        {
            hp -= 4 * hours;
        }
        stud_time += hours;
    }

    void rabotay(unsigned hours)
    {
        time -= hours;
        money += 700 * hours;
        hp -= 3 * hours;
        if(stud_time >= 24)
        {
            hp -= 6 * hours;
        }
    }

    void sleep(unsigned hours)
    {
        hp += 2 * hours;
        if (hours > 6)
        {
            stud_time = 0;
        }
    }

    void funny(unsigned hours)
    {
        if(money <= 0)
        {
            cout << "No money?\n";
        }
        else
        {
            time -= hours;
            money -= 100 * hours;
            if(stud_time > 24)
            {
                hp += 5 * hours / 3;
            }
            else
            {
                hp += 5 * hours;
            }
        }
    }

    void nk(unsigned hours)
    {
        time -= hours;
        hp += 10;
        if(hours >= 3)
        {
            hp -= 20;
            stud_time = 0;
            cout << "You woke up next day in your friend's room.\n";
            cout << "You don't remember anything from the night.\n";
        }
    }

    void myHP()
    {
        if(hp > 0)
        {
            cout << "You have " << hp << " health!\n";
        }
        else
        {
            cout << "Ушёл в академ, gone but not forgor...\n";
        }
    }

    void myMoney()
    {
        cout << "You have " << money << " money!\n";
        if(money < 0)
        {
            cout << "You better pay your debts, friend.\n";
        }
    }

    void myTime()
    {
        cout << "You have " << time << " hours left this day!\n";
    }

    void myInfo()
    {
        cout << "You are " << name << " " << surname << " .\n";
        cout << "You are in " << group << " group.\n";
        cout << "You are " << age << " years old.\n";
        cout << "You have " << hp << " health.\n";
        cout << "You have " << money << " money.\n";
        cout << "You have " << time << " hours left this day.\n";
        cout << "Your student time is " << stud_time << " .\n";
    }
};

int main()
{
}
