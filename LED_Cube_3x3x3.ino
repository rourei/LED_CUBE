/*
   Operation sketch for a 3x3x3 LED Cube with an Arduino UNO.

   Author:  Rouven Reichert
   Created: 2020/04/30
*/

// Define variables
int pinLayer[3]  = {A2, A1, A0};
int pinColumn[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};

const int cube_size = 3;


// ################ SETUP ################
void setup()
{
  // Define pin mode for layers and columns
  for (int i = 0; i < cube_size; i++)
  {
    pinMode(pinLayer[i], OUTPUT);
  }

  for (int i = 0; i < (cube_size * cube_size); i++)
  {
    pinMode(pinColumn[i], OUTPUT);
  }

  // Initialze cube in off state
  cubeOff();

  // Blink middle column three times
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(pinLayer[0], HIGH);
    digitalWrite(pinLayer[1], HIGH);
    digitalWrite(pinLayer[2], HIGH);
    digitalWrite(pinColumn[4], LOW);
    delay(500);
    cubeOff();
    delay(500);
  }

  cubeOff();
}


// ################ LOOP ################
void loop()
{
  walkCube();
  cubeOff();
  cornerColumns();
  delay(1000);
  cubeOff();
  buildLayer(0);
  delay(1000);
  cubeOff();
  buildLayer(1);
  delay(1000);
  cubeOff();
  buildLayer(2);
  delay(1000);
  cubeOff();

}

// ################ EVERYTHING ON ################
void cubeOn()
{
  // Set anode layers to high
  for (int i = 0; i < cube_size; i++)
  {
    digitalWrite(pinLayer[i], HIGH);
  }

  // Set cathode columns to low
  for (int i = 0; i < (cube_size * cube_size); i++)
  {
    digitalWrite(pinColumn[i], LOW);
  }
}


// ################ EVERYTHING OFF ################
void cubeOff()
{
  // Set anode layers to low
  for (int i = 0; i < cube_size; i++)
  {
    digitalWrite(pinLayer[i], LOW);
  }

  // Set cathode columns to high
  for (int i = 0; i < (cube_size * cube_size); i++)
  {
    digitalWrite(pinColumn[i], HIGH);
  }
}

// ################ WALK CUBE ################
void walkCube()
{
  for (int i = 0; i < cube_size; i++)
  {
    for (int j = 0; j < (cube_size * cube_size); j++)
    {
      digitalWrite(pinLayer[i], HIGH);
      digitalWrite(pinColumn[j], LOW);
      delay(150);
      cubeOff();
      delay(150);
    }
  }
}

// ################ ALL LAYERS ON ################
void allLayersOn()
{
  // Set anode layers to high
  for (int i = 0; i < cube_size; i++)
  {
    digitalWrite(pinLayer[i], HIGH);
  }
}

// ################ CORNER COLUMNS ################
void cornerColumns()
{
  allLayersOn();
  digitalWrite(pinColumn[0], LOW);
  digitalWrite(pinColumn[2], LOW);
  digitalWrite(pinColumn[6], LOW);
  digitalWrite(pinColumn[8], LOW);
}

// ################ BUILD LAYER ################
void buildLayer(int i)
{
  digitalWrite(pinLayer[i], HIGH);

  for (int j = 0; j < (cube_size * cube_size); j++)
  {
    digitalWrite(pinColumn[j], LOW);
    delay(250);
  }
}
