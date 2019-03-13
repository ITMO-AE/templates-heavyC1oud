#include <iostream>
#include <vector>
#include <map>

using namespace std;

template <typename T>

vector<T> sqr(const vector<T> &data)
{
    vector<T> a;

    for(auto i: data) {
        a.push_back(i * i);
    }

    return a;
}


template <typename T>
T sqrMember(const T &data)
{
    T a;

    a = data * data;

    return a;
}


template <typename T, typename Y>
pair<T, Y> sqrMember(const pair<T, Y> &data)
{
    pair<T, Y> a;

    a.first = data.first * data.first;
    a.second = data.second * data.second;

    return a;
}


template <typename T, typename Y>
map<T, Y> sqr(const map<T, Y> &data)
{      
    map<T, Y> a;
    pair<T, Y> b;

    auto beginIt = data.begin();
    auto endIt = data.end();

    for(auto i = beginIt; i != endIt; i++) {
        //  копирование элемента контейнера map в контейнер pair
        b = *i;

        //  возведение в квадрат второго элемента
        b.second = b.second * b.second;

        //  заполнение выходного контейнера
        a.insert(b);
    }

    return a;
}


template <typename T, typename Y, typename Z>
map<T, pair<Y, Z>> sqr(const map<T, pair<Y, Z>> &data)
{
    map<T, pair<Y, Z>> a;
    pair<T, pair<Y, Z>> b;

    auto beginIt = data.begin();
    auto endIt = data.end();

    for(auto i = beginIt; i != endIt; i++) {
        //  копирование элемента контейнера map в контейнер pair
        b = *i;

        //  возведение в квадрат каждого элемента пары
        b.second.first = b.second.first * b.second.first;
        b.second.second = b.second.second * b.second.second;

        //  заполнение выходного контейнера
        a.insert(b);
    }

    return a;
}



int main()
{
    vector<int> v = {1, 2, 3};

    cout << "vector:";

    for (int x : sqr(v)) {
      cout << ' ' << x;
    }
    cout << endl;


    map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
    };

    cout << "map of pairs:" << endl;

    for (const auto& x : sqr(map_of_pairs)) {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
