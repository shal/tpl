#include <iostream>
#include <string>
#include <functional>
#include <vector>

using namespace std;

// This is polymorphic function #1.
template <typename T>
bool is_integer(T arg)
{
    return false;
}

template <>
bool is_integer<int>(int arg)
{
    return true;
}

// This is polymorphic function #2.
template <typename T>
bool is_string(T arg)
{
    return false;
}

template <>
bool is_string<string>(string arg)
{
    return true;
}

// Implement in C++ function that takes polymorphic function as an argument.
template <typename T>
vector<bool> check_each(vector<T> arr, bool (*check)(T))
{
    vector<bool> res;
    for (auto x : arr) {
        res.push_back(check(x));
    }

    return res;
}

void example_works()
{
    vector<int> input1({ 1, 10, 20 });

    cout << "is_integer<int>: ";
    for (auto x : check_each(input1, is_integer)) {
        cout << (x ? "yes" : "no") << " ";
    }
    cout << endl;

    cout << "is_string<int>: ";
    for (auto x : check_each(input1, is_string)) {
        cout << (x ? "yes" : "no") << " ";
    }
    cout << endl;

    cout << "is_integer<string>: ";
    vector<string> input2({ "hello", "this", "is", "strings" });

    for (auto x : check_each(input2, is_integer)) {
        cout << (x ? "yes" : "no") << " ";
    }
    cout << endl;

    cout << "is_string<string>: ";
    for (auto x : check_each(input2, is_string)) {
        cout << (x ? "yes" : "no") << " ";
    }
    cout << endl;
}

// 1. Is it possible to pass function template into such construction?
// Yes. Use examples_works().

// 2. What is the main difference with Haskell?
// Haskell is functional language, it has different type system.

// 3. Why std::function objects cannot be used?
// Directly no, because can't get a function pointer out of an std::function.
//
// void example_does_not_work() {
//     vector<string> input({ "1", "2", "3" });

//     function<bool(string)> is_str = [](string) { return true; };
//     for (auto x : check_each<string>(input, is_str)) {
//         cout << (x ? "yes" : "no") << endl;
// 	}
// }

int main(int argc, char* argv[])
{
    example_works();
    // example_does_not_work();

    return 0;
}