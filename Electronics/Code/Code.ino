#include "CityData.h"
#include "Adafruit_LEDBackpack.h"

//CITY SELECTION
const int buttonPinNewYork = 50;
const int lightPinNewYork = 51;
const int buttonPinManila = 48;
const int lightPinManila = 49;
const int buttonPinKamaishi = 46;
const int lightPinKamaishi = 47;
const int buttonPinTakoradi = 44;
const int lightPinTakoradi = 45;
const int buttonPinCananeia = 42;
const int lightPinCananeia = 43;
const int buttonPinBugrino = 40;
const int lightPinBugrino = 41;

int bStateNewYork = 0;
int bStateManila = 0;
int bStateKamaishi = 0;
int bStateTakoradi = 0;
int bStateCananeia = 0;
int bStateBugrino = 0;

// DISPLAYS
Adafruit_7segment matrixYear = Adafruit_7segment();
Adafruit_7segment matrixScenario = Adafruit_7segment();

//SELECTION OF YEAR AND SCENARIO
const int potPinYear = A14;
const int potPinScenario = A15;
int potVYear = 0;
int yearDisplayValue;
int potVScenario = 0;
float scenarioDisplayValue;

// FINAL USER SELECTIONS
int selectedCity = 0;
int Scenario = 4;
int FutureYear = 2030;

//"ENTER" BUTTON
const int switchButtonPin = 4;
const int lightswitchButton = 5;
int switchButtonState = 0;
int switchButtonStateOld = 0;

// USER STAGES
bool measureOnce = true;
bool userStage = true;
bool filling = true;

//LED FEEDBACK
const int doneLED = 2;
const int waterLED = 3;

//WATERLEVEL
float waterLevelRise; // this is a variable for the NASA data
int waterLevelRiseScaled;

//HEIGHT MEASUREMENT
int waterLevel;

const int waterlevelMaxPin = 9;
int waterlevelMax;

const unsigned long maxDurationToFill = 171000; // it takes max 171 seconds to fill up the entire aquarium

const int heightPin05 = 12;
int height05;
const int heightPin10 = 11;
int height10;
const int heightPin15 = 10;
int height15;
const int heightPin20 = 13;
int height20;
const int heightPin25 = 22;
int height25;
const int heightPin30 = 38;
int height30;
const int heightPin35 = 37;
int height35;
const int heightPin40 = 36;
int height40;
const int heightPin45 = 35;
int height45;
const int heightPin50 = 34;
int height50;
const int heightPin55 = 33;
int height55;
const int heightPin60 = 32;
int height60;
const int heightPin65 = 31;
int height65;
const int heightPin70 = 30;
int height70;
const int heightPin75 = 29;
int height75;
const int heightPin80 = 28;
int height80;
const int heightPin85 = 27;
int height85;
const int heightPin90 = 26;
int height90;
const int heightPin95 = 25;
int height95;
const int heightPin100 = 7;
int height100;
const int heightPin105 = 8;
int height105;
const int heightPin110 = 6;
int height110;

//MOTORS
const int inMotorPin = 53;
const int outMotorPin = 52;

