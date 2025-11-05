#ifndef PAIR_H
#define PAIR_H

template<typename T, typename U>
struct Pair
{
    T first;
    U second;
};

template<typename T,typename U>
constexpr T add(Pair<T,U> p)
{
    return p.first + p.second ;
}

#endif