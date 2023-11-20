#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Planet_Class.h"


// object class for an asteroid with a position, velocity, and a shape
// takes coordinates and velocies for the asteroid
class Asteroid
{
    sf::Vector2f pos;
    sf::Vector2f vel;
    sf::CircleShape s;

public:
    Asteroid(float pos_x, float pos_y, float vel_x, float vel_y) {
        pos.x = pos_x;
        pos.y = pos_y;

        vel.x = vel_x;
        vel.y = vel_y;

        //set the position, color and radius of the asteroid in the rendered window
        s.setPosition(pos);
        s.setFillColor(sf::Color::White);
        s.setRadius(3);
    }

    // set the position of the asteroid draw it every time the window updates
    void render(sf::RenderWindow& asteroid) {
        s.setPosition(pos);
        asteroid.draw(s);
    }

    // you can dynamically change the color of the asteroid as it changes velocity, not always needed
    void set_color(sf::Color col) {
        s.setFillColor(col);
    }

    // every time the window updates, you need to update the velocity and position of asteroid based on the physics
    void update_physics(Planet& s) {

        //using trig, the pythagorean theorem, update the velocity of the asteroid
        // x0 - x1 and y0 - y1 to find relative distance
        float distance_x = s.get_pos().x - pos.x;
        float distance_y = s.get_pos().y - pos.y;

        //pythagorean theorem to find c in c^2 = a^2 + b^2
        float distance = sqrt(distance_x * distance_x + distance_y * distance_y);

        // finding the normalized components of the distance so we know what the diretion is without the distance magnitude
        // this is useful for everything else because it gives the angle of asteroid without needing to know the cos or sin
        float inverse_distance = 1.f / distance;
        float normalized_x = inverse_distance * distance_x;
        float normalized_y = inverse_distance * distance_y;

        //finding the acceleration caused by the gravitational source using the inverse square law F = m*a/r^2
        // for this equation, the mass of both objects are 1
        float inverse_square_law = inverse_distance * inverse_distance;
        float acceleration_x = normalized_x * s.get_strength() * inverse_square_law;
        float acceleration_y = normalized_y * s.get_strength() * inverse_square_law;

        // the asteroid is subject to a force produced by the gravity source object and the force is equal the strengh in the GravitySource class
        // finally update the position and the velocity of the asteroid, F = m*a --> m = 1 ---> F = dv/dt 
        // dt = change in time = change in frame rate = 1 frame per update
        // for velocity: a = dv/dt ---> dt * a = dv ---> dt * a  = v1 - v0 (change in v) ---> v1 = 1 * a + v0
        // for position: v = dr/dt ---> dt * v = dr ---> dt * v  = r1 - r0 (change in r) ---> r1 = 1 * v1 + r0
        vel.x += acceleration_x;
        vel.y += acceleration_y;
        pos.x += vel.x;
        pos.y += vel.y;
    }
};