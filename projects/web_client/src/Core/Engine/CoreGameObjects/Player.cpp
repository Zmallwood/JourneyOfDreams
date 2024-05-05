// Copyright (c) 2024 Andreas Åkerberg.

#include "Player.h"
#include "configuration/src/GlobalProperties.h"
//
//  Player class implementation.
//
namespace JourneyOfDreams
{
   Player::Player() {
      //initialize player position to the center of the world area
      auto worldAreaSize = _<GlobalProperties>().WorldAreaSize();
      m_position = { .x = worldAreaSize.w / 2, .y = worldAreaSize.h / 2 };
   }
   int Player::GetX() {
      //return player x position
      return m_position.x;
   }
   int Player::GetY() {
      //return player y position
      return m_position.y;
   }
   void Player::MoveNorth() {
      //move player north
      m_position.y -= 1;
   }
   void Player::MoveEast() {
      //move player east
      m_position.x += 1;
   }
   void Player::MoveSouth() {
      //move player south
      m_position.y += 1;
   }
   void Player::MoveWest() {
      //move player west
      m_position.x -= 1;
   }
   Point Player::Position() {
      //getter
      return m_position;
   }
   void Player::SetPosition(Point position) {
      //setter
      m_position = position;
   }
   int Player::TicksLastMove() {
      //getter
      return m_ticksLastMove;
   }
   void Player::SetTicksLastMove(int ticksLastMove) {
      //setter
      m_ticksLastMove = ticksLastMove;
   }
   float Player::MovementSpeed() {
      //getter
      return m_movementSpeed;
   }
   Point Player::Destination() {
      //getter
      return m_destination;
   }
   void Player::SetDestination(Point destination) {
      //setter
      m_destination = destination;
   }
} // namespace JourneyOfDreams