//
//  Entity.hpp
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

#ifndef Entity_hpp
#define Entity_hpp

#include <stdio.h>
#include <string>
#include <vector>

#include <SketchUpAPI/model/entity.h>

namespace CW {

// Forward Declarations
class AttributeDictionary;
class TypedValue;

/*
* Entity object wrapper
*/
class Entity {
  protected:
  SUEntityRef m_entity;
  
  /**
  * Indicates whether the Entity has been attached to a model.
  */
  bool m_attached;

  public:
  /**
  * Constructor representing a null objject.
  */
	Entity();
  
  /**
  * Creates a new Entity object.
  */
  Entity(SUEntityRef entity, bool attached = true);
  
  /**
  * Copy constructor with an optional parameter for the entity reference.  SUEntityRef objects cannot be created from this class, so the Ref object must be passed to this constructor from a derived class object.
  * @param other - Entity object from which properties will be copied.
  * @param entity_ref - SUEntityRef object to assign to the copied object.
  */
  Entity(const Entity& other, SUEntityRef entity_ref = SU_INVALID);
  
  ~Entity();
  
  /** Copy assignment operator */
  Entity& operator=(const Entity& other);

  /*
  * The class object can be converted to a SUEntityRef without loss of data.
  */
  operator SUEntityRef() const;
  operator SUEntityRef*();
  
  /**
  * Returns true if this entity is not valid.
  */
  bool operator!() const;

  /**
  * Function lets the object know that it has been attached to a model.  This is important as it will let the object know that it does not need to "release" the object.
  * @param optional true to let the object know that it has been attached to the model.  False to let the object know that it has not been attached.
  */
  void attached(bool attach =  true);
  
  /*
  * The attribute_dictionaries method is used to retrieve the AttributeDictionaries collection attached to the entity.
  * @return vector of AttributeDictionary objects associated with the entity. If no AttributeDictionary objects are associated with the entity, an empty vector will be returned.
  */
  std::vector<AttributeDictionary>	attribute_dictionaries() const;
  
  /*
  * Retrieves an attribute dictionary object with a given name that is attached to an Entity.
  *
  */
  AttributeDictionary attribute_dictionary(const std::string& name) const;
  
  /*
  * Copies attributes from another Entity object to this one.
  * @param entity object to get the attributes from.
  * @param bool true to delete existing attributes, false to retain and overwrite the values. // TODO: as the C API does not currentlty allow you to delete attributes, this flag can have no effect.
  * @return true for success, false for failure.
  */
  bool copy_attributes_from(const Entity& entity /*, bool clear_existing = false*/);
  
  /*
  * The delete_attribute method is used to delete an attribute from an entity.
  * @param AttributeDictionary& object in which to find the key.
  * @param std::string with the name of the key of the attribute.
  */
  /*
  * TODO: deleting attributes is not possible with the current C API.  It could be used, however, to store a list of deleted attributes, so if this object is copied, the deleted attributes are not copied over to the new object.
  void delete_attribute(AttributeDictionary &dict, std::string key);
  */
  
  /*
  * Determines if your entity is still valid (not deleted by another script, for example.)
  */
  /*
  * TODO: as deleting an entity is not currently possible with the C API, this function cannot be used.
  bool valid();
  */
  
  /*
  * Retrieve a unique ID assigned to an entity.
  * @return int32_t key for the Entity object
  */
  int32_t entityID() const;
  
  
  /*
  * Retrieves the value of an attribute in the entity's attribute dictionary.
  * @param dict_name string name of the attribute dictionary, or AttributeDictionary object.
  * @param std::string attribute key.
  * @param default_value (optional) default TypedValue to return if no attribute is found
  * @return value TypedValue of the attribute.  If no attribute found, the default value passed is returned.
  */
  TypedValue get_attribute(const std::string& dict_name, const std::string& key) const;
  TypedValue get_attribute(const std::string& dict_name, const std::string& key, const TypedValue& default_value) const;
  
  TypedValue get_attribute(const AttributeDictionary &dict, const std::string& key) const;
  TypedValue get_attribute(const AttributeDictionary &dict, const std::string& key, const TypedValue& default_value) const;
  
  /*
  // TODO: C API does not currently allow traversing upwards
  parent()
  */
  
  /*
  * Sets the value of an attribute in the given AttributeDictionary object.
  * @param AttributeDictionary object or string name of AttributeDictionary object that the attribute is in.
  * @param std::string attribute key.
  * @param std::string value to set
  * @return true on success, false on failure
  */
  bool set_attribute(const std::string& dict_name, const std::string& key, const TypedValue& value);
  bool set_attribute(AttributeDictionary& dict, const std::string& key, const TypedValue& value);
  
  /*
  * Returns the type of the entity. See enum SURefType.
  */
  enum SURefType entity_type() const;
  
  /**
  * Returns whether these objects are the same.
  */
  //bool operator==(const Entity& entity) const;
  
  /**
  * Comparison operator for two entity objects
  */
  friend bool operator==(const Entity& lhs, const Entity& rhs);
  friend bool operator!=(const Entity& lhs, const Entity& rhs);
  
};

} /* namespace CW */

#endif /* Entity_hpp */
