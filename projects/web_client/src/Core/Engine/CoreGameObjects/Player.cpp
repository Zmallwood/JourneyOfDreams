// Copyright (c) 2024 Andreas Åkerberg.

#include "Player.h"
#include "configuration/src/GlobalProperties.h"

// Player class implementation.

namespace journey_of_dreams
{
  Player::Player() {
    // initialize player position to the center of the world area
    auto _worldAreaSize = _<GlobalProperties>().WorldAreaSize();
    m_position = {.x = _worldAreaSize.w / 2, .y = _worldAreaSize.h / 2};
  }

  int Player::GetX() {
    return m_position.x;
  }

  int Player::GetY() {
    return m_position.y;
  }

  void Player::MoveNorth() {
    m_position.y -= 1;
  }

  void Player::MoveEast() {
    m_position.x += 1;
  }

  void Player::MoveSouth() {
    m_position.y += 1;
  }

  void Player::MoveWest() {
    m_position.x -= 1;
  }

  Point Player::Position() {
    return m_position;
  }

  void Player::SetPosition(Point _position) {
    m_position = _position;
  }

  int Player::TicksLastMove() {
    return m_ticksLastMove;
  }

  void Player::SetTicksLastMove(int _ticksLastMove) {
    m_ticksLastMove = _ticksLastMove;
  }

  float Player::MovementSpeed() {
    return m_movementSpeed;
  }

  Point Player::Destination() {
    return m_destination;
  }

  void Player::SetDestination(Point _destination) {
    m_destination = _destination;
  }
} // namespace journey_of_dreams