void setup() {

  Serial.begin(9600);

  pinMode(buttonPinNewYork, INPUT_PULLUP);
  pinMode(buttonPinManila, INPUT_PULLUP);
  pinMode(buttonPinKamaishi, INPUT_PULLUP);
  pinMode(buttonPinTakoradi, INPUT_PULLUP);
  pinMode(buttonPinCananeia, INPUT_PULLUP);
  pinMode(buttonPinBugrino, INPUT_PULLUP);

  pinMode(lightPinNewYork, OUTPUT);
  pinMode(lightPinManila, OUTPUT);
  pinMode(lightPinKamaishi, OUTPUT);
  pinMode(lightPinTakoradi, OUTPUT);
  pinMode(lightPinCananeia, OUTPUT);
  pinMode(lightPinBugrino, OUTPUT);

  digitalWrite(lightPinNewYork, LOW);
  digitalWrite(lightPinManila, LOW);
  digitalWrite(lightPinKamaishi, LOW);
  digitalWrite(lightPinTakoradi, LOW);
  digitalWrite(lightPinCananeia, LOW);
  digitalWrite(lightPinBugrino, LOW);

  pinMode(switchButtonPin, INPUT_PULLUP);
  pinMode(lightswitchButton, OUTPUT);
  digitalWrite(lightswitchButton, LOW);

  pinMode(waterLED, OUTPUT);
  pinMode(doneLED, OUTPUT);
  digitalWrite(waterLED, LOW);
  digitalWrite(doneLED, LOW);

  pinMode(waterlevelMaxPin, INPUT_PULLUP);
  pinMode(heightPin05, INPUT_PULLUP);
  pinMode(heightPin10, INPUT_PULLUP);
  pinMode(heightPin15, INPUT_PULLUP);
  pinMode(heightPin20, INPUT_PULLUP);
  pinMode(heightPin25, INPUT_PULLUP);
  pinMode(heightPin30, INPUT_PULLUP);
  pinMode(heightPin35, INPUT_PULLUP);
  pinMode(heightPin40, INPUT_PULLUP);
  pinMode(heightPin45, INPUT_PULLUP);
  pinMode(heightPin50, INPUT_PULLUP);
  pinMode(heightPin55, INPUT_PULLUP);
  pinMode(heightPin60, INPUT_PULLUP);
  pinMode(heightPin65, INPUT_PULLUP);
  pinMode(heightPin70, INPUT_PULLUP);
  pinMode(heightPin75, INPUT_PULLUP);
  pinMode(heightPin80, INPUT_PULLUP);
  pinMode(heightPin85, INPUT_PULLUP);
  pinMode(heightPin90, INPUT_PULLUP);
  pinMode(heightPin95, INPUT_PULLUP);
  pinMode(heightPin100, INPUT_PULLUP);
  pinMode(heightPin105, INPUT_PULLUP);
  pinMode(heightPin110, INPUT_PULLUP);

  matrixYear.begin(0x70);
  matrixScenario.begin(0x71);

  pinMode(inMotorPin, OUTPUT);
  pinMode(outMotorPin, OUTPUT);
  digitalWrite(inMotorPin, LOW);
  digitalWrite(outMotorPin, LOW);
}

void loop() {
  switchButtonState = digitalRead(switchButtonPin);

  if (switchButtonState == LOW and switchButtonStateOld == HIGH) {
    userStage = false;
  }

  waterlevelMax = digitalRead(waterlevelMaxPin);
  if (waterlevelMax == LOW) {
    Serial.println("MAX WATER LEVEL");
    emergency();
  }

  switch (userStage) {
    case true:
      digitalWrite(lightswitchButton, LOW);
      getUserData();
      measureOnce = true;
      delay(100);
      break;
    case false:
      digitalWrite(lightswitchButton, HIGH);
      if (measureOnce) {
        getData();
        measureOnce = false;
      }
      fillAquarium();
      delay(100);
      reset();
      userStage = true;
      break;
  }
  switchButtonStateOld = switchButtonState;
}

