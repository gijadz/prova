//
// Created by Giada Schicchi on 10/07/2025.
//

#ifndef PROVA_SUBJECT_H
#define PROVA_SUBJECT_H

#pragma once
#include <vector>
#include "Observer.h"

class Subject {
    std::vector<Observer*> observers;
public:
    void aggiungi(Observer* obs);
    void rimuovi(Observer* obs);
    void notificaProgresso(int progressoBarra);
    void avanzamentoBarra(int numFiles);
};

#endif //PROVA_SUBJECT_H
