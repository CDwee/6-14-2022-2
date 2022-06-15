// Started at 8:17 6-14-2022

// Section 13
// Static class members
#include <iostream>
#include "Player.h"

using namespace std;

void display_active_players() {
    cout << "Active players: " << Player::get_num_players() << endl;
}

int main() {
    display_active_players();
    Player hero{"Hero"};
    display_active_players();
    
    {
        Player frank{"Frank"};
        display_active_players();
    }
    display_active_players();
    
    Player *enemy = new Player{"Enemy", 100, 100};
    display_active_players();
    delete enemy;
    display_active_players();
    
    return 0;
}

#include "Player.h"

int Player::num_players{0};

Player::Player(std::string name_val, int health_val, int xp_val) 
    : name{name_val}, health{health_val}, xp{xp_val} {
        ++num_players;
}

Player::Player(const Player &source)
       : Player {source.name, source.health, source.xp}  {
}

Player::~Player() {
    --num_players;
}

int Player::get_num_players() {
    return num_players;
}

#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <string>

class Player
{
private:
   static int num_players;
   std::string name;
   int health;
   int xp;
public:
    std::string get_name() { return name; }
    int get_health() { return health; }
    int get_xp() {return xp; } 
    Player(std::string name_val ="None", int health_val = 0, int xp_val = 0);
    // Copy constructor
    Player(const Player &source);
    // Destructor
    ~Player();
    
    static int get_num_players();
    
};

#endif // _PLAYER_H_

#include <iostream>
#include "Movies.h"

void increment_watched(Movies &movies, std::string name);
void add_movie(Movies &movies, std::string name, std::string rating, int watched);

void increment_watched(Movies &movies, std::string name) {
    if (movies.increment_watched(name)) {
        std::cout << name << " watch incremented" <<  std::endl;
    } else {
        std::cout << name << " not found" <<  std::endl;
    }
}

void add_movie(Movies &movies, std::string name, std::string rating, int watched) {
    if (movies.add_movie(name,rating,watched)) {
        std::cout << name << " added" << std::endl;
    } else {
        std::cout << name << " already exists" <<  std::endl;
    }
}

int main() {
    
    Movies my_movies;
    
    my_movies.display();
    
    add_movie(my_movies, "Big", "PG-13",2);
    add_movie(my_movies,"Star Wars", "PG",5);
    add_movie(my_movies,"Cinderella", "PG",7);
     
    my_movies.display();
    
    add_movie(my_movies,"Cinderella", "PG",7);
    add_movie(my_movies,"Ice Age", "PG",12);
 
    my_movies.display();
    
    increment_watched(my_movies,"Big");
    increment_watched(my_movies,"Ice Age");
    
    my_movies.display();
    
    increment_watched(my_movies,"XXX");

	return 0;
}

#ifndef _MOVIES_H_
#define _MOVIES_H_
#include <vector>
#include <string>
#include "Movie.h"

class Movies
{
private:
    std::vector<Movie> movies;
public:
    Movies();
    ~Movies();
    
    bool add_movie(std::string name, std::string rating, int watched);
    
    bool increment_watched(std::string name);
    
    void display() const;
};

#endif // _MOVIES_H_

#include <iostream>
#include "Movies.h"

Movies::Movies() {
}

Movies::~Movies() {
}

bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // you implement this method
    return false;
}

bool Movies::increment_watched(std::string name) {
   // you implement this method
   return false;
}

void Movies::display() const {
   // You implement this method
}

#ifndef _MOVIE_H_
#define _MOVIE_H_

#include <string>

class Movie
{
private:
    std::string name;
    std::string rating;
    int watched;
public:
    
    Movie(std::string name, std::string rating, int watched);

    Movie(const Movie &source); 

    ~Movie();
    
    void set_name(std::string name) {this->name = name; }
    std::string get_name() const { return name; }
    
    void set_rating(std::string rating) {this->rating = rating; }
    std::string get_rating() const { return rating; }
    
    void set_watched(int watched) {this->watched = watched; }
    int get_watched() const { return watched; }

    void increment_watched() { ++watched; }

    void display() const;
};

#endif // _MOVIE_H_

#include <iostream>
#include "Movie.h"

Movie::Movie(std::string name, std::string rating, int watched) 
    : name(name), rating(rating), watched(watched)  {
}

Movie::Movie(const Movie &source) 
    : Movie{source.name, source.rating, source.watched} {
}

Movie::~Movie() {
}

void Movie::display() const {
    std::cout << name << ", " << rating <<  ", " << watched  <<   std::endl;
}

// Ended at 10:24 6-14-2022
