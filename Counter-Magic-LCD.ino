#include <LiquidCrystal.h>
#include <avr/sleep.h>
#include <avr/power.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

byte heart[8] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
};

byte energy[8] = {
  B00000,
  B01111,
  B00010,
  B00100,
  B01110,
  B00100,
  B01000,
};

byte magic[8] = {
  B00000,
  B00100,
  B10101,
  B11111,
  B11111,
  B01110,
  B00100,
  B00100,
};

int btnMod = 10;
int btnAdd = 8;
int btnAdd5 = 6;
int btnLss = 7;
int btnLss5 = 9;
int btnPly = 13;

int vida = 20;
int counter = 0;
int vida2 = 20;
int counter2 = 0;
int mod = 0;
int player = 1;

int activePlayer = 1;

void aberturaMagicCounter()
{
  for (int i = 0; i < 4; i++)
  {
    lcd.clear();
    lcd.write(byte(2));
    lcd.print("Magic Counter");
    lcd.write(byte(2));
    lcd.scrollDisplayRight();
    delay(500);
    lcd.scrollDisplayLeft();
    delay(500);
  }
}

void quantityPlayers()
{
  boolean ba, bl;

  lcd.clear();
  lcd.print("1P - Aperte +");
  lcd.setCursor(0, 1);
  lcd.print("2P - Aperte -");
  while ((digitalRead(btnAdd) == HIGH) or (digitalRead(btnLss) == HIGH))
  {
    ba = digitalRead(btnAdd);
    bl = digitalRead(btnLss);

    if (ba == LOW)
    {
      player = 1;
      lcd.clear();
      lcd.print("1 Jogador");
      delay(1000);
      break;
    }
    if (bl == LOW)
    {
      player = 2;
      lcd.clear();
      lcd.print("2 Jogadores");
      delay(1000);
      break;
    }
  }
}

void rollDice()
{
  int p1, p2, dot;
  dot = 0;

  while (digitalRead(btnMod) == HIGH)
  {
    lcd.clear();
    lcd.print("Dado do J1");
    p1 = random(1, 20);
    lcd.setCursor(0, 1);
    if (dot < 5)
    {
      lcd.print(".");
    }
    else if ((dot >= 5) and (dot < 10))
    {
      lcd.print("..");
    }
    else if ((dot >= 10) and (dot <= 15))
    {
      lcd.print("...");
    }
    else
    {
      dot = 0;
    }
    dot = dot + 1;
    delay(100);
  }
  lcd.setCursor(0, 1);
  lcd.print("   ");
  lcd.setCursor(0, 1);
  lcd.print(p1);
  dot = 0;
  delay(3000);
  if (player == 2)
  {
    while (digitalRead(btnMod) == HIGH)
    {
      lcd.clear();
      lcd.print("Dado do J2");
      p2 = random(1, 20);
      lcd.setCursor(0, 1);
      if (dot < 5)
      {
        lcd.print(".");
      }
      else if ((dot >= 5) and (dot < 10))
      {
        lcd.print("..");
      }
      else if ((dot >= 10) and (dot <= 15))
      {
        lcd.print("...");
      }
      else
      {
        dot = 0;
      }
      dot = dot + 1;
      delay(100);
    }
    lcd.setCursor(0, 1);
    lcd.print("   ");
    lcd.setCursor(0, 1);
    lcd.print(p2);
    dot = 0;
    delay(3000);

    if (p1 > p2)
    {
      lcd.clear();
      lcd.print("Jogador 1");
      lcd.setCursor(0, 1);
      lcd.print("inicia!");
      delay(3000);
    }
    else if (p1 < p2)
    {
      lcd.clear();
      lcd.print("Jogador 2");
      lcd.setCursor(0, 1);
      lcd.print("inicia!");
      delay(3000);
      changePlayer();
    }
    else if (p1 == p2)
    {
      lcd.clear();
      lcd.print("Empate!");
      lcd.setCursor(0, 1);
      lcd.print("Role novamente.");
      delay(3000);
      rollDice();
    }
  }
}

void changePlayer()
{
  if (player == 2)
  {
    if (activePlayer == 1)
    {
      activePlayer = 2;
    }
    else
    {
      activePlayer = 1;
    }
  }
}

void showLife()
{
  if (player == 1)
  {
    if (mod == 0)
    {
      lcd.clear();
      lcd.write(byte(1));
      lcd.print(vida);
      lcd.setCursor(0, 1);
      lcd.write(byte(0));
      lcd.print(counter);
    }
    else
    {
      lcd.clear();
      lcd.write(byte(0));
      lcd.print(counter);
      lcd.setCursor(0, 1);
      lcd.write(byte(1));
      lcd.print(vida);
    }
  }
  else
  {
    if (mod == 0)
    {
      if (activePlayer == 1)
      {
        lcd.clear();
        lcd.print("P1 ");
        lcd.write(byte(1));
        lcd.print(vida);
        lcd.print(" ");
        lcd.write(byte(0));
        lcd.print(counter);

        lcd.setCursor(0, 1);
        lcd.print("P2 ");
        lcd.write(byte(1));
        lcd.print(vida2);
        lcd.print(" ");
        lcd.write(byte(0));
        lcd.print(counter2);
      }
      else
      {
        lcd.clear();
        lcd.print("P2 ");
        lcd.write(byte(1));
        lcd.print(vida2);
        lcd.print(" ");
        lcd.write(byte(0));
        lcd.print(counter2);

        lcd.setCursor(0, 1);
        lcd.print("P1 ");
        lcd.write(byte(1));
        lcd.print(vida);
        lcd.print(" ");
        lcd.write(byte(0));
        lcd.print(counter);
      }
    }
    else
    {
      if (activePlayer == 1)
      {
        lcd.clear();
        lcd.print("P1 ");
        lcd.write(byte(0));
        lcd.print(counter);
        lcd.print(" ");
        lcd.write(byte(1));
        lcd.print(vida);

        lcd.setCursor(0, 1);
        lcd.print("P2 ");
        lcd.write(byte(0));
        lcd.print(counter2);
        lcd.print(" ");
        lcd.write(byte(1));
        lcd.print(vida2);
      }
      else
      {
        lcd.clear();
        lcd.print("P2 ");
        lcd.write(byte(0));
        lcd.print(counter2);
        lcd.print(" ");
        lcd.write(byte(1));
        lcd.print(vida2);

        lcd.setCursor(0, 1);
        lcd.print("P1 ");
        lcd.write(byte(0));
        lcd.print(counter);
        lcd.print(" ");
        lcd.write(byte(1));
        lcd.print(vida);
      }
    }
  }
}

