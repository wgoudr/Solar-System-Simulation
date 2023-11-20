This program simulates asteroids passing through the solar system. The asteroids are the white circles and the planets are the red circles. This program uses the sfml library to draw the objects in motion. when you run the program a fullscreen window pops up and you can see a row of asteroids flying through the solar system towards the sun. The red circle in the center represents the sun, and the other red circles that orbit around the center represent the planets; the planets present are Mercury, Venus, Earth, Mars, Jupiter, Uranus, and Neptune. 

The important files is the main, and the two header fles which contain the class definitions. 

The simulation is a work in progress and needs more work. Here are some notes on what could possibly be changed or added in the future: 

// !! NOTES !!
// In sfml you can create a vector with 2 float elements x and y
// velocity is calculated based on framerates, because its a measure of time. speed = d(position)/d(frame rate)
// we assume the mass to be 1 for all objects (for now...)
// change the strength to mass for both objects
// create unique objects for each planet
// add hit detection between asteroid and planets
// add random asteroid velocities, starting positions, and mass
// add trails to asteroid for visual clarity
// make each shape a different size
// change scales and distance to better reflect size of solar system
// take real data from planets and change shape of orbits