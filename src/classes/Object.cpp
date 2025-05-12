//
// Created by jaden on 5/11/2025.
//

#include "Object.h"

#include <bits/streambuf_iterator.h>

Object::~Object() = default;

std::string Object::getName() const {
    return name;
}

std::string Object::getClassName() const {
    return className;
}

Object * Object::getParent() const {
    return parent;
}

std::vector<Object *> Object::getChildren() const {
    return children;
}

void Object::setName(const std::string &name) {
    this->name = name;
}

void Object::setParent(Object *parent) {
    this->parent = parent;
}

void Object::addChild(Object *child) {
    children.push_back(child);
}

void Object::removeChild(Object *child) {
    // TODO: Implement iterators for the Object class.
    //children.erase(std::find(children.begin(), children.end(), child));
}
