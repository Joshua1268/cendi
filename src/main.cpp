#include <Arduino.h>

const int relayPin1 = 6; // Broche du relais 1
const int relayPin2 = 7; // Broche du relais 2

const int button1Pin = 8; // Broche du bouton 1
const int button2Pin = 9; // Broche du bouton 2

bool relay1State = LOW; // État du relais 1
bool relay2State = LOW; // État du relais 2

bool lastButton1State = HIGH; // Dernier état du bouton 1
bool lastButton2State = HIGH; // Dernier état du bouton 2

void setup() {
  // Initialiser les broches des relais comme sorties
  pinMode(relayPin1, OUTPUT);
  pinMode(relayPin2, OUTPUT);

  // Démarrer les relais éteints
  digitalWrite(relayPin1, LOW);
  digitalWrite(relayPin2, LOW);

  // Initialiser les broches des boutons comme entrées avec pull-up interne activé
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);

  Serial.begin(9600); // Initialiser la communication série pour le débogage
}

void loop() {
  // Lire l'état des boutons
  bool button1State = digitalRead(button1Pin);
  bool button2State = digitalRead(button2Pin);

  // Vérifier si le bouton 1 a été appuyé
  if (button1State == LOW && lastButton1State == HIGH) {
    relay1State = !relay1State; // Inverser l'état du relais 1
    digitalWrite(relayPin1, relay1State);
    delay(50); // Petite pause pour éviter le rebondissement
  }
  lastButton1State = button1State; // Mettre à jour l'état précédent du bouton 1

  // Vérifier si le bouton 2 a été appuyé
  if (button2State == LOW && lastButton2State == HIGH) {
    relay2State = !relay2State; // Inverser l'état du relais 2
    digitalWrite(relayPin2, relay2State);
    delay(50); // Petite pause pour éviter le rebondissement
  }
  lastButton2State = button2State; // Mettre à jour l'état précédent du bouton 2

  // Afficher les états pour le débogage
  Serial.print("Button 1 State: ");
  Serial.print(button1State);
  Serial.print(" | Relay 1 State: ");
  Serial.println(relay1State);
  
  Serial.print("Button 2 State: ");
  Serial.print(button2State);
  Serial.print(" | Relay 2 State: ");
  Serial.println(relay2State);
}