void getUserData() {
  // Check the state of each button
  bStateNewYork = digitalRead(buttonPinNewYork);
  bStateManila = digitalRead(buttonPinManila);
  bStateKamaishi = digitalRead(buttonPinKamaishi);
  bStateTakoradi = digitalRead(buttonPinTakoradi);
  bStateCananeia = digitalRead(buttonPinCananeia);
  bStateBugrino = digitalRead(buttonPinBugrino);

  if (bStateNewYork == LOW) {
    selectedCity = 0;
  } else if (bStateManila == LOW) {
    selectedCity = 1;
  } else if (bStateKamaishi == LOW) {
    selectedCity = 2;
  } else if (bStateTakoradi == LOW) {
    selectedCity = 3;
  } else if (bStateCananeia == LOW) {
    selectedCity = 4;
  } else if (bStateBugrino == LOW) {
    selectedCity = 5;
  }


  if (selectedCity == 0) {
    digitalWrite(lightPinNewYork, HIGH);
    digitalWrite(lightPinManila, LOW);
    digitalWrite(lightPinKamaishi, LOW);
    digitalWrite(lightPinTakoradi, LOW);
    digitalWrite(lightPinCananeia, LOW);
    digitalWrite(lightPinBugrino, LOW);
  }
  else if (selectedCity == 1) {
    digitalWrite(lightPinNewYork, LOW);
    digitalWrite(lightPinManila, HIGH);
    digitalWrite(lightPinKamaishi, LOW);
    digitalWrite(lightPinTakoradi, LOW);
    digitalWrite(lightPinCananeia, LOW);
    digitalWrite(lightPinBugrino, LOW);
  }
  else if (selectedCity == 2) {
    digitalWrite(lightPinNewYork, LOW);
    digitalWrite(lightPinManila, LOW);
    digitalWrite(lightPinKamaishi, HIGH);
    digitalWrite(lightPinTakoradi, LOW);
    digitalWrite(lightPinCananeia, LOW);
    digitalWrite(lightPinBugrino, LOW);
  }
  else if (selectedCity == 3) {
    digitalWrite(lightPinNewYork, LOW);
    digitalWrite(lightPinManila, LOW);
    digitalWrite(lightPinKamaishi, LOW);
    digitalWrite(lightPinTakoradi, HIGH);
    digitalWrite(lightPinCananeia, LOW);
    digitalWrite(lightPinBugrino, LOW);
  }
  else if (selectedCity == 4) {
    digitalWrite(lightPinNewYork, LOW);
    digitalWrite(lightPinManila, LOW);
    digitalWrite(lightPinKamaishi, LOW);
    digitalWrite(lightPinTakoradi, LOW);
    digitalWrite(lightPinCananeia, HIGH);
    digitalWrite(lightPinBugrino, LOW);
  }
  else if (selectedCity == 5) {
    digitalWrite(lightPinNewYork, LOW);
    digitalWrite(lightPinManila, LOW);
    digitalWrite(lightPinKamaishi, LOW);
    digitalWrite(lightPinTakoradi, LOW);
    digitalWrite(lightPinCananeia, LOW);
    digitalWrite(lightPinBugrino, HIGH);
  }

  // Read the potentiometer values
  potVYear = analogRead(potPinYear);
  potVScenario = analogRead(potPinScenario);

  yearDisplayValue = map(potVYear, 0, 1023, 2030, 2159);
  yearDisplayValue = yearDisplayValue - (yearDisplayValue % 10); // Round down to the nearest 10
  if (potVScenario < 50) {
    scenarioDisplayValue = 1.5;
  } else {
    scenarioDisplayValue = map(potVScenario, 50, 900, 2, 5);
  }

  matrixYear.print(yearDisplayValue);
  matrixScenario.print(scenarioDisplayValue, 1);
  matrixYear.writeDisplay();
  matrixScenario.writeDisplay();

  Serial.print("City: ");
  if (selectedCity == 0) {
    Serial.print("NewYork");
  }
  else if (selectedCity == 1) {
    Serial.print("Manila");
  }
  else if (selectedCity == 2) {
    Serial.print("Kamaishi");
  }
  else if (selectedCity == 3) {
    Serial.print("Takoradi");
  }
  else if (selectedCity == 4) {
    Serial.print("Cananeia");
  }
  else if (selectedCity == 5) {
    Serial.print("Bugrino");
  }
  Serial.print("   Year: ");
  Serial.print(yearDisplayValue);
  Serial.print("   Scenario: ");
  Serial.println(scenarioDisplayValue);
}

void getData() {
  int mappedYear = mapYears(yearDisplayValue);
  int mappedScenario = mapScenario(scenarioDisplayValue);

  waterLevelRise = Cities[selectedCity][mappedYear][mappedScenario];
  waterLevelRiseScaled = waterLevelRise * 50; //( *1000 (from m to mm) /20 (for scale))

  Serial.print("Water Level Rise (m): ");
  Serial.print(waterLevelRise);
  Serial.print("    SCALED (mm): ");
  Serial.println(waterLevelRiseScaled);

  delay(1000);
}

void fillAquarium() {

  unsigned long startTime = millis();

  while (filling) {

    waterlevelMax = digitalRead(waterlevelMaxPin);
    if (waterlevelMax == LOW) {
      Serial.print("MAX WATER LEVEL");
      filling = false;
      emergency();
    }

    waterheight();

    Serial.print("waterlevel: ");
    Serial.print(waterLevel);
    Serial.print("   Scaled: ");
    Serial.println(int(waterLevelRiseScaled));

    if (waterLevel <= waterLevelRiseScaled and millis() - startTime < maxDurationToFill) {

      Serial.print("Filling    ");
      digitalWrite(inMotorPin, HIGH);

      //BLUE LED BLINKS
      digitalWrite(waterLED, HIGH);
      delay(300);
      digitalWrite(waterLED, LOW);
      delay(300);

    } else {
      digitalWrite(inMotorPin, LOW);
      Serial.print("Water Level Reached     ");

      digitalWrite(waterLED, LOW);
      digitalWrite(doneLED, HIGH);

      delay(30000); //waiting for user to see (wait 30 seconds);
      digitalWrite(doneLED, LOW);

      filling = false;
    }
  }
}

