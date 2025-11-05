#include<iostream>

namespace Monster
{
    enum Monstertype
    {
        orc,
        goblin,
        troll,
        ogre,
        skeleton,
    };
}



int main()
{
    Monster::Monstertype monster {Monster::troll};
}

