#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>


// gravity has position, a strength and a shape. This can be a planet
class Planet {

    float orbital_r = 50.0;
    float orbital_t = 365.0;
    float initial_x = 0;
    float initial_y = 0;
    float theta = 0;
    float strength;
    sf::Vector2f pos;
    sf::CircleShape s;

    // creating gravity objects takes x, y coordinates, a field gravity field strength value, a orbit radius
public:
    Planet(float pos_x, float pos_y, float strength, float orbital_radius, float orbital_time) {
        pos.x = pos_x;
        pos.y = pos_y;
        orbital_r = orbital_radius;
        orbital_t = orbital_time;
        initial_x = pos_x;
        initial_y = pos_y;
        this->strength = strength;

        // after the object is made, set the shape's position, color, and radius using sfml
        s.setPosition(pos);
        s.setFillColor(sf::Color::Red);
        s.setRadius(10);
    }

    void update_position() {
        // update the position of the gravitational source // x = x + rcos(theta + 1) //increment of time
        theta = theta + 1 / orbital_t;
        pos.x = initial_x + orbital_r * cos(theta);
        pos.y = initial_y + orbital_r * sin(theta);
    }

    // inside in the window, render the created gravity source object
    void render(sf::RenderWindow& grav_source) {
        s.setPosition(pos);
        grav_source.draw(s);
    }

    // get position of grav source
    sf::Vector2f get_pos() {
        return pos;
    }

    // get strength of grav source
    float get_strength() {
        return strength;
    }
};