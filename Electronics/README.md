## Part 1: Overview


<img src="/../main/Pictures/WiringDiagram.jpg" alt="Overview Illustration of Electronics" width="800">

The electronic components in Flooded House have three main functions:
- **_The Interface_** collects the user's selection of the climate scenario. The selectin contains 6 buttons - each one represents a location around the world, potentiometer with which users can select a year, and a potentiometer with which users can select a predicted temperature increase. A "Enter" button allows users to start the visualization.
- **_The Water Height Measurement_** consists of many transistors and constantly measures the water height inside the aquarium tp report it back to the Arduino. [The electronics for this are not very elegant unfortunately...]
- **_The Water System_**, made up of water pumps, transistors, and capacitors pump water into the aquarium or out of it, depending on the user selection, and the water height.


Below you can find an explanation and material list for each main function. Regular Electronics Items like (Silicone) Wire, Heat Shrink Tubes, Solder, (Wago) Connectors are also needed. 


## Part 2: Interface

Pretty straight forward: A bunch of buttons, sliding potentiometers, 7-segment displays and LEDs. 

<img src="/../main/Pictures/Interface.jpg" alt="Overview Illustration of Electronics" width="800">

- 2 x [Sliding Potentiometers](https://www.adafruit.com/product/4219)
- 6 x [Illuminated Pushbutton](https://www.adafruit.com/product/1479)
- 2 x [7-segment display with I2C Backpack](https://www.adafruit.com/product/1002)
- 2 x [Stemma QT-connector wires](https://www.adafruit.com/product/4210)
- 1 x [Arcade Button](https://www.adafruit.com/product/492)
- 2 x Regular 4mm LED's in Blue and Green
- 2 x 220Ω Resistor for LED

## Part 3: Water Height Measurement

_Note: The way I am measuring the water height in this project is not ideal. I am measuring the water height at intervals of 5mm by placing wire-ends into the aquarium at those height intervals: the first wire is placed 5mm above the floor, the second one 10mm, and so on. A separate wire that is charged 5V is also placed in the water at the other corner of the apartment. If the water rises, it connects the 5V-charged wire to the other wire-ends. Using transistors, I can aplify the current and detect whether the water is connecing that "circuit". Hence, I can detect how high the water has already risen._

_The problem of this method is that over time multiple measure points keep breaking. Additionally, the measurement is not very precise, as I can only detect increases of 5mm._


<img src="/../main/Pictures/WaterHeight.jpg" alt="Overview Illustration of Electronics" width="400">

- 1 x [extra thin prototyping wire](https://www.adafruit.com/product/1446)
- 22 x [2n2222a transistor](https://www.amazon.com/dp/B0CRVGFN4R?psc=1&ref=ppx_yo2ov_dt_b_product_details)

The wires marked with the "Water" tag are placed into the apartment. I glued them at the back of the miniature mirror with 5mm distance from each other, to measure the water height in intervals of 5mm. 
<img src="/../main/Pictures/WaterHeightSensor.jpg" alt="Picture of the Water Height Sensor" width="600">

## Part 4: Water System

Read more about how the water pump system works [here](/../main/Fabrication/), Part 2.

_Note: I am using two separate power supplies, one for the Arduino, and one for the DC Water pumps. This is technically not necessary, and could have been avoided by powering both the Arduino and the water pumps with 12V._

<img src="/../main/Pictures/WaterSystem.jpg" alt="Overview Illustration of Electronics" width="600">

- 2 x [mini DC 6V-12V Water Pump](https://www.amazon.com/Gikfun-Aquarium-Cooled-Diaphragm-EK1856/dp/B0744FWNFR/ref=sr_1_8?crid=32KMANFREUB0E&dib=eyJ2IjoiMSJ9.J0Tx3kri4VOzRx4WEBbvFqtay5iG7ajseZqrG_dtkoebM9g6lP8WZgsmsSQusOCyx9zNqZKUEm4AOZAsuNBRDL_KEKx3fl4AlU-RHnunfjPtwnE9DVWMFh6hfjJi7kup9jggLzmP5qCKWlK50Vvs5VnWu9aJx-zCBwapUsVnUN7B3ZbiLiI17WJ2K0DV6cKRJMdsL_GMQBL6KhunZMsen87Lxazvq0yXjnUWTctHZlA6QviKqo2bmg8pZ-La4j5bEXsJDe9xVfi1WRDsWJOqwtabCaCHKBEaXNbetLuWrR4.hik8rEZ-_YLfcWAMrKjhWcLLEJ72LE4GUuT7xzYkr7Y&dib_tag=se&keywords=water+pumps+arduino+12V&qid=1718229218&sprefix=water+pumps+arduino+12v%2Caps%2C207&sr=8-8)
- 2 x [35V 1000uf Capacitor](https://www.amazon.com/dp/B073YR6LVK?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- 2 x [Transistor????](...)
- 2 x [1N4007 Diode 1A 1000V](https://www.amazon.com/MIC-Silastic-Junction-Standard-Rectifier/dp/B07GQCSC7G/ref=sr_1_1?crid=8HQN89PY6UBR&dib=eyJ2IjoiMSJ9.TvZUWlEBgrSXw-JzElFmP2pdXry7HSf3z_nJwoRcKBOx2BVkbIJraiaTKOEq0ubZwZHHh8cKo0Zkedss0eEde7BKI0GKBz_LASY5qu1YE3qyB9uWY6sPVltY_CY-YpMZB-LKYO849kTmw0_WM1MwPbnVV7MFJ3eJ7XKFpT4yTToQYXGTIiOrIEzWwSRUyJNyNbOqmmp8k7NuwT8i9JP6pg-gIMX0KVbs9zr2OGo4DDGCIWaT2XMrTIpdRTszQyJTKTdX0TOb8JDCoIBxM-1bhJVPDR64cndRnAPy5PLed6k.I3HBXig6K8XixgVAtsY0jKmWt4OgEqCwLrA48Nceo9w&dib_tag=se&keywords=flyback+diode&qid=1718229378&s=industrial&sprefix=flybackdiode%2Cindustrial%2C222&sr=1-1)
- 1 x [12V 5A Power Supply](https://www.amazon.com/Converter-100-220V-Transformer-5-5x2-1mm-Accessories/dp/B08C594VNP/ref=sr_1_2_sspa?crid=2CTCE8Z1W2IVL&dib=eyJ2IjoiMSJ9.nuI_jzhR504zJueFvzdvvkJaPnoB_guhkUgOVQo8ooN7p8XUjZjAlYbSoVJ2mUfkAfDfmTzXWAz1wJ_6m1fRqegzfYYCw7FwB_pY2Awd2bxT_QBuuUqi6wnSmsbC2GymYtNaTyFyeJNq5-SREfjZx7z3eMonNZ1tpD22A89BWKeO8GN8EzPBxpNDCG_kF6GHXOmw2wRlRY-DedlazM8wAuUPwZbrdNUEBvEuO7s5opJyTw0zQ2oNeC5-RDldGbG7uMZlEGlWLj8izQVpDnBA1IgATlRl4Q-0s5zHmMNhAdM.7Ev06JooUs4Iz5nIvg7v8_x8UZAUEzU53gp7ZGpIgaE&dib_tag=se&keywords=12+V+5A+power+supply&qid=1718229664&s=electronics&sprefix=12v+5a+power+supply%2Celectronics%2C170&sr=1-2-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1&smid=A1ADCAD2VWTFU6)


## Part 5: Power Supply + Putting everything together

- 1 x [Arduino Mega](https://www.amazon.com/ARDUINO-MEGA-2560-REV3-A000067/dp/B0046AMGW0/ref=sr_1_1_sspa?crid=14BK7OWCC52NO&dib=eyJ2IjoiMSJ9.7su-8tK7IrW7zSexC6pA41TS-skmVROyj9TVtdJfDMxQMuGeaYlw4Bd0B2rlk8zx4ujrdDWmOceYc-P42XvWTgC6TTpFhXSvw4_OkxPvNgOzvRFfSwuMLTPZz-ur_E1271PFLmHB5Pyr-YuKPxFetmMiMJMfi5pa9LTsscGGLDZPuX8QmeBdyGaCFwROpjthb3dgzKdWtgRxvZXBexmgnxh9EfHlquB8yrrouIifXFt_Dckb9nkfp__9X9i6eS6Ua1PEXnrFotg6581IAqKOQ6NmQnNDqhgVGln5xB-A598.JAnNw4aD28YLVxf0eJHjqft2zpFyOD6Fo3jpfpvikmM&dib_tag=se&keywords=arduino+mega&qid=1718229489&s=industrial&sprefix=arduino+meg%2Cindustrial%2C189&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)
- 1 x [Prototyping Shield for Arduino Mega](https://www.amazon.com/KEYESTUDIO-Prototype-Board-Arduino-Double/dp/B07DRG2LN2/ref=sr_1_1_sspa?crid=1ZPIL4K2COI1M&dib=eyJ2IjoiMSJ9.1YYH4-fCL-REZT_IlejIaFstf1X8vrf6XK5-LE-jhVzXHFYEYJfKy07jKgexkvDuidukg8Z7Jnf3RxeD0kjoQYplsoldFbD7Q7X0A3n7_jVvLGg5lZ1G_qzIwGNwWgwbm3Wx-MTnpIRB2tH0No6FYtwPGvHMNm4FaXjXC2G_PqCkbNMeXfgXJDZIsZJ-quT2OYGxPMgM6ZAGFgHXPTsR0m08HrceiYmScml63qXNxW0hcFbUR0QcNMnURzt_9W7gjdZhg8sf-2roSZRVK81ak6mf9g7u5h1KjkEpm8536uA.7T7xokcv2lbbDu1NG7SQDC3qvG4zVDNo9DJsMWx5Dto&dib_tag=se&keywords=arduino+mega+shield&qid=1718229518&s=industrial&sprefix=arduino+mega+shied%2Cindustrial%2C186&sr=1-1-spons&sp_csd=d2lkZ2V0TmFtZT1zcF9hdGY&psc=1)
- 1 x [9V 5A Power Supply](https://www.amazon.com/dp/B08K2WJ31N?psc=1&ref=ppx_yo2ov_dt_b_product_details)
- 1x [Barrel Jack Connectors](https://www.amazon.com/dp/B08SJM2G52?psc=1&ref=ppx_yo2ov_dt_b_product_details)


## Part 6: Code!
[Find Arduino Code Here](/Electronics/Code)

## This is how my electronics looked like all put together!
<img src="/../main/Pictures/ElectronicsPicture.JPG" alt="Picture of finished Electronics" width="800">


