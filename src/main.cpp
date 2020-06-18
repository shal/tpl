#include <iostream>
#include <string>
#include <functional>
#include <vector>

using namespace std;

// Polymorphic class.
template<typename T>
class Functor {
public:
    T operator () (T x) {
        return x;
    }
};

// Function that takes polymorphic functor as an argument.
template<template<typename T> class G>
pair<int,double> some_func()
{
    return make_pair(G<int>()(1), G<double>()(1.1));
}

// Is it possible to pass function template into such construction?
// No, only functors can be used.

int main(int argc, char* argv[])
{
    pair<int, double> res = some_func<Functor>();
    cout << res.first << " " << res.second << endl; // => 1 1.1

    return 0;
}