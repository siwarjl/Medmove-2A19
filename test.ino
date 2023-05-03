// Inclusion des bibliothèques nécessaires 

#include <Servo.h>  //Cette bibliothèque est utilisée pour contrôler les servomoteurs, qui sont capables de tourner sur un angle précis
// Définition des constantes symboliques

#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04 (capteur ultrason)
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04

//Déclaration des variables globales

long duration; // variable pour la durée de propagation de l'onde sonore  (long:entierlong)
int distance; // variable pour la mesure de distance
Servo monServomoteur;   //servo une classe de la bib servo.h
char inputChar;

// Fonction de configuration du programme

void setup() {
  // Configuration des broches de commande du capteur ultrason
  pinMode(trigPin, OUTPUT); // // La broche trigPin est configurée en sortie
  pinMode(echoPin, INPUT); //  La broche echoPin est configurée en entréeINPUT
  
// Configuration des broches de la barrière
  pinMode(12,OUTPUT);  //  La broche 12 est configurée en sortie pour la barrière ouverte (vert)
  pinMode(7,OUTPUT);  // La broche 7 est configurée en sortie pour la barrière fermée (rouge)
  
 // Initialisation de la barrière fermée (rouge)
    analogWrite(7, 0); //La sortie analogique de la broche 7 est mise à 0
    digitalWrite(7, LOW); // La sortie numérique de la broche 7 est mise à LOW
    
// Initialisation du servo-moteur
 monServomoteur.attach(11); // La broche 11 est assignée pour contrôler le servo-moteur
 monServomoteur.write(-90);//Le servo-moteur est initialisé à -90 degrés(barriere fermée)
  
// Initialisation de la communication série
Serial.begin(9600); // La communication série est initialisée à 9600 bauds

// Impression de messages sur le moniteur série
  Serial.println("Ultrasonic Sensor HC-SR04 Test"); // Le message est imprimé sur le moniteur série
  Serial.println("with Arduino UNO R3");// Le message est imprimé sur le moniteur série
 
}
void loop() {
  
  // Envoi d'une impulsion sur le capteur ultrason pour mesurer la distance
  digitalWrite(trigPin, LOW); // On met la broche trigPin à LOW
  delayMicroseconds(2); // On attend 2 microsecondes
  // On met la broche trigPin à HIGH pendant 10 microsecondes
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW); // On met la broche trigPin à LOW
  
  // Lecture de la durée de l'impulsion reçue sur la broche echoPin
  duration = pulseIn(echoPin, HIGH); // On mesure la durée de l'impulsion reçue sur la broche echoPin
  // Calcul de la distance en cm à partir de la durée de l'impulsion
  distance = duration * 0.034 / 2; // La vitesse du son est d'environ 0,034 cm/us, on divise donc par 2 car le son fait l'aller-retour
  // Displays the distance on the Serial Monitor
  //Serial.print("Distance: ");
  //Serial.print(distance);
  //delay(500);
  //Serial.println(" cm");
  
  
   // Gestion de la barrière en fonction de la distance mesurée
  if((distance<11))
  {//Serial.println("Voiture détectée !");
    monServomoteur.write(90);// On tourne le servo-moteur pour ouvrir la barrière
  digitalWrite(12,HIGH);// On allume la LED verte pour indiquer que la barrière est ouverte
  digitalWrite(7,LOW);
  }
  else if((distance>12))
 { 
  //Serial.println("Aucune voiture détectée.");
  monServomoteur.write(-90);// On tourne le servo-moteur pour fermer la barrière
 digitalWrite(7,HIGH);   // On allume la LED rouge pour indiquer que la barrière est fermée
 digitalWrite(12,LOW);

 }
   // Gestion de la barrière par communication série
  if (Serial.available()){ // Si des données sont disponibles sur le port série
    inputChar=Serial.read(); // On lit le caractère reçu
 
  if(inputChar == '2')  // Si le caractère reçu est '2'
{
  digitalWrite(7,LOW); // On éteint la LED rouge
  monServomoteur.write(90);
  delay(1000); // Attendre 1 seconde pour ouvrir la barrière
  digitalWrite(12,HIGH);// On allume la LED verte pour indiquer que la barrière est ouverte
  delay(500); // Attendre 0,5 seconde avant d'arrêter le servo
 // monServomoteur.write(-90); // Arrêter le servo
}
else if(inputChar == '1') // Si le caractère reçu est '1'
{
  digitalWrite(12,LOW);
  delay(500); // Attendre 0,5 seconde avant de commencer à fermer la barrière
  monServomoteur.write(-90); // On tourne le servo-moteur pour fermer la barrière
  delay(1000); // Attendre 1 seconde pour fermer la barrière
  digitalWrite(7,HIGH);
}

  
 
 }
 }
