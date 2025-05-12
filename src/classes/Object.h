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

  std::string Name = "Object";
  const std::string ClassName = "Object";
  Object* Parent = nullptr;
  std::vector<Object*> Children = std::vector<Object*>();
};
