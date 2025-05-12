//
// Created by jaden on 5/11/2025.
//

#pragma once
#include <string>
#include <vector>

// Abstract base class from which all objects are derived. Cannot be instantiated.
class Object {
public:
  virtual ~Object() = 0;

  std::string getName() const;
  std::string getClassName() const;
  Object* getParent() const;
  std::vector<Object*> getChildren() const;

  void setName(const std::string& name);
  void setParent(Object* parent);
  void addChild(Object* child);
  void removeChild(Object* child);
private:
  std::string name = "Object";
  const std::string className = "Object";
  Object* parent = nullptr;
  std::vector<Object*> children = std::vector<Object*>();
};
