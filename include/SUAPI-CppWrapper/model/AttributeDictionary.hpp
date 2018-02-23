//
//  AttributeDictionary.hpp
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

#ifndef AttributeDictionary_hpp
#define AttributeDictionary_hpp

#include <stdio.h>
#include <vector>
#include <string>

#include <SketchUpAPI/model/attribute_dictionary.h>

#include "SUAPI-CppWrapper/model/Entity.hpp"

namespace CW {

class TypedValue;
class String;

/*
* Entity object wrapper
*/
class AttributeDictionary :public Entity {
  /**
  * Creates a SUAttributeDictionaryRef object using the given name.
  * @param name - name of the created AttributeDictionary object.
  * @since SketchUp 2018, API v6.0
  * @return SUAttributeDictionaryRef object with the given name.
  */
  static SUAttributeDictionaryRef create_attribute_dictionary(const std::string& name);

  /**
  * Creates a SUAttributeDictionaryRef derived from an existing AttributeDictionary object.
  * @param dict - AttributeDictionary object to derive the new SUAttributeDictionaryRef from
  * @since SketchUp 2018, API v6.0
  * @return if the AttributeDictionary object is already attached to a model, its SUAttributeDictionaryRef will be returned. If the AttributeDicitonary object has not been attached to a model, a new SUAttributeDictionaryRef object will be created.  In the latter case, bear in mind that keys and values will not be copied to the new object - this would have to be done manually.
  */
  static SUAttributeDictionaryRef copy_reference(const AttributeDictionary& dict);

  public:
  /**
  * Constructor for null object.
  */
  AttributeDictionary();

  /**
  * Constructor to create a new object.
  * @param name - name of the dictionary to create.
  * @since SketchUp 2018, API v6.0
  */
  AttributeDictionary(std::string name);
  
  /**
  * Constructor from existing SUAttributeDictionaryRef object
  * @param dict - existing SUAttributeDictionaryRef object to wrap with this class.
  * @param attached - indicates whether the dictionary is attached to an entity or not.
  */
  AttributeDictionary(SUAttributeDictionaryRef dict, bool attached = true);

  /** Copy constructor */
  AttributeDictionary(const AttributeDictionary& other);
  
  /**
  * Destructor
  * @since SketchUp 2018, API v6.0
  */
  ~AttributeDictionary();

  /** Copy assignment operator */
  AttributeDictionary& operator=(const AttributeDictionary& other);

  /** Cast to native object **/
  SUAttributeDictionaryRef ref() const;
  operator SUAttributeDictionaryRef() const;
  operator SUAttributeDictionaryRef*();
  
  /**
  * Returns the value of the attribute with the specified key.
  * @param &key - the key of the attribute
  * @param &default_value - the default value to return if the attribute with the key does not exist.
  */
  TypedValue get_attribute(const std::string &key, const TypedValue &default_value) const;
  
  /**
  * Alias of AttributeDictionary::get_attribute().
  * @return TypedValue object.  If the attribute does not exist, a null TypedValue object will be returned.
  */
  TypedValue get_value(const std::string &key) const;

  /**
  * Sets the specified attribute's value.
  * @param &key - the key of the attribute to set.
  * @param &value - the value to set.
  */
  bool set_attribute(const std::string &key, const TypedValue &value);

  /**
  * Returns a vector array of keys in the Attribute Dictionary.
  */
  std::vector<std::string> get_keys() const;
  
  /**
  * Returns the name of the AttributeDictionary.
  */
  std::string get_name() const;
  
  /**
  * Returns true if this is a null object.
  */
  bool operator!() const;

};

} /* namespace CW */

#endif /* AttributeDictionary_hpp */
