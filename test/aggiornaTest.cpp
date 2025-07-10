//
// Created by Giada Schicchi on 10/07/2025.
//

#include <gtest/gtest.h>
#include "../SFMLProgressBar.h"

TEST(SFMLProgressBarTest, AggiornaModificaLarghezzaBarra) {
    SFMLProgressBar bar(0, 0, 100, 20);

    //aggiorna al 50%
    bar.aggiorna(50);

    //la larghezza della barra di avanzamento dovrebbe essere 50

    EXPECT_FLOAT_EQ(bar.getLarghezzaAvanzamento(), 50.0f);
}