void reset() {

  Serial.println("We are resetting");

  while (!filling) {

    //BLUE LED BLINKS
    digitalWrite(waterLED, HIGH);
    delay(300);
    digitalWrite(waterLED, LOW);
    delay(300);

    waterheight();

    Serial.println(waterLevel);

    if (waterLevel > 5) {
      Serial.println("Unfilling   ");
      digitalWrite(outMotorPin, HIGH);
      delay(100);
    } else if (waterLevel <= 5) {
      filling = true;
      digitalWrite(outMotorPin, HIGH);
    }
  }

  Serial.println("DONE");
  delay(12000); // to make sure all water is out
  digitalWrite(outMotorPin, LOW);
  //resetting flags

  digitalWrite(lightPinNewYork, LOW);
  digitalWrite(lightPinManila, LOW);
  digitalWrite(lightPinKamaishi, LOW);
  digitalWrite(lightPinTakoradi, LOW);
  digitalWrite(lightPinCananeia, LOW);
  digitalWrite(lightPinBugrino, LOW);

  //resetting leds
  digitalWrite(doneLED, LOW);
}

void waterheight() {
  //  //TRANSISTOR CODE HERE (make function?)
  height05 = digitalRead(heightPin05);
  height10 = digitalRead(heightPin10);
  height15 = digitalRead(heightPin15);
  height20 = digitalRead(heightPin20);
  height25 = digitalRead(heightPin25);
  height30 = digitalRead(heightPin30);
  height35 = digitalRead(heightPin35);
  height40 = digitalRead(heightPin40);
  height45 = digitalRead(heightPin45);
  height50 = digitalRead(heightPin50);
  height55 = digitalRead(heightPin55);
  height60 = digitalRead(heightPin60);
  height65 = digitalRead(heightPin65);
  height70 = digitalRead(heightPin70);
  height75 = digitalRead(heightPin75);
  height80 = digitalRead(heightPin80);
  height85 = digitalRead(heightPin85);
  height90 = digitalRead(heightPin90);
  height95 = digitalRead(heightPin95);
  height100 = digitalRead(heightPin100);
  height105 = digitalRead(heightPin105);
  height110 = digitalRead(heightPin110);

  if (waterlevelMax == LOW) {
    waterLevel = 200;
  } else if (height110 == LOW) {
    waterLevel = 110;
  } else if (height105 == LOW) {
    waterLevel = 105;
  } else if (height100 == LOW) {
    waterLevel = 100;
  } else if (height95 == LOW) {
    waterLevel = 95;
  } else if (height90 == LOW) {
    waterLevel = 90;
  } else if (height85 == LOW) {
    waterLevel = 85;
  } else if (height80 == LOW) {
    waterLevel = 80;
  } else if (height75 == LOW) {
    waterLevel = 75;
  } else if (height70 == LOW) {
    waterLevel = 70;
  } else if (height65 == LOW) {
    waterLevel = 65;
  } else if (height60 == LOW) {
    waterLevel = 60;
  } else if (height55 == LOW) {
    waterLevel = 55;
  } else if (height50 == LOW) {
    waterLevel = 50;
  } else if (height45 == LOW) {
    waterLevel = 45;
  } else if (height40 == LOW) {
    waterLevel = 40;
  } else if (height35 == LOW) {
    waterLevel = 35;
  } else if (height30 == LOW) {
    waterLevel = 30;
  } else if (height25 == LOW) {
    waterLevel = 25;
  } else if (height20 == LOW) {
    waterLevel = 20;
  } else if (height15 == LOW) {
    waterLevel = 15;
  } else if (height10 == LOW) {
    waterLevel = 10;
  } else if (height05 == LOW) {
    waterLevel = 5;
  } else {
    waterLevel = 0;
  }
}

void emergency() {
  Serial.println("WE ARE IN AN EMERGENCY");
  digitalWrite(inMotorPin, LOW);
  delay(5000);
  reset();
  userStage = true;
}

int mapYears(int inputYear) {
  int mappedValue = (inputYear - 2030) / 10;
  mappedValue = constrain(mappedValue, 0, 12);
  return mappedValue;
}

int mapScenario(float inputScenario) {
  if (inputScenario == 1.5) {
    int mappedValue = 0;
    return mappedValue;
  } else {
    int mappedValue = (int)((inputScenario - 1));
    mappedValue = constrain(mappedValue, 0, 4);
    return mappedValue;
  }
}
