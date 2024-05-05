// Copyright (c) 2024 Andreas Åkerberg.

#pragma once

// Square class declaration and implementation.

namespace journey_of_dreams
{
  /////////////////////////////////////////////////
  /// Helper class for creating a square of type T.
  /////////////////////////////////////////////////
  template <class T>
  class Square {
   public:
    /////////////////////////////////////////////////
    /// Set all values to the same value.
    ///
    /// \param _value Value to set all values to.
    /////////////////////////////////////////////////
    void SetAll(T _value);

    /////////////////////////////////////////////////
    /// Top left corner value.
    /////////////////////////////////////////////////
    T _00;

    /////////////////////////////////////////////////
    /// Bottom left corner value.
    /////////////////////////////////////////////////
    T _01;

    /////////////////////////////////////////////////
    /// Bottom right corner value.
    /////////////////////////////////////////////////
    T _11;

    /////////////////////////////////////////////////
    /// Top right corner value.
    /////////////////////////////////////////////////
    T _10;
  };

  template <class T>
  void
  Square<T>::SetAll(T _value) {
    // set all values to the same value at the same time
    _00 = _01 = _11 = _10 = _value;
  }
} // namespace journey_of_dreams