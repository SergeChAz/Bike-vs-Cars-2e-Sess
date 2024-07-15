//
//  main.c
//  Bike vs Cars 2e Sess
//
//  Created by Serge CHARLIER AZAMA on 11/07/2024.
//

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <stdio.h>
#include <GLUT/glut.h>

#include "display.h"

// Fonction principale
int main(int argc, char **argv) {
    initGLUT(&argc, argv);                  // Initialisation de GLUT
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // Fond noir
    glutDisplayFunc(display);               // Ici, nous indiquons à GLUT quelle fonction utiliser pour dessiner la fenêtre de jeu
    glutMainLoop();                         // Lancement de la boucle principale de GLUT
    return 0;
}
#pragma clang diagnostic pop
