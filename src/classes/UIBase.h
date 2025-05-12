//
// Created by jaden on 5/11/2025.
//

#pragma once
#include "Object.h"

class UIBase : public Object {
public:
    ~UIBase() override = 0;

    std::string Name = "UIBase";
    const std::string ClassName = "UIBase";
    bool Hidden = false;
private:
};
