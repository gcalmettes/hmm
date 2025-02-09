#pragma once

#include <glm/glm.hpp>
#include <string>
#include <utility>
#include <vector>

class Heightmap {
public:
    Heightmap(const std::string &path);

    Heightmap(
        const int width,
        const int height,
        const std::vector<float> &data);

    int Width() const {
        return m_Width;
    }

    int Height() const {
        return m_Height;
    }

    float At(const int x, const int y) const {
        return m_Data[y * m_Width + x];
    }

    float At(const glm::ivec2 p) const {
        return m_Data[p.y * m_Width + p.x];
    }

    std::pair<glm::ivec2, float> FindCandidate(
        const glm::ivec2 p0,
        const glm::ivec2 p1,
        const glm::ivec2 p2) const;

private:
    int m_Width;
    int m_Height;
    std::vector<float> m_Data;
};
