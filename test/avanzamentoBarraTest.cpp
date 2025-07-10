//
// Created by Giada Schicchi on 10/07/2025.
//

#include <gtest/gtest.h>
#include "SFMLProgressBar.h"

//controlla che getLarghezzaAvanzamento() restituisca 50, cioè il 50% di 100
//serve a garantire che la barra mostri l'avanzamento giusto in base al valore aggiornato
TEST(SFMLProgressBarTest, AvanzamentoCorretto) {
    SFMLProgressBar barra(0, 0, 100, 20); // posizione x, y, larghezza, altezza
    barra.aggiorna(50); // aggiorna al 50%
    EXPECT_FLOAT_EQ(barra.getLarghezzaAvanzamento(), 50.0f); // metà della larghezza
}