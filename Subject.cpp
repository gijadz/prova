//
// Created by Giada Schicchi on 10/07/2025.
//

#pragma once
#include "Subject.h"
//per funzione remove in rimuovi()
#include <algorithm>
//per cronometro/timer
#include <thread>
#include <chrono>

void Subject::aggiungi(Observer* obs) {
    observers.push_back(obs);
}

void Subject::rimuovi(Observer* obs) {
    observers.erase(std::remove(observers.begin(), observers.end(), obs), observers.end());
}

void Subject::notificaProgresso(int progressoBarra) {
    for (auto obs : observers) {
        obs->aggiorna(progressoBarra);
    }
}

void Subject::avanzamentoBarra(int numFiles) {
    for (int i = 1; i <= numFiles; ++i) {
        int progresso = static_cast<int>((i * 100.0f) / numFiles);
        notificaProgresso(progresso);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}