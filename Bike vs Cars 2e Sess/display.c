//
//  display.c
//  Bike vs Cars 2e Sess
//
//  Created by Serge CHARLIER AZAMA on 08/04/2024.
//

// Utilisation de la directive #pragma pour supprimer les messages "is deprecated" que XCode affiche systématiquement lorsque l'on utilise GLUT

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <GLUT/glut.h>      // Inclusion de la bibliothèque GLUT pour créer des interfaces graphiques

#include <stdlib.h>         // Inclusion de la bibliothèque standard

#include "display.h"        // Inclusion du fichier d'entête

// Fonction pour initialiser GLUT et créer la fenêtre de jeu
void initGLUT(int *argc, char **argv) {
    glutInit(argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(800, 600);       // Définition taille fenêtre de jeu 800x600
    glutCreateWindow("Bike vs Cars");   // Création de la fenêtre de jeu intitulée "Bike vs Cars"
}

// Fonction pour dessiner la route

//Dans la ligne suivante, j'ajoute un void entre les parenthèses pour éviter l'avertissement "This old-style function definition is not preceded by a prototype"

void drawRoad(void) {
    // Dessiner la route
    glColor3f(0.5f, 0.5f, 0.5f);    // Couleur grise pour la route
    glBegin(GL_QUADS);              // Début du dessin du quadrilatère que sera la route
    glVertex2f(-0.8f, -1.0f);       // Définition des 4 coins du quadrilatère
    glVertex2f(0.8f, -1.0f);
    glVertex2f(0.8f, 1.0f);
    glVertex2f(-0.8f, 1.0f);
    glEnd();                        // Fin du dessin

    // Dessiner la ligne discontinue au milieu
    glColor3f(1.0f, 1.0f, 1.0f);    // Couleur blanche pour la ligne
    glLineWidth(2.0f);              // Epaisseur de la ligne
    glBegin(GL_LINES);              // Début dessin ligne
    
    //Boucle for pour dessiner la série de segments qui permettront de créer notre ligne discontinue
    for (float i = -1.0f; i < 1.0f; i += 0.2f) {
        glVertex2f(0.0f, i);
        glVertex2f(0.0f, i + 0.1f);
    }
    glEnd();
}

// Fonction pour dessiner la végétation
void drawVegetation(void) {
    // Végétation bordure de gauche
    glColor3f(0.0f, 0.6f, 0.0f); // Couleur verte pour la végétation
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f(-0.8f, -1.0f);
    glVertex2f(-0.8f, 1.0f);
    glVertex2f(-1.0f, 1.0f);
    glEnd();

    // Végétation bordure de droite
    glBegin(GL_QUADS);
    glVertex2f(0.8f, -1.0f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(1.0f, 1.0f);
    glVertex2f(0.8f, 1.0f);
    glEnd();
}

// Fonction de rappel pour afficher le contenu de la fenêtre
void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);   // Effaçage du contenu de la fenêtre
    
    // Appel des fonctions pour dessiner la route et la végétation
    drawRoad();
    drawVegetation();
    
    glutSwapBuffers();              // Echange des tampons si affichage en double tampon => affichage à l'écran du contenu dessiné
}

#pragma clang diagnostic pop        // Réactivation des avertissements
