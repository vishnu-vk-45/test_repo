#include <iostream>
#include <string>
#include "Random.h"
using namespace std;

class Creature
{
    protected:
        string m_name;
        char m_symbol;
        int m_health;
        int m_damageAmount;
        int m_goldAmount;

    public:

        Creature(const string& name,char symbol,int health,int damageAmount,int goldAmount)
            :m_name{name},m_symbol{symbol},m_health{health},m_damageAmount{damageAmount},
             m_goldAmount{goldAmount} {}

        const string& getName() const {return m_name;}
        char getSymbol() const {return m_symbol;}
        int getHealth() const {return m_health;}
        int getDamage() const {return m_damageAmount;}
        int getGold() const {return m_goldAmount;}

        void reduceHealth(int health) {m_health -= health;}
        bool isDead() {return m_health <= 0 ? true : false;}
        void addGold(int gold) {m_goldAmount += gold;}


};

class Player : public Creature
{
    protected:
        int m_level{1};
        
    public:
        Player(const string& name)
            : Creature{name,'@',10,1,0} {}
        
        void levelUp() {
            m_level++;
            m_damageAmount++;
        }

        int getLevel() const {return m_level;}
        bool hasWon() {return m_level == 20 ? true : false;}

};

class Monster :  public Creature
{
    public:
        enum Type
        {
            dragon,
            orc,
            slime,
            max_types

        };

    private:
        inline static Creature monsterData[] {
            Creature {"dragon",'D',20,4,100},
            Creature {"orc",'o',4,2,25},
            Creature {"slime",'s',1,14,10},
            
        };


    public:
        Monster(Type type)
            :Creature{monsterData[type]} {}

        static Monster getRandomMonster()
        {
            return static_cast<Type>(Random::get(0,max_types-1));
        }
    
};

void attackPlayer(Player& player, Monster& m)
{
         
    player.reduceHealth(m.getDamage());
    cout<<"The "<<m.getName()<<" hit you for "<<m.getDamage()<<" damage.\n";
}

void attackMonster(Player& player, Monster& m)
{
    if(player.isDead())
        return;

    m.reduceHealth(player.getDamage());
    cout<<"You hit the "<<m.getName()<<" for "<<player.getDamage()<<" damage.\n";

    if(m.isDead())
    {
        player.levelUp();
        player.addGold(m.getGold());
        cout<<"You killed the "<<m.getName()<<".\n";
        cout<<"You are now level "<<player.getLevel()<<".\n";\
        cout<<"You found "<<m.getGold()<<" gold.\n";
    }

    else
    {
        if(!m.isDead())
            attackPlayer(player,m);
        else
            return;
    }

}



void fightMonster(Player& player)
{
    Monster m (Monster::getRandomMonster());
    cout << "You have encountered a " <<m.getName()<<" ("<<m.getSymbol()<<").\n";

    while(!m.isDead() && !player.isDead())
    {
        char option;
        cout<<"(R)un or (F)ight: ";
        cin>>option;

        if(option == 'r' || option == 'R')
        {
            if(Random::get(1,2) == 1)
            {
                cout<<"You successfully fled.\n";
                // fightMonster(player);
                return;
            }
            else
            {
                cout<<"You failed to flee.\n";
                attackPlayer(player,m);
                continue;
            }
        }
        else
        {
            if(option == 'F' || option == 'f')
            {
                attackMonster(player,m);
            }
        } 

    }
    
}

int main()
{
	string player_name;
    cout<<"Enter your name: ";
    cin>>player_name;
    Player p1 {player_name};
    cout<<"Welcome, "<<player_name<<endl;

    while(!p1.isDead() && !p1.hasWon())
    {
        fightMonster(p1);

    }

    if(p1.isDead())
    {
        cout<<"You died at level "<<p1.getLevel()<<" and with "<<p1.getGold()<<" gold.\n";
        cout<<"Too bad you can\'t take it with you!\n";

    }

    else
    {
        cout<<"You won the match with "<<p1.getGold()<<" gold.";
    }

	return 0;

}