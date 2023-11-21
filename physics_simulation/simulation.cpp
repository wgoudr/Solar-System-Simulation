#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include "Planet_Class.h"
#include "Asteroid_class.h"


const double PI = 3.1415926535897932384626433832795028841971693993751058209;

// !! MAIN !!
// create a window and set size and  set the frame rate of the window
// for every loop, update physics and update the figures to be drawn according to update physics
// create planets and asteroids with different positions in the window
int main(){
    
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SIMULATION OF ASTEROIDS TRAVELING THROUGH THE SOLAR SYSTEM", sf::Style::Fullscreen);
    window.setFramerateLimit(120);

    // making each planet of the solar system   
    Planet the_sun(960-12.5, 540-12.5, 75, 0.1, 365, 25);
    Planet mercury(960, 540, 10, 60, 100);
    Planet venus(960, 540, 10, 85, 565);
    Planet earth(960, 540, 10, 125, 365);
    Planet mars(960, 540, 10, 200, 265);
    Planet jupiter(960, 540, 10, 275, 665);
    Planet saturn(960, 540, 10, 350, 765);
    Planet neptune(960, 540, 10, 425, 865);
    Planet uranus(960, 540, 10, 500, 1100);

    // adding each planet to a vector 
    std::vector<Planet> sources;
    sources.push_back(the_sun);
    sources.push_back(mercury);
    sources.push_back(venus);
    sources.push_back(earth);
    sources.push_back(mars);
    sources.push_back(jupiter);
    sources.push_back(saturn);
    sources.push_back(neptune);
    sources.push_back(uranus);        

    // set the number of asteroids you want and loop through a set of asteroids and assign to them different speed values
    float num_asteroids = 3000;
    std::vector<Asteroid> asteroids; 
    
    for (int i = 0; i < num_asteroids; i++) {
        asteroids.push_back(Asteroid(0, 0 + (1050.f/num_asteroids)*i, 0.1, 0));    //divide grid size by asteroids for equal distance between        
    }

    // update the window for every frame
    while (window.isOpen()){

        // check for event to close the game, either press Esc or click X button in top right (not possible in fullscreen)
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }   

        window.clear();

        // for every frame, for every source, apply the physics update for every asteroid
        // this is like taking the sum of forces and finding the resulting force applied on the asteroid        

        for (int i = 0; i < sources.size(); i++) {
            sources[i].update_position();

            for (int j = 0; j < asteroids.size(); j++){
                asteroids[j].update_physics(sources[i]);
            }
        }        

        // for every update you have to render the new position of the planets and the asteroids again
        for (int i = 0; i < sources.size(); i++){
            sources[i].render(window);
        }
        for (int j = 0; j < asteroids.size(); j++){
            asteroids[j].render(window);
        }        

        // display the window for the user
        window.display();
    }
    

    return 0;
}