// Fichier : main.cpp
// Description :
// Programme principal de l'application de jeux d'échecs
//
// Ce fichier est le point d'entrée de l'application Qt.
// Il initialise la bibliothèque de cours et démarre l'application Qt.
// Il inclut également la bibliothèque de vérification de fuites de mémoire et d'autres bibliothèques nécessaires.
//
// Remarque :
// - La versoion de Qt utilisée est la version 6.8.1 vous pouvez la changer dans les properties du projet.
// - La version de C++ utilisée est la version 20 vous pouvez la changer dans les properties du projet.
// - Le Cmake utilisé provient du projet Calculatrice disponible sur la page Moodle du cours, il etait pas tester donc il est possible qu'il ne fonctionne pas.
// - Le projet est configuré pour utiliser le compilateur MSVC 2022, vous pouvez le changer dans les properties du projet.

#include "ProjetJeuxEchecs.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ProjetJeuxEchecs w;
    w.show();
    return app.exec();
}