void addLife(int ply)
{
  if (mod == 0)
  {
    if (ply == 1)
    {
      vida = vida + 1;
    }
    else
    {
      vida2 = vida2 + 1;
    }
  }
  if (mod == 1)
  {
    if (ply == 1)
    {
      counter = counter + 1;
    }
    else
    {
      counter2 = counter2 + 1;
    }
  }
}

void addLife5()
{
  if (mod == 0)
  {
    vida = vida + 5;
  }

  if (mod == 1)
  {
    counter = counter + 5;
  }
}

void lessLife(int ply)
{
  if (mod == 0)
  {
    if (ply == 1)
    {
      vida = vida - 1;
    }
    else
    {
      vida2 = vida2 - 1;
    }
  }
  if (mod == 1)
  {
    if (ply == 1)
    {
      counter = counter - 1;
    }
    else
    {
      counter2 = counter2 - 1;
    }
  }
}

void lessLife5()
{
  if (mod == 0)
  {
    vida = vida - 5;
  }

  if (mod == 1)
  {
    counter = counter - 5;
  }
}

void changeMode()
{
  if (mod == 0)
  {
    mod = 1;
  }
  else
  {
    mod = 0;
  }
}

void setup() {
  lcd.createChar(0, energy);
  lcd.createChar(1, heart);
  lcd.createChar(2, magic);
  lcd.begin(16, 2);
  pinMode(btnAdd, INPUT);
  digitalWrite(btnAdd, HIGH);
  pinMode(btnLss, INPUT);
  digitalWrite(btnLss, HIGH);
  pinMode(btnAdd5, INPUT);
  digitalWrite(btnAdd5, HIGH);
  pinMode(btnLss5, INPUT);
  digitalWrite(btnLss5, HIGH);
  pinMode(btnMod, INPUT);
  digitalWrite(btnMod, HIGH);
  pinMode(btnPly, INPUT);
  digitalWrite(btnPly, HIGH);
  //  pinMode (A0, OUTPUT);    // changed as per below
  //  digitalWrite (A0, LOW);  //     ditto
  //  pinMode (A1, OUTPUT);    // changed as per below
  //  digitalWrite (A1, LOW);  //     ditto
  //  pinMode (A2, OUTPUT);    // changed as per below
  //  digitalWrite (A2, LOW);  //     ditto
  //  pinMode (A3, OUTPUT);    // changed as per below
  //  digitalWrite (A3, LOW);  //     ditto
  //  pinMode (A4, OUTPUT);    // changed as per below
  //  digitalWrite (A4, LOW);  //     ditto
  //  pinMode (A5, OUTPUT);    // changed as per below
  //  digitalWrite (A5, LOW);  //     ditto
  //  ADCSRA = 0;
  //  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  //  power_adc_disable(); // ADC converter
  //  power_spi_disable(); // SPI
  //  power_usart0_disable();// Serial (USART)
  //  noInterrupts ();           // timed sequence follows
  //  sleep_enable();
  //  // turn off brown-out enable in software
  //  MCUCR = bit (BODS) | bit (BODSE);
  //  MCUCR = bit (BODS);
  //  interrupts ();             // guarantees next instruction executed
  
  aberturaMagicCounter();
  quantityPlayers();
  rollDice();
  showLife();
}

void loop() {
  boolean ba = digitalRead(btnAdd);
  boolean bl = digitalRead(btnLss);
  boolean ba5 = digitalRead(btnAdd5);
  boolean bl5 = digitalRead(btnLss5);
  boolean bm = digitalRead(btnMod);
  boolean bp = digitalRead(btnPly);
  if ((ba == LOW) or (bl == LOW) or (bm == LOW) or (bp == LOW) or (ba5 == LOW) or (bl5 == LOW))
  {
    if (ba == LOW)
    {
      addLife(1);
      showLife();
      delay(400);
    }
    else if (ba5 == LOW)
    {
      if (player == 2)
      {
        addLife(2);
      }
      else
      {
        addLife5();
      }
      showLife();
      delay(400);
    }
    else if (bl == LOW)
    {
      lessLife(1);
      showLife();
      delay(400);
    }
    else if (bl5 == LOW)
    {
      if (player == 2)
      {
        lessLife(2);
      }
      else
      {
        lessLife5();
      }
      showLife();
      delay(400);
    }
    else if ((bp == LOW) and (player == 2))
    {
      changePlayer();
      showLife();
      delay(400);
    }
    else
    {
      changeMode();
      showLife();
      delay(400);
    }

  }
}

