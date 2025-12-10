#pragma once
#include <vector>
#include <string>

// Ç¢Ç¡ÇΩÇÒâºÇ≈çÏÇÈ
class View {
public:
    virtual ~View() = default;

    virtual void Render(const std::vector<std::string>& messageLog) = 0;

    virtual void Clear() = 0;
};