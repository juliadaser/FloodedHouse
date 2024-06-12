## Part 1: Overview

Sketch of electronics that is annotated (and what each part does)

The electronic components in Flooded House have three main functions:
- **_The Interface_** collects the user's selection of the climate scenario. The selectin contains 6 buttons - each one represents a location around the world, potentiometer with which users can select a year, and a potentiometer with which users can select a predicted temperature increase. A "Enter" button allows users to start the visualization.
- **_The Water Height Measurement_** consists of many transistors and constantly measures the water height inside the aquarium tp report it back to the Arduino. [The electronics for this are not very elegant unfortunately...]
- **_The Water System_**, made up of water pumps, transistors, and capacitors pump water into the aquarium or out of it, depending on the user selection, and the water height. 


## Part 2: Interface

Sketch

- 2 x [Sliding Potentiometers](https://www.adafruit.com/product/4219)
- 6 x [Illuminated Pushbutton](https://www.adafruit.com/product/1479)
- 2 x [7-segment display with I2C Backpack](https://www.adafruit.com/product/1002)
- 2 x [Stemma QT-connector wires](https://www.adafruit.com/product/4210)
- 1 x [Arcade Button](https://www.adafruit.com/product/492)
- 2 x Regular 4mm LED's in Blue and Green
- 2 x 220Ω Resistor for LED

## Part 3: Water Height Measurement

Sketch

- 1 x [extra thin prototyping wire](https://www.adafruit.com/product/1446)
- 22 x [2n2222a transistor](https://www.amazon.com/dp/B0CRVGFN4R?psc=1&ref=ppx_yo2ov_dt_b_product_details)

## Part 4: Water System

Sketch

- 2 x [mini DC 6V-12V Water Pump](https://www.amazon.com/Gikfun-Aquarium-Cooled-Diaphragm-EK1856/dp/B0744FWNFR/ref=sr_1_8?crid=32KMANFREUB0E&dib=eyJ2IjoiMSJ9.J0Tx3kri4VOzRx4WEBbvFqtay5iG7ajseZqrG_dtkoebM9g6lP8WZgsmsSQusOCyx9zNqZKUEm4AOZAsuNBRDL_KEKx3fl4AlU-RHnunfjPtwnE9DVWMFh6hfjJi7kup9jggLzmP5qCKWlK50Vvs5VnWu9aJx-zCBwapUsVnUN7B3ZbiLiI17WJ2K0DV6cKRJMdsL_GMQBL6KhunZMsen87Lxazvq0yXjnUWTctHZlA6QviKqo2bmg8pZ-La4j5bEXsJDe9xVfi1WRDsWJOqwtabCaCHKBEaXNbetLuWrR4.hik8rEZ-_YLfcWAMrKjhWcLLEJ72LE4GUuT7xzYkr7Y&dib_tag=se&keywords=water+pumps+arduino+12V&qid=1718229218&sprefix=water+pumps+arduino+12v%2Caps%2C207&sr=8-8)
- 2 x [35V 1000uf Capacitor] (https://www.amazon.com/dp/B073YR6LVK?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- 2 x [Transistor????](...)
- 2 x [1N4007 Diode 1A 1000V](https://www.amazon.com/MIC-Silastic-Junction-Standard-Rectifier/dp/B07GQCSC7G/ref=sr_1_1?crid=8HQN89PY6UBR&dib=eyJ2IjoiMSJ9.TvZUWlEBgrSXw-JzElFmP2pdXry7HSf3z_nJwoRcKBOx2BVkbIJraiaTKOEq0ubZwZHHh8cKo0Zkedss0eEde7BKI0GKBz_LASY5qu1YE3qyB9uWY6sPVltY_CY-YpMZB-LKYO849kTmw0_WM1MwPbnVV7MFJ3eJ7XKFpT4yTToQYXGTIiOrIEzWwSRUyJNyNbOqmmp8k7NuwT8i9JP6pg-gIMX0KVbs9zr2OGo4DDGCIWaT2XMrTIpdRTszQyJTKTdX0TOb8JDCoIBxM-1bhJVPDR64cndRnAPy5PLed6k.I3HBXig6K8XixgVAtsY0jKmWt4OgEqCwLrA48Nceo9w&dib_tag=se&keywords=flyback+diode&qid=1718229378&s=industrial&sprefix=flybackdiode%2Cindustrial%2C222&sr=1-1)


## Part 5: Power Supply + Putting everything together

Arduino Mega + Power supply + Soldering hat thing
Silicone Wire
Heat Shrinks, Solder etc. 
Wago Connectors
Barrel Jack Connectors

## Part 6: Code!
[Find Commented Arduino Code Here](/Electronics/Code)


