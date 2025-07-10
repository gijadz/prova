//
// Created by Giada Schicchi on 10/07/2025.
//

#pragma once
#include "SFMLProgressBar.h"

SFMLProgressBar::SFMLProgressBar(float x, float y, float width, float height)
        : m_x(x), m_y(y), m_width(width), m_height(height), m_progresso(0)
{
    m_sfBarraSfondo.setPosition(m_x, m_y);
    m_sfBarraSfondo.setSize(sf::Vector2f(m_width, m_height));
    m_sfBarraSfondo.setFillColor(sf::Color(200, 200, 200));

    m_sfBarraAvanzamento.setPosition(m_x, m_y);
    m_sfBarraAvanzamento.setSize(sf::Vector2f(0, m_height));
    m_sfBarraAvanzamento.setFillColor(sf::Color(100, 200, 100));
}

void SFMLProgressBar::aggiorna(int progressoBarra) {
    m_progresso = progressoBarra;
    float nuovaLarghezza = (m_width * m_progresso) / 100.0f;
    m_sfBarraAvanzamento.setSize(sf::Vector2f(nuovaLarghezza, m_height));
}

void SFMLProgressBar::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(m_sfBarraSfondo, states);
    target.draw(m_sfBarraAvanzamento, states);
}
float SFMLProgressBar::getLarghezzaAvanzamento() const {
    return m_sfBarraAvanzamento.getSize().x;
}