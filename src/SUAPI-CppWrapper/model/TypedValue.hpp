//
//  TypedValue.hpp
//
// Sketchup C++ Wrapper for C API
// MIT License
//
// Copyright (c) 2017 Tom Kaneko
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#ifndef TypedValue_hpp
#define TypedValue_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include <SketchUpAPI/model/typed_value.h>


namespace CW {

// Forward Declarations
class Color;
class String;
class Vector3D;

class TypedValue {
  private:
  SUTypedValueRef m_typed_value;
  /**
  * Indicates whether the TypedValue is attached to another TypedValue
  */
  bool m_attached;
  
  static SUTypedValueRef create_typed_value();
  
  public:
  TypedValue();
  TypedValue(SUTypedValueRef typed_val, bool attached = false);
  TypedValue(const char chars[]);
  //TypedValue(const std::string string);
  
  /** Copy constructor */
  TypedValue(const TypedValue& other);
  
  /** Copy Assignment Operator */
  TypedValue& operator= (const TypedValue& other);
  
  ~TypedValue();
  
  SUTypedValueRef ref() const;
  operator SUTypedValueRef();
  operator SUTypedValueRef*();
  
  /**
  * Checks whether TypedValue has been initialised.
  */
  bool operator!() const;

  
  /**
  * Checks whether TypedValue is empty.
  */
  bool empty() const;
  
  /**
  * Retrieves the type information of a typed value object.
  * @see enum SUTypedValueType for values
  */
  SUTypedValueType get_type() const;

  /**
  * Retrieves/ Set the byte value of a typed value object.
  */
  char byte_value() const;
  TypedValue& byte_value(const char byte_val);
  operator char() const;
  
  /**
   * Retrieves/Sets the int16 value of a typed value object.
  */
  int16_t int16_value() const;
  TypedValue& int16_value(const int16_t int16_val);
  operator int16_t() const;

  /**
   * Retrieves/Sets the int32 value of a typed value object.
  */
  int32_t int32_value() const;
  TypedValue& int32_value(const int32_t int32_val);
  operator int32_t() const;

  /**
  * Retrieves/Sets the float value of a typed value object.
  */
  float float_value() const;
  TypedValue& float_value(const float float_val);
  operator float() const;

  /**
  * Retrieves/Sets the double value of a typed value object.
  */
  double double_value() const;
  TypedValue& double_value(const double double_val);
  operator double() const;

  /**
  * Retrieves the boolean value of a typed value object.
  */
  bool bool_value() const;
  TypedValue& bool_value(bool bool_val);
  operator bool() const;

  /**
  * Retrieves the color value of a typed value object.
  */
  Color color_value() const;
  TypedValue& color_value(const Color &color_val);
  operator Color() const;

  /**
  * Retrieves/Sets the time value of a typed value object.  The time value is in seconds since January 1, 1970.
  */
  int64_t time_value() const;
  TypedValue& time_value(int64_t time_val);
  operator int64_t() const;

  /**
  * Retrieves/Sets the string value of a typed value object.
  */
  String string_value() const;
  TypedValue& string_value(const String &string_val);
  TypedValue& string_value(const std::string &string_val);
  operator String() const;
  operator std::string() const;

  /**
  * Retrieves/Sets the 3-element vector value of a typed value object
  */
  Vector3D vector_value() const;
  TypedValue& vector_value(const Vector3D &vector_val);
  operator Vector3D() const;

  /**
  * Retrieve/Set the array of typed value objects of a type value object.
  */
  std::vector<TypedValue> typed_value_array() const;
  TypedValue& typed_value_array(std::vector<TypedValue> &typed_val_array);
  operator std::vector<TypedValue>() const;
  
  /**
  * Comparison operator overloads
  */
  friend bool operator== (const TypedValue &val1, const TypedValue &val2);
  friend bool operator!= (const TypedValue &val1, const TypedValue &val2);

};

} /* namespace CW */
#endif /* TypedValue_hpp */
