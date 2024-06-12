## Part 1: Overview

- Sketch of electronics that is annotated (and what each part does)

The electronic components in Flooded House have three main functions:
- **_The Interface_** collects the user's selection of the climate scenario. The selectin contains 6 buttons - each one represents a location around the world, potentiometer with which users can select a year, and a potentiometer with which users can select a predicted temperature increase. A "Enter" button allows users to start the visualization.
- **_The Water Height Measurement_** consists of many transistors and constantly measures the water height inside the aquarium tp report it back to the Arduino. [The electronics for this are not very elegant unfortunately...]
- **_The Water System_**, made up of water pumps, transistors, and capacitors pump water into the aquarium or out of it, depending on the user selection, and the water height. 


## Part 2: Interface
- 2 x [Sliding Potentiometers](https://www.adafruit.com/product/4219)
- 6 x [Illuminated Pushbutton](https://www.adafruit.com/product/1479)
- 2 x [7-segment display with I2C Backpack](https://www.adafruit.com/product/1002)
- 2 x [Stemma QT-connector wires](https://www.adafruit.com/product/4210)
- 1 x [Arcade Button](https://www.adafruit.com/product/492)
- 2 x Regular 4mm LED's in Blue and Green
- 2 x 220Ω Resistor for LED

## Part 3: Water Height Measurement

Water Height
Thin Wire
2222a Transistors
Circuit Diagram

## Part 4: Water System

Water Pumps:
Power supply
2 water pumps
Capacitors
Transistors
Resistors
Flyback Diode

## Part 5: Power Supply + Putting everything together

Arduino Mega + Power supply + Soldering hat thing
Silicone Wire
Heat Shrinks, Solder etc. 
Wago Connectors
Barrel Jack Connectors

## Part 6: Code!
[Find Commented Arduino Code Here](/Electronics/Code)


