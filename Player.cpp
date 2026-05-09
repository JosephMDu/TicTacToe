#include "Player.h"

Player::Player(std::string name, char piece) 
    : name_(name), piece_(piece) {
}

Player::~Player(){
}

char Player::getPiece() const {
    return piece_;
}

std::string Player::getName() const {
    return name_;
}

