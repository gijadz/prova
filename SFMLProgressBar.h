//
// Created by Giada Schicchi on 10/07/2025.
//

#ifndef PROVA_SFMLPROGRESSBAR_H
#define PROVA_SFMLPROGRESSBAR_H

#pragma once
#include <SFML/Graphics.hpp>
#include "Observer.h"

class SFMLProgressBar : public Observer, public sf::Drawable {
public:
    SFMLProgressBar(float x, float y, float width, float height);

    void aggiorna(int progressoBarra) override;

    float getLarghezzaAvanzamento() const;

private:
    float m_x, m_y, m_width, m_height;
    int m_progresso;
    sf::RectangleShape m_sfBarraSfondo;
    sf::RectangleShape m_sfBarraAvanzamento;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif //PROVA_SFMLPROGRESSBAR_